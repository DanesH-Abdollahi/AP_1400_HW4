#ifndef UNIQUE_PTR
#define UNIQUE_PTR

template <typename T>
class UniquePtr {
public:
    UniquePtr(T*&&);
    UniquePtr();
    ~UniquePtr();
    UniquePtr(const UniquePtr&);

    const T* get() const
    {
        return _p;
    }
    void reset();
    void reset(T*);
    T* release();

    const T operator*() const { return *(this->get()); }
    T* operator->() const { return _p; }

    operator bool() const { return (_p) ? true : false; }

private:
    T* _p;
};

template <typename T>
UniquePtr<T> make_unique(const T&);

#include "unique_ptr.hpp"

#endif // UNIQUE_PTR