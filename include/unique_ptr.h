#ifndef UNIQUE_PTR
#define UNIQUE_PTR

template <typename T>
class UniquePtr {
public:
    UniquePtr(T*&&);
    UniquePtr();

    const T* get() const { return _p; }

    const T operator*() const;
    T* operator->() const { return _p; }

private:
    T* _p;
};

template <typename T>
UniquePtr<T> make_unique(const T&);

#include "unique_ptr.hpp"

#endif // UNIQUE_PTR