//
// Created by dennis on 12/09/16.
//

#ifndef MYVECTOR_VECTOR_H
#define MYVECTOR_VECTOR_H

#include <exception>

namespace my {
    template<typename T>
    class Vector {
    public:
        explicit Vector(int capacity = 10) : capacity_(capacity), latest_(0), data_(new T[capacity]) {}

        Vector(const Vector &other) {}

        Vector &operator=(const Vector &other) {
            return *this;
        }

        ~Vector() {
            delete[] data_;
        }

        int size() const {
            return capacity_;
        }

        T &back() {
            return *data_;
        }

        void push_back(const T &t) {
            if (latest_ < capacity_) {
                data_[latest_] = t;
                latest_++;
            }
        }

        void pop_back() {}

        void insert(const T &t, int n) {}

        T *begin() {
            return data_;
        }

        T *end() {
            return data_+capacity_;
        }

        T &operator[](int i) {
            return *(data_[i]);
        }

    private:
        int capacity_;
        int latest_;
        T *data_; // Contains the actual elements - data on the heap
    };
}

#endif //MYVECTOR_VECTOR_H
