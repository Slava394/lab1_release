#pragma once
#include <stdexcept>
#include "./counter.hpp"


template<typename Type>
class WeakPtr;


template<typename Type>
class SharedPtr
{
    friend class WeakPtr<Type>;
private:
    Type* dataPtr_;
    Counter* counterPtr_;
    
    void release()
    {
        if (counterPtr_)
        {
            // std::cout << "Releasing SharedPtr. Shared count: " << counterPtr_->getSharedCount()
                //   << ", Weak count: " << counterPtr_->getWeakCount() << "\n";
            counterPtr_->decreaseSharedCount();
            if (counterPtr_->getSharedCount() == 0)
            {
                // std::cout << "Deleting managed object at address: " << dataPtr_ << "\n";
                delete dataPtr_;
                dataPtr_ = nullptr;
            }
            if (counterPtr_->getSharedCount() == 0 && counterPtr_->getWeakCount() == 0)
            {
                // std::cout << "Deleting counter at address: " << counterPtr_ << "\n";
                delete counterPtr_;
                counterPtr_ = nullptr;
            }
        }
    }
public:
    explicit SharedPtr(Type* dataPtr = nullptr)
        : dataPtr_(dataPtr),
          counterPtr_(dataPtr ? new Counter(1UL, 0UL) : nullptr) {}

    SharedPtr(const SharedPtr<Type>& sharedPtr)
        : dataPtr_(sharedPtr.dataPtr_),
          counterPtr_(sharedPtr.counterPtr_)
    {
        if (counterPtr_)
        {
            counterPtr_->increaseSharedCount();
        }
    }

    explicit SharedPtr(const WeakPtr<Type>& weakPtr);

    SharedPtr(SharedPtr<Type>&&) = delete;

    ~SharedPtr()
    {
        release();
    }

    SharedPtr<Type>& operator=(const SharedPtr<Type>& sharedPtr)
    {
        if (dataPtr_ != sharedPtr.dataPtr_)
        {
            release();
            dataPtr_ = sharedPtr.dataPtr_;
            counterPtr_ = sharedPtr.counterPtr_;
            if (counterPtr_)
            {
                counterPtr_->increaseSharedCount();
            }
        }
        return *this;
    }

    SharedPtr<Type>& operator=(const WeakPtr<Type>& weakPtr);

    SharedPtr<Type>& operator=(SharedPtr<Type>&& rvalueSharedPtr) noexcept
    {
        if (this != &rvalueSharedPtr)
        {
            release();  
            dataPtr_ = rvalueSharedPtr.dataPtr_;
            counterPtr_ = rvalueSharedPtr.counterPtr_;
            rvalueSharedPtr.dataPtr_ = nullptr;
            rvalueSharedPtr.counterPtr_ = nullptr;
        }
        return *this;
    }

    SharedPtr<Type>& operator=(std::nullptr_t)
    {
        if (this != nullptr)
        {
            release();
            dataPtr_ = nullptr;
            counterPtr_ = nullptr;
        }
        return *this;
    }

    bool operator==(const SharedPtr<Type>& sharedPtr) const
    {
        return dataPtr_ == sharedPtr.dataPtr_;
    }

    bool operator!=(const SharedPtr<Type>& sharedPtr) const
    {
        return dataPtr_ != sharedPtr.dataPtr_;
    }

    bool operator==(const WeakPtr<Type>& weakPtr);

    bool operator!=(const WeakPtr<Type>& weakPtr);

    bool operator==(std::nullptr_t) const
    {
        return dataPtr_ == nullptr;
    }

    bool operator!=(std::nullptr_t) const
    {
        return dataPtr_ != nullptr;
    }

    explicit operator bool()
    {
        return dataPtr_ != nullptr;
    }

    ul getSharedCount() const
    {
        return counterPtr_ ? counterPtr_->getSharedCount() : 0UL;
    }

    ul getWeakCount() const
    {
        return counterPtr_ ? counterPtr_->getWeakCount() : 0UL;
    }

    Type* operator->()
    {
        if (!dataPtr_) 
        {
            throw std::runtime_error("The memory isn`t allocated.");
        }
        return dataPtr_;
    }
    
    Type& operator*()
    {
        if (!dataPtr_) 
        {
            throw std::runtime_error("The memory isn`t allocated.");
        }
        return *dataPtr_;
    }

    Type* operator->() const
    {
        if (!dataPtr_) 
        {
            throw std::runtime_error("The memory isn`t allocated.");
        }
        return dataPtr_;
    }
    
    Type& operator*() const
    {
        if (!dataPtr_) 
        {
            throw std::runtime_error("The memory isn`t allocated.");
        }
        return *dataPtr_;
    }
};


template<typename Type>
class WeakPtr
{
    friend class SharedPtr<Type>;
private:
    Type* dataPtr_;
    Counter* counterPtr_;

