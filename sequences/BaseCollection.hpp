#pragma once


//P.S. for copy constructor DynamicArray <-> LinkedList
template <class T>
class BaseCollection
{
public:
    //---Virtual destructor---
    virtual ~BaseCollection() = default;
    //---Getters---
    virtual T &Get(int index) const = 0;
    [[nodiscard]] virtual int GetSize() const = 0;
};
