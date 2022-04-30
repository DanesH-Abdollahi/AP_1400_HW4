template <typename T>
UniquePtr<T>::UniquePtr(T*&& N)
    : _p { N }
{
}

template <typename T>
UniquePtr<T>::UniquePtr()
    : _p { nullptr }
{
}

template <typename T>
const T UniquePtr<T>::operator*() const
{
    return *(this->get());
}

template <typename T>
UniquePtr<T> make_unique(const T& N)
{
    return UniquePtr<T> { new T { N } };
}
