//
// Created by arthur on 28/11/2025.
//
#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class DynamicArray {
private:
    T* _data;
    size_t _size;
    size_t _capacity;

    void resize(const size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (int i = 0; i < _size; i++) {
            new_data[i] = _data[i];
        }
        delete[] _data;
        _data = new_data;
        _capacity = new_capacity;
    }

    public:
    DynamicArray() : _data(nullptr), _size(0), _capacity(1) {
        _data = new T[_capacity];
    };

    DynamicArray(const DynamicArray& other) : _data(nullptr), _size(other._size), _capacity(other._capacity) {
        _data = new T[_capacity];
        for (int i = 0; i < other._size; i++) {
            _data[i] = other._data[i];
        }
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) {
            return *this;
        }

        T* tmp = new T[_capacity];
        for (int i = 0; i < other._size; i++) {
            tmp[i] = other._data[i];
        }
        delete[] _data;
        _data = tmp;
        _size = other._size;
        _capacity = other._capacity;

        return *this;
    }

    ~DynamicArray() {
        delete[] _data;
    };

    void push_back(const T& item) {
        if (_size == _capacity) {
            resize(_capacity * 2);
        }
        _data[_size] = item;
        _size++;
    }

    void pop_back() {
        if (_size == 0) {
            return;
        }
        _size--;
        _data[_size].~T();
    }

    T& operator[](const size_t index) {
        if (index >= _size) {
            throw std::out_of_range("index out of range");
        }
        return _data[index];
    }

    const T& operator[](const size_t index) const {
        if (index >= _size) {
            throw std::out_of_range("index out of range");
        }
        return _data[index];
    }

    [[nodiscard]] size_t size() const {
        return _size;
    }

    [[nodiscard]] size_t capacity() const {
        return _capacity;
    }

    void print() const {
        std::cout << '[';
        for (size_t i = 0; i < _size; i++) {
            std::cout << _data[i];
            if (i < _size - 1) {
                std::cout << ", ";
            }
        }
        std::cout << ']' << std::endl;
    }
};