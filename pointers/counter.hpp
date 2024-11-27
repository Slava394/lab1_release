#pragma once
#include <iostream>


using ul = unsigned long;


class Counter 
{
private:
    ul sharedQuantity_;
    ul weakQuantity_;
public:
    Counter(ul sharedQuantity, ul weakQuantity)
        : sharedQuantity_(sharedQuantity),
          weakQuantity_(weakQuantity) {}

    ul getSharedCount()
    {
        return sharedQuantity_;
    }

    ul getWeakCount()
    {
        return weakQuantity_;
    }

    void increaseSharedCount()
    {
        ++sharedQuantity_;
    }

    void increaseWeakCount()
    {
        ++weakQuantity_;
    }

    void decreaseSharedCount()
    {
        if (sharedQuantity_ == 0UL)
        {
            throw std::logic_error("Shared quantity can`t be less then zero.");
        }
        else
        {
            --sharedQuantity_;
        }
    }

    void decreaseWeakCount()
    {
        if (weakQuantity_ == 0UL)
        {
            throw std::logic_error("Weak quantity can`t be less then zero.");
        }
        else
        {
            --weakQuantity_;
        }
    }
};