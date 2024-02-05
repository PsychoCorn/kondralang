#ifndef Array_HPP
#define Array_HPP

#include <iostream>
#include <vector>

namespace kondra
{
    template <class T>
    class Array : public std::vector<T>
    {
    public:
        using std::vector<T>::vector;
        T& operator[](int);
        const T& operator[](int) const;
        Array operator+(const Array&) const;
        Array &operator+=(const Array&);
        Array operator*(const size_t&) const;
        Array &operator*=(const size_t&);
    };

    template <class T>
    T& Array<T>::operator[](int index) {
        if (index < 0) {
            index += this->size();
        }
        return std::vector<T>::operator[](index);
    }

    template <class T>
    const T& Array<T>::operator[](int index) const {
        if (index < 0) {
            index += this->size();
        }
        return std::vector<T>::operator[](index);
    }

    template <class T>
    Array<T> Array<T>::operator+(const Array<T> &other) const
    {
        Array<T> result = *this;
        result.insert(result.end(), other.begin(), other.end());
        return result;
    }

    template <class T>
    Array<T> &Array<T>::operator+=(const Array<T> &other)
    {
        *this = *this + other;
        return *this;
    }
    
    template <class T>
    Array<T> Array<T>::operator*(const size_t &times) const
    {
        Array<T> result;
        auto originalSize = this->size();
        result.reserve(this->size() * times);
        for (size_t i = 0; i < times; i++)
        {
            result.insert(result.end(), this->begin(), this->end());
        }
        return result;
    }

    template <class T>
    Array<T> &Array<T>::operator*=(const size_t& times)
    {
        *this = *this * times;
        return *this;
    }

    template <class T>
    std::ostream &operator<<(std::ostream &os, const Array<T> &arr)
    {
        os << "[";
        auto iter = arr.begin();
        if (iter == arr.end()) 
        {
            os << "]";
            return os;
        }
        for (; iter != arr.end() - 1; iter++) 
        {
            os << *iter << ", ";
        }
        os << *iter << "]";
        return os;
    }

    template <class T>
    using array = Array<T>;

}

#endif