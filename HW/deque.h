#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <vector>
#include <exception>

template <class T>
class Deque
{
public:
    Deque()
    {
    }

    bool Empty() const
    {
        return deq.empty();
    }

    size_t Size() const
    {
        return deq.size();
    }

    T & operator[](size_t index)
    {
        if (index < this->Size())
            return deq[index];
        else
            this->At(index);
    }

    const T & operator[](size_t index) const
    {
        if (index < this->Size())
            return deq[index];
        else
            this->At(index);
    }

    void At(size_t index)
    {
        if(index >= deq.size())
            throw std::out_of_range("error");
    }

    const void At(size_t index) const
    {
        if(index >= deq.size())
            throw std::out_of_range("error");
    }

    T &Front()
    {
        return deq.front();
    }

    const T &Front() const
    {
        return deq.front();
    }

    T &Back()
    {
        return deq.back();
    }

    const T &Back() const
    {
        return deq.back();
    }

    void PushFront(T const &val)
    {
        deq.insert(deq.begin(), val);
    }

    void PushBack(T const &val)
    {
        deq.push_back(val);
    }

private:
    std::vector<T> deq;
};

#endif // DEQUE_H
