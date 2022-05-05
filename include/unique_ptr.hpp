template <typename T>
UniquePtr<T>::UniquePtr(T* ptr) // Constructor
    : _p { ptr }
{
}
//----------------------------------------------------------------------------------
template <typename T>
UniquePtr<T>::UniquePtr() // Default Constructor
    : _p { nullptr }
{
}
//----------------------------------------------------------------------------------
template <typename T>
UniquePtr<T>::~UniquePtr() // Destructor
{
    delete _p;
    _p = nullptr;
}
//----------------------------------------------------------------------------------
template <typename T>
void UniquePtr<T>::reset() // Reset Function
{
    delete _p;
    _p = nullptr;
}
//----------------------------------------------------------------------------------
template <typename T>
void UniquePtr<T>::reset(T* ptr) // Reset Function with input
{
    delete _p;
    _p = ptr;
}
//----------------------------------------------------------------------------------
template <typename T>
T* UniquePtr<T>::release() // Release Function
{
    T* tmp { _p };
    _p = nullptr;
    return tmp;
}
//----------------------------------------------------------------------------------
template <typename T>
UniquePtr<T> make_unique(const T& N) // Make Unique Function
{
    return UniquePtr<T> { new T { N } }; // Return R-Value UniquePtr Object ( Using RVO )
}
//------------------------------- The End ------------------------------------------