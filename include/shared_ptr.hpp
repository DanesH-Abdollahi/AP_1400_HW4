template <typename T>
SharedPtr<T>::SharedPtr(T*&& ptr)
    : _p { ptr }
    , counter { new int { 1 } }
{
}
//----------------------------------------------------------------------------------
template <typename T>
SharedPtr<T>::SharedPtr()
    : _p { nullptr }
    , counter { new int { 1 } }
{
}
//----------------------------------------------------------------------------------
template <typename T>
SharedPtr<T>::SharedPtr(SharedPtr<T>& ptr)
    : _p { ptr._p }
    , counter { &(++(*ptr.counter)) }

{
}
//----------------------------------------------------------------------------------
template <typename T>
SharedPtr<T>::~SharedPtr()
{
    if (counter) {
        if (--(*counter) == 0) {
            delete _p;
            _p = nullptr;
            delete counter;
            counter = nullptr;
        }
    }
}
//----------------------------------------------------------------------------------
template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& ptr)
{
    if (this == &ptr)
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
void SharedPtr<T>::reset()
{
    delete _p; // ??
    _p = nullptr;
    delete counter;
    counter = nullptr;
}
//----------------------------------------------------------------------------------
template <typename T>
void SharedPtr<T>::reset(T* ptr)
{
    delete _p; // ??
    _p = ptr;
    delete counter;
    counter = new int { 1 };
}
//----------------------------------------------------------------------------------
template <typename T>
SharedPtr<T> make_shared(const T& N)
{
    return SharedPtr<T> { new T { N } };
}
//----------------------------------------------------------------------------------