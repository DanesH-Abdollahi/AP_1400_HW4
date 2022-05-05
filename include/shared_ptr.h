#ifndef SHARED_PTR
#define SHARED_PTR
#include <iostream>

template <typename T>
class SharedPtr {
public:
    SharedPtr(T*); // Constructor
    SharedPtr(); // Default Constructor
    ~SharedPtr(); // Destructor
    SharedPtr(SharedPtr&); // Copy Constructor

    const T* get() const { return _p; }
    const size_t use_count() const { return (counter) ? *counter : 0; }
    void reset();
    void reset(T*);

    const T operator*() const { return *(_p); }
    T* operator->() const { return _p; }
    SharedPtr& operator=(const SharedPtr&);

    operator bool() const { return (_p) ? true : false; } // Cast SharedPtr to bool

private:
    T* _p;
    int* counter;
};

template <typename T>
SharedPtr<T> make_shared(const T&);

#include "shared_ptr.hpp"

#endif // SHARED_PTR