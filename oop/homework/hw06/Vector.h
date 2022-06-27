#include <iostream>
#include <vector>
using namespace std;
template <class T>
class Vector
{
public:
    Vector() : m_nSize(0), m_nCapacity(0), m_pElements(nullptr) {} // creates an empty vector
    Vector(int size) : m_nSize(0), m_nCapacity(size), m_pElements(new T(size * sizeof(T))) {} // creates a vector for holding 'size' elements
    Vector(const Vector &r) {m_pElements = r.m_pElements; m_nSize = r.m_nSize; m_nCapacity = r.m_nCapacity;}
    // the copy ctor
    ~Vector() {}                  // destructs the vector
    T &operator[](int index)    // accesses the specified element without bounds checking
    {
        return this -> m_pElements[index]; //no check of whether index is out of range
    }
    T &at(int index);           // accesses the specified element, throws an exception of
                                // type 'std::out_of_range' when index <0 or >=m_nSize
    int size() const;           // return the size of the container
    void push_back(const T &x); // adds an element to the end
    void clear();               // clears the contents
    bool empty() const;         // checks whether the container is empty
private:
    void inflate();  // expand the storage of the container to a new capacity,
                     // e.g. 2*m_nCapacity
    T *m_pElements;  // pointer to the dynamically allocated storage
    int m_nSize;     // the number of elements in the container
    int m_nCapacity; // the number of elements that can be held in currently
                     // allocated storage
};

template<class T>
bool Vector<T>::empty() const
{
    return this -> m_nSize; //return the size of Vector, transfrom it to bool type implicitly
}

template<class T>
void Vector<T>::clear()
{
    this -> m_nSize = 0;
    delete [] this -> m_pElements; //free the allocated space
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
        this -> m_pElements = new T[this -> m_nCapacity]; //allocate space
        return ;
    }
    this -> m_nCapacity *= 2; //expand the storage of the container to 2 * capacity
    T *temp = new T[this -> m_nCapacity]; //allocate space
    for (int i = 0; i < Vector::size(); i++)
        temp[i] = this -> m_pElements[i]; //copy old elements to new allcated space
    delete [] this -> m_pElements; //free allocated space
    this -> m_pElements = temp;
}

template<class T>
void Vector<T>::push_back(const T &x)
{
    if (this -> m_nCapacity == this -> m_nSize) //Vector is full
        this->inflate(); //expand its storage
    int i = Vector::size();
    this -> m_pElements[i] = x;
    this -> m_nSize++;
}

template<class T>
T& Vector<T>::at(int index)
{
    if (index < 0 || index >= m_nSize) // check the index
        throw std::out_of_range("index out of range"); //throw the exception
    return this -> m_pElements[index];
}