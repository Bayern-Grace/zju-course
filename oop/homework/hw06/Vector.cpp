#include "Vector.h"
#include <iostream>
using namespace std;

template<class T>
bool Vector<T>::empty() const
{
    return this -> m_nSize;
}

template<class T>
void Vector<T>::clear()
{
    this -> m_nSize = 0;
    this -> m_pElements = nullptr;
}

template<class T>
int Vector<T>::size() const
{
    return this -> m_nSize;
}

template<class T>
void Vector<T>::inflate()
{
    if (this -> m_nCapacity == 0)
    {
        this -> m_nCapacity += 1;
        return ;
    }
    this -> m_nCapacity *= 2;
    T *temp = new T[this -> m_nCapacity];
    for (int i = 0; i < Vector::size(); i++)
        temp[i] = this -> m_pElements[i];
    delete [] this -> m_pElements;
    this -> m_pElements = temp;
}

template<class T>
void Vector<T>::push_back(const T &x)
{
    if (this -> m_nCapacity == this -> m_nSize)
        this->inflate();
    int i = Vector::size();
    this -> m_pElements[i] = x;
    this -> m_nSize++;
}

template<class T>
T& Vector<T>::at(int index)
{
    if (index < 0 || index >= m_nSize) // check the index
        throw std::out_of_range("index out of range");
    return this -> m_pElements[index];
}