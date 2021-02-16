#include "array.h"

//template <typename T>
//const T& Array<T>::operator [](size_t pos) const
//{
//    if(pos > size)
//    {
//        cout << "out of range!" << endl;
//        return 0;
//    }
//    else
//    {
//        return p[pos];
//    }
//}

//template <typename T>
//Array<T>& Array<T>::operator+(const Array<T>& A)
//{
//    if(size != A.size)
//    {
//        Array newArr(0);
//        return newArr;
//    }
//    else
//    {
//        Array newArr(size);

//        for (int i = 0; i < size; i++)
//        {
//            newArr[i] = p[i] + A[i];
//        }
//        return newArr;
//    }
//}

//template <typename T>
//void Array<T>::FormArrayRandom()
//{
//    srand(time(NULL));
//    for (int i = 0; i < size; i++)
//        p[i] = rand() % 10;
//}
