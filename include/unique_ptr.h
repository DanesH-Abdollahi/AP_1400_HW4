#ifndef UNIQUE_PTR
#define UNIQUE_PTR

template <typename T>
class UniquePtr {
public:
    UniquePtr(T*); // Constructor
    UniquePtr(); // Default Constructor
    ~UniquePtr(); // Destructor
    UniquePtr(const UniquePtr&) = delete; // Copy Constructor

    const T* get() const { return _p; }
    void reset();
    void reset(T*);
    T* release();

    const T& operator*() const { return *(_p); }
    T* operator->() const { return _p; }
    UniquePtr& operator=(const UniquePtr&) = delete;

    operator bool() const { return (_p) ? true : false; } // Cast UniquePtr to bool

private:
    T* _p;
};

template <typename T>
UniquePtr<T> make_unique(const T&);

#include "unique_ptr.hpp"

#endif // UNIQUE_PTR