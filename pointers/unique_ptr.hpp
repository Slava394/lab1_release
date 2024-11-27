#pragma once
#include <stdexcept>


template<typename Type>
class UniquePtr
{
private:
    Type* dataPtr_;

    void release()
    {
        delete dataPtr_;
        dataPtr_ = nullptr;
    }
public:
    explicit UniquePtr(Type* dataPtr = nullptr)
        : dataPtr_(dataPtr) {}

    UniquePtr(const UniquePtr<Type>&) = delete;

    UniquePtr(UniquePtr<Type>&& uniquePtr) noexcept
    {
        dataPtr_ = uniquePtr.dataPtr_;
        uniquePtr.dataPtr_ = nullptr;
    }

    ~UniquePtr()
    {
        release();
    }

    UniquePtr<Type>& operator=(const UniquePtr<Type>&) = delete;

    UniquePtr<Type>& operator=(UniquePtr<Type>&& uniquePtr) noexcept
    {
        if (dataPtr_ != uniquePtr.dataPtr_)
        {
            release();
            dataPtr_ = uniquePtr.dataPtr_;
            uniquePtr.dataPtr_ = nullptr;
        }
        return *this;
    }

    bool operator==(const UniquePtr<Type>& uniquePtr) const
    {
        return dataPtr_ == uniquePtr.dataPtr_;
    }

    bool operator!=(const UniquePtr<Type>& uniquePtr) const
    {
        return dataPtr_ != uniquePtr.dataPtr_;
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

    Type* getOwnership() 
    {
        Type* dataPtr = dataPtr_;
        dataPtr_ = nullptr;
        return dataPtr;
    }

    void reset(Type* dataPtr = nullptr) 
    {
        delete dataPtr_;
        dataPtr_ = dataPtr;
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
};