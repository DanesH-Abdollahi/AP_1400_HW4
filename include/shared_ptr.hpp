template <typename T>
SharedPtr<T>::SharedPtr(T* ptr) // Constructor
    : _p { ptr }
    , counter { new int { 1 } }
{
}
//----------------------------------------------------------------------------------
template <typename T>
SharedPtr<T>::SharedPtr() // Default Constructor
    : _p { nullptr }
    , counter { new int { 0 } }
{
}
//----------------------------------------------------------------------------------
template <typename T>
SharedPtr<T>::SharedPtr(SharedPtr<T>& ptr) // Copy Constructor
    : _p { ptr._p }
    , counter { &(++(*ptr.counter)) }

{
}
//----------------------------------------------------------------------------------
template <typename T>
SharedPtr<T>::~SharedPtr() // Destructor
{
    if (counter) { // if the counter is not nullptr
        if (--(*counter) == 0) { // if the counter value is 1
            delete _p;
            _p = nullptr;
            delete counter;
            counter = nullptr;
        }
        _p = nullptr;
    }
}
//----------------------------------------------------------------------------------
template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& ptr)
{
    if (this == &ptr) // If The Input is Same as The Object
        return *this;

    delete _p;
    delete counter;
    _p = ptr._p;
    counter = ptr.counter;
    *counter += 1;
    return *this;
}
//----------------------------------------------------------------------------------
template <typename T>
void SharedPtr<T>::reset() // Reset Function
{
    delete _p;
    _p = nullptr;
    delete counter;
    counter = nullptr;
}
//----------------------------------------------------------------------------------
template <typename T>
void SharedPtr<T>::reset(T* ptr) // Reset Function with input
{
    delete _p;
    _p = ptr;
    delete counter;
    counter = new int { 1 };
}
//----------------------------------------------------------------------------------
template <typename T>
SharedPtr<T> make_shared(const T& N)
{
    return SharedPtr<T> { new T { N } }; // Return R-Value SharedPtr Object ( Using RVO )
}
//------------------------------- The End ------------------------------------------