    void release()
    {
        if (counterPtr_)
        {
            counterPtr_->decreaseWeakCount();
            if (counterPtr_->getSharedCount() == 0 && counterPtr_->getWeakCount() == 0)
            {
                delete counterPtr_;
                counterPtr_ = nullptr;
            }
        }
    }
public:
    explicit WeakPtr(std::nullptr_t) 
        : dataPtr_(nullptr),
          counterPtr_(nullptr) {}

    WeakPtr(const WeakPtr<Type>& weakPtr)
        : dataPtr_(weakPtr.dataPtr_),
          counterPtr_(weakPtr.counterPtr_)
    {
        if (counterPtr_)
        {
            counterPtr_->increaseWeakCount();
        }
    }

    explicit WeakPtr(const SharedPtr<Type>& sharedPtr)
        : dataPtr_(sharedPtr.dataPtr_),
          counterPtr_(sharedPtr.counterPtr_)
    {
        if (counterPtr_)
        {
            counterPtr_->increaseWeakCount();
        }
    }

    WeakPtr(WeakPtr<Type>&&) = delete;

    ~WeakPtr()
    {
        release();
    }

    WeakPtr<Type>& operator=(const WeakPtr<Type>& weakPtr)
    {
        if (dataPtr_ != weakPtr.dataPtr_)
        {
            release();
            dataPtr_ = weakPtr.dataPtr_;
            counterPtr_ = weakPtr.counterPtr_;
            if (counterPtr_)
            {
                counterPtr_->increaseWeakCount();
            }
        }
        return *this;
    }

    WeakPtr<Type>& operator=(const SharedPtr<Type>& sharedPtr)
    {
        if (dataPtr_ != sharedPtr.dataPtr_)
        {
            release();
            dataPtr_ = sharedPtr.dataPtr_;
            counterPtr_ = sharedPtr.counterPtr_;
            if (counterPtr_)
            {
                counterPtr_->increaseWeakCount();
            }
        }
        return *this;
    }

    WeakPtr<Type>& operator=(WeakPtr<Type>&&) = delete;

    bool operator==(const WeakPtr<Type>& weakPtr) const
    {
        return dataPtr_ == weakPtr.dataPtr_;
    }

    bool operator!=(const WeakPtr<Type>& weakPtr) const
    {
        return dataPtr_ != weakPtr.dataPtr_;
    }

    bool operator==(const SharedPtr<Type>& sharedPtr) const
    {
        return dataPtr_ == sharedPtr.dataPtr_;
    }

    bool operator!=(const SharedPtr<Type>& sharedPtr) const
    {
        return dataPtr_ != sharedPtr.dataPtr_;
    }

    bool operator==(std::nullptr_t) const
    {
        return dataPtr_ == nullptr;
    }

    bool operator!=(std::nullptr_t) const
    {
        return dataPtr_ != nullptr;
    }

    explicit operator bool()
    {
        return dataPtr_ != nullptr;
    }

    ul getSharedCount() const
    {
        return counterPtr_ ? counterPtr_->getSharedCount() : 0UL;
    }

    ul getWeakCount() const
    {
        return counterPtr_ ? counterPtr_->getWeakCount() : 0UL;
    }

    bool isExpired() const
    {
        return counterPtr_ ? counterPtr_->getSharedCount() == 0 : true;
    }

    SharedPtr<Type> lock()
    {
        if (isExpired())
        {
            return SharedPtr<Type>(); 
        }
        return SharedPtr<Type>(*this);
    }
};


template<typename Type>
SharedPtr<Type>::SharedPtr(const WeakPtr<Type>& weakPtr)
    : dataPtr_(nullptr),
      counterPtr_(nullptr)
{
    if (!weakPtr.isExpired())
    {
        dataPtr_ = weakPtr.dataPtr_;
        counterPtr_ = weakPtr.counterPtr_;
        counterPtr_->increaseSharedCount();
    }
}

template<typename Type>
SharedPtr<Type>& SharedPtr<Type>::operator=(const WeakPtr<Type>& weakPtr)   
{
    if (dataPtr_ != weakPtr.dataPtr_) 
    {
        release();
        if (weakPtr.isExpired())
        {
            dataPtr_ = nullptr;
            counterPtr_ = nullptr;
        }
        else 
        {
            dataPtr_ = weakPtr.dataPtr_;
            counterPtr_ = weakPtr.counterPtr_;
            counterPtr_->increaseSharedCount();
        }
    }
    return *this;
}

template<typename Type>
bool SharedPtr<Type>::operator==(const WeakPtr<Type>& weakPtr)
{
    return dataPtr_ == weakPtr.dataPtr_;
}

template<typename Type>
bool SharedPtr<Type>::operator!=(const WeakPtr<Type>& weakPtr)
{
    return dataPtr_ != weakPtr.dataPtr_;
}