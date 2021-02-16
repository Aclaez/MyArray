#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

using namespace std;

template<typename T>
class Array
{
private:
    T* p;
    int size;
public:
    class My_iterator;

    Array(int size)
    {
        this->p = new T(size);
        this->size = size;
    }

    Array(const Array& other)
    {
        p = new int(other.size);
        for(int i = 0; i < size; i++)
        {
            p[i] = other.p[i];
        }
    }

    ~Array()
    {
        delete[] p;
    }

    Array<T>& operator =(Array<T>&& other) noexcept
    {
        if (&other == this)
            return *this;

        p = other.p;
        other.p = nullptr;
        return *this;
    }

    T& operator [](size_t pos)
    {

        if(pos > size && pos < 0)
        {
            cout << "out of range!" << endl;
            T zero = 0;
            return zero;
        }
        else
        {
            return p[pos];
        }
    }

    void show()
    {
        cout << "The Array:\n";
        for (int i = 0; i < size; i++)
          cout << "p[" << i << "] = " << p[i] << endl;
        cout << "------------------------------" << endl;
    }

    My_iterator begin()
    {
        My_iterator tmp(this->p);
        return tmp;
    }

    My_iterator end()
    {
        My_iterator tmp(this->p+size);
        return tmp;
    }

    void insert(My_iterator& pos, T value)
    {
        int new_size = size + 1;
        int i = 0;
        Array<T> new_arr(new_size);
        auto it = My_iterator(this->begin());
        while(it != this->end())
        {
            if(it == pos)
            {
                new_arr[i] = value;
                it++;
                i++;
                continue;
            }
            new_arr[i] = *it;
            i++;
            it++;
        }
        this->p = new T(new_size);
        for(int i = 0; i < new_size; i++)
        {
            p[i] = new_arr.p[i];
        }
        size++;
    }

    void FormArrayRandom();

    class My_iterator
    {
        T* ptr;
    public:
        My_iterator(T* adress):ptr(adress)
        {}

        My_iterator(const My_iterator& it):ptr(it.ptr)
        {}

        bool operator ==(const My_iterator& other)
        {
           return this->ptr == other.ptr;
        }

        bool operator !=(const My_iterator& other)
        {
           return !(*this == other);
        }

        My_iterator& operator ++(int)
        {
            My_iterator tmp(ptr++);
            return tmp;
        }

        My_iterator& operator ++()
        {
            My_iterator tmp(++ptr);
            return tmp;
        }

        My_iterator& operator +(int n)
        {
            My_iterator tmp(ptr + n);
            return tmp;
        }

        My_iterator& operator -(int n)
        {
            My_iterator tmp(ptr - n);
            return tmp;
        }

        T& operator* ()
        {
            return *ptr;
        }

    };
};

#endif // ARRAY_H
