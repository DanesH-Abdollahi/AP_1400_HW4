template <typename T>
UniquePtr<T>::UniquePtr(T* ptr)
    : _p { ptr }
{
}
//----------------------------------------------------------------------------------
template <typename T>
UniquePtr<T>::UniquePtr()
    : _p { nullptr }
{
}
//----------------------------------------------------------------------------------
template <typename T>
UniquePtr<T>::UniquePtr(const UniquePtr<T>& ptr)
    : _p { ptr._p }
{
}
//----------------------------------------------------------------------------------
template <typename T>
UniquePtr<T>::~UniquePtr()
{
    delete _p;
    _p = nullptr;
}
//----------------------------------------------------------------------------------
template <typename T>
UniquePtr<T>& UniquePtr<T>::operator=(const UniquePtr<T>& ptr)
{
    if (this == &ptr)
        return *this;

    delete _p;
    _p = ptr._p;
    return *this;
}
//----------------------------------------------------------------------------------
template <typename T>
void UniquePtr<T>::reset()
{
    delete _p;
    _p = nullptr;
}
//----------------------------------------------------------------------------------
template <typename T>
void UniquePtr<T>::reset(T* ptr)
{
    delete _p;
    _p = ptr;
}
//----------------------------------------------------------------------------------
template <typename T>
T* UniquePtr<T>::release()
{
    T* tmp { _p };
    _p = nullptr;
    return tmp;
}
//----------------------------------------------------------------------------------
template <typename T>
UniquePtr<T> make_unique(const T& N)
{
    return UniquePtr<T> { new T { N } };
}
//----------------------------------------------------------------------------------