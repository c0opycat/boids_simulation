//
// Created by arthur on 28/11/2025.
//
#pragma once
#include <iostream>
#include <stdexcept>

/**
 * @brief A dynamic array implementation similar to std::vector.
 *
 * This class provides a resizable array that can store elements of any type `T`.
 * It handles memory management automatically, expanding its capacity as needed.
 *
 * @tparam T The type of elements stored in the array.
 */
template <typename T>
class DynamicArray {
    T* _data; /**< Pointer to the underlying array storing elements. */
    size_t _size; /**< The number of elements currently in the array. */
    size_t _capacity; /**< The total number of elements the array can hold without reallocating. */

    /**
     * @brief Resizes array to a new capacity.
     * @param new_capacity The new capacity for the array.
     */
    void resize(const size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < _size; i++) {
            new_data[i] = _data[i];
        }
        delete[] _data;
        _data = new_data;
        _capacity = new_capacity;
    }

public:
    /**
     * @brief Constructs an empty DynamicArray with a default initial capacity of 1.
     */
    DynamicArray() : _data(nullptr), _size(0), _capacity(1) {
        _data = new T[_capacity];
    };

    /**
     * @brief Copy constructor. Creates a new DynamicArray by copying elements from another.
     * @param other The DynamicArray to copy from.
     */
    DynamicArray(const DynamicArray& other) : _data(nullptr), _size(other._size), _capacity(other._capacity) {
        _data = new T[_capacity];
        for (size_t i = 0; i < other._size; i++) {
            _data[i] = other._data[i];
        }
    }

    /**
     * @brief Copy assignment operator. Assigns the contents of another DynamicArray to this one.
     * @param other The DynamicArray to assign from.
     * @return A reference to this DynamicArray after assignment.
     */
    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) {
            return *this;
        }

        delete[] _data;
        _size = other._size;
        _capacity = other._capacity;
        _data = new T[_capacity];
        for (size_t i = 0; i < _size; i++) {
            _data[i] = other._data[i];
        }

        return *this;
    }

    /**
     * @brief Destructor. Frees the memory allocated for the internal array.
     */
    ~DynamicArray() {
        delete[] _data;
    };

    /**
     * @brief Adds an element to the end of the array.
     * If the array's capacity is reached, it will be resized (doubled).
     * @param item The item to add.
     */
    void push_back(const T& item) {
        if (_size == _capacity) {
            resize(_capacity * 2);
        }
        _data[_size] = item;
        _size++;
    }

    /**
     * @brief Removes the last element from the array.
     * Does nothing if the array is empty.
     */
    void pop_back() {
        if (_size == 0) {
            return;
        }
        _size--;
        _data[_size].~T(); // Call destructor for the removed element
    }

    /**
     * @brief Accesses the element at the specified index (non-const version).
     * @param index The index of the element to access.
     * @return A reference to the element at the given index.
     * @throws std::out_of_range if the index is out of bounds.
     */
    T& operator[](const size_t index) {
        if (index >= _size) {
            throw std::out_of_range("index out of range");
        }
        return _data[index];
    }

    /**
     * @brief Accesses the element at the specified index (const version).
     * @param index The index of the element to access.
     * @return A const reference to the element at the given index.
     * @throws std::out_of_range if the index is out of bounds.
     */
    const T& operator[](const size_t index) const {
        if (index >= _size) {
            throw std::out_of_range("index out of range");
        }
        return _data[index];
    }

    /**
     * @brief Returns the number of elements currently in the array.
     * @return The current size of the array.
     */
    [[nodiscard]] size_t size() const {
        return _size;
    }

    /**
     * @brief Returns the total capacity of the array.
     * @return The current capacity of the array.
     */
    [[nodiscard]] size_t capacity() const {
        return _capacity;
    }

    /**
     * @brief Prints the elements of the array to the standard output.
     * Elements are printed within square brackets, separated by commas.
     */
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