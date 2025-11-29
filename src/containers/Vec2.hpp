//
// Created by lcooper on 28/11/2025.
//

#pragma once



#include "../Utils.hpp"

#include <iostream>

#include <ostream>

#include <cmath> // For std::hypot



template <typename T>

class Vec2; // Forward declaration



template <typename T>

std::ostream& operator<<(std::ostream& os, const Vec2<T>& vec); // Forward declaration



template <typename T>

class Vec2 {

    T _x;

    T _y;



public:

    Vec2(const T x, const T y) : _x(x), _y(y) {}



    const T getX() const {

        return _x;

    }



    const T getY() const {

        return _y;

    }



    void setX(const T x) {

        _x = x;

    }



    void setY(const T y) {

        _y = y;

    }



    Vec2 operator+(const Vec2& other) const {

        return Vec2(_x + other._x, _y + other._y);

    }



    Vec2 operator-(const Vec2& other) const {

        return Vec2(_x - other._x, _y - other._y);

    }



    Vec2 operator*(const Vec2& other) const {

        return Vec2(_x * other._x, _y * other._y);

    }



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



    Vec2 operator*(const T val) const {

        return Vec2(_x * val, _y * val);

    }



    Vec2 operator/(const T val) const {

        try {

            Utils::check_denominator(val);

            return Vec2(_x / val, _y / val);

        } catch (std::invalid_argument& e) {

            std::cerr << e.what() << std::endl;

            return *this;

        }

    }



    Vec2 operator+=(const Vec2& other) {

        _x += other._x;

        _y += other._y;

        return *this;

    }



    Vec2 operator-=(const Vec2& other) {

        _x -= other._x;

        _y -= other._y;

        return *this;

    }



    Vec2 operator*=(const Vec2& other) {

        _x *= other._x;

        _y *= other._y;

        return *this;

    }



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



    Vec2 operator*=(const T val) {

        _x *= val;

        _y *= val;

        return *this;

    }



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



    bool operator==(const Vec2& other) const {

        return _x == other._x && _y == other._y;

    }



    bool operator!=(const Vec2& other) const {

        return !(*this == other);

    }



    friend std::ostream& operator<< <>(std::ostream& os, const Vec2<T>& vec);



    T length() const {

        return std::hypot(_x, _y);

    }



    Vec2 normalise() const {

        Vec2 res(_x, _y);

        T length = res.length();

        if (length != 0) {

            return res / length;

        }

        return res;

    }

};



template <typename T>

std::ostream& operator<<(std::ostream& os, const Vec2<T> & vec) {

    os << "(" << vec._x << ", " << vec._y << ")";

    return os;

}
