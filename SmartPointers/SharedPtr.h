#ifndef SMARTPOINTERS_SHAREDPTR_H
#define SMARTPOINTERS_SHAREDPTR_H

#include <cstdlib>
#include <iostream>

template<typename T>
class SharedPtr {
public:
    explicit SharedPtr(T *t) : pointer(t), counter(new std::size_t(1)) {}

    SharedPtr(const SharedPtr& other) {
        if (this != &other) {
            pointer = other.pointer;
            counter = other.counter;
            (*counter)++;
        }
    }

    ~SharedPtr() {
        (*counter)--;
        if (*counter == 0) {
            std::cout << "Deleting pointer and counter..." << std::endl;
            delete pointer;
            delete counter;
        }
    }

    SharedPtr &operator=(const SharedPtr &sharedPtr) {
        SharedPtr<T> copyPtr(sharedPtr);
        copyPtr.swap(*this);
        return *this;
    }

    T& operator*() {
        return *pointer;
    }

    T* operator->() {
        return pointer;
    }

    bool operator==(const SharedPtr& other) {
        if (*pointer == *other) {
            return true;
        }
        return false;
    }

    operator bool() const {
        return (pointer != NULL);
    }

    std::size_t count() {
        return *counter;
    }

    void swap(SharedPtr & other) {
        std::swap(this->pointer, other.pointer);
        std::swap(this->counter, other.counter);
    }
private:
    T* pointer;
    std::size_t* counter;
};

#endif //SMARTPOINTERS_SHAREDPTR_H
