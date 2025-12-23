/**
 * @file Vec2.hpp
 * @brief Contains the declaration of the Vec2 template class.
 */

#pragma once

#include "../utils/Utils.hpp"
#include <iostream>
#include <cmath> // For std::hypot

template <typename T>
class Vec2;

/**
 * @brief Overload of the << operator to print a Vec2 to an output stream.
 * @tparam T The type of the vector's components.
 * @param os The output stream.
 * @param vec The vector to print.
 * @return The output stream.
 */
template <typename T>
std::ostream& operator<<(std::ostream& os, const Vec2<T>& vec);

/**
 * @class Vec2
 * @brief A 2D vector class.
 * @tparam T The type of the vector's components.
 *
 * This class represents a 2D vector with components x and y.
 */
template <typename T>
class Vec2 {
    T _x; ///< The x component of the vector.
    T _y; ///< The y component of the vector.

public:
    /**
     * @brief Constructs a new Vec2 object.
     * @param x The x component.
     * @param y The y component.
     */
    Vec2(const T x, const T y) : _x(x), _y(y) {}

    /** @name Getters */
    ///@{
    /**
    * @brief Gets the x component of the vector.
    * @return The x component.
     */
    const T getX() const {
        return _x;
    }

    /**
    * @brief Gets the y component of the vector.
    * @return The y component.
     */
    const T getY() const {
        return _y;
    }
    ///@}

    /** @name Setters */
    ///@{
    /**
    * @brief Sets the x component of the vector.
    * @param x The new x component.
    */
    void setX(const T x) {
        _x = x;
    }

    /**
    * @brief Sets the y component of the vector.
    * @param y The new y component.
    */
    void setY(const T y) {
        _y = y;
    }
    ///@}

    /**
     * @brief Adds two vectors.
     * @param other The vector to add.
     * @return The resulting vector.
     */
    Vec2 operator+(const Vec2& other) const {
        return Vec2(_x + other._x, _y + other._y);
    }

    /**
     * @brief Subtracts two vectors.
     * @param other The vector to subtract.
     * @return The resulting vector.
     */
    Vec2 operator-(const Vec2& other) const {
        return Vec2(_x - other._x, _y - other._y);
    }

    /**
     * @brief Multiplies two vectors.
     * @param other The vector to multiply by.
     * @return The resulting vector.
     */
    Vec2 operator*(const Vec2& other) const {
        return Vec2(_x * other._x, _y * other._y);
    }

    /**
     * @brief Divides two vectors.
     * @param other The vector to divide by.
     * @return The resulting vector.
     */
    Vec2 operator/(const Vec2& other) const {
        try {
            Utils::check_denominator(other._x);
            Utils::check_denominator(other._y);
            return Vec2(_x / other._x, _y / other._y);
        } catch (std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
            return *this;
        }
    }

    /**
     * @brief Multiplies the vector by a scalar.
     * @param val The scalar value.
     * @return The resulting vector.
     */
    Vec2 operator*(const T val) const {
        return Vec2(_x * val, _y * val);
    }

    /**
     * @brief Divides the vector by a scalar.
     * @param val The scalar value.
     * @return The resulting vector.
     */
    Vec2 operator/(const T val) const {
        try {
            Utils::check_denominator(val);
            return Vec2(_x / val, _y / val);
        } catch (std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
            return *this;
        }
    }

    /**
     * @brief Adds another vector to this one.
     * @param other The vector to add.
     * @return A reference to this vector.
     */
    Vec2 operator+=(const Vec2& other) {
        _x += other._x;
        _y += other._y;
        return *this;
    }

    /**
     * @brief Subtracts another vector from this one.
     * @param other The vector to subtract.
     * @return A reference to this vector.
     */
    Vec2 operator-=(const Vec2& other) {
        _x -= other._x;
        _y -= other._y;
        return *this;
    }

    /**
     * @brief Multiplies this vector by another one.
     * @param other The vector to multiply by.
     * @return A reference to this vector.
     */
    Vec2 operator*=(const Vec2& other) {
        _x *= other._x;
        _y *= other._y;
        return *this;
    }

    /**
     * @brief Divides this vector by another one.
     * @param other The vector to divide by.
     * @return A reference to this vector.
     */
    Vec2 operator/=(const Vec2& other) {
        try {
            Utils::check_denominator(other._x);
            Utils::check_denominator(other._y);
            _x /= other._x;
            _y /= other._y;
        } catch (std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
        }
        return *this;
    }

    /**
     * @brief Multiplies this vector by a scalar.
     * @param val The scalar value.
     * @return A reference to this vector.
     */
    Vec2 operator*=(const T val) {
        _x *= val;
        _y *= val;
        return *this;
    }

    /**
     * @brief Divides this vector by a scalar.
     * @param val The scalar value.
     * @return A reference to this vector.
     */
    Vec2 operator/=(const T val) {
        try {
            Utils::check_denominator(val);
            _x /= val;
            _y /= val;
        } catch (std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
        }
        return *this;
    }

    /**
     * @brief Checks if two vectors are equal.
     * @param other The other vector.
     * @return True if the vectors are equal, false otherwise.
     */
    bool operator==(const Vec2& other) const {
        return _x == other._x && _y == other._y;
    }

    /**
     * @brief Checks if two vectors are not equal.
     * @param other The other vector.
     * @return True if the vectors are not equal, false otherwise.
     */
    bool operator!=(const Vec2& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<< <>(std::ostream& os, const Vec2<T>& vec);

    /**
     * @brief Calculates the length of the vector.
     * @return The length of the vector.
     */
    T length() const {
        return std::hypot(_x, _y);
    }

    /**
     * @brief Normalizes the vector.
     * @return A new vector with the same direction but a length of 1.
     */
    Vec2 normalize() const {
        Vec2 res(_x, _y);
        T length = res.length();
        if (length != 0) {
            return res / length;
        }
        return res;
    }

    /**
     * @brief Normalizes the vector to a maximum length.
     * @param max The maximum length.
     * @return A new vector with the same direction but a length no greater than max.
     */
    Vec2 normalize_max(const T max) {
        Vec2 res(_x, _y);
        T length = res.length();
        if (length != 0 && length > max) {
            return res / length * max;
        }
        return res;
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vec2<T> & vec) {
    os << "(" << vec._x << ", " << vec._y << ")";
    return os;
}
