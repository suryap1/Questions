//
// Created by Tafseer Ahmed on 3/3/2018.
//

#ifndef COMP_VECTOR_3D_H
#define COMP_VECTOR_3D_H

#include <iostream>
#include <cmath>
#include <cassert>

template<class T>
class vect3 {
private:
    T x, y, z;
public:
    //3-D VECTOR CONSTRUCTORS
    inline vect3() : x(0), y(0), z(0) {}

    inline vect3(const T &p) : x(p), y(p), z(p) {}

    inline vect3(const T &x, const T &y, const T &z) : x(x), y(y), z(z) {}

    inline vect3(const vect3<T> &q) : x(q.x), y(q.y), z(q.z) {}

    //COMPARISIONS
    inline bool operator==(const vect3<T> &k) const {
        return (x == k.x && y == k.y && z == k.z);
    }

    inline bool operator!=(const vect3<T> &k) const {
        return (x != k.x || y != k.y || z != k.z);
    }

    // SCALING
    inline vect3<T> operator-() const {
        return vect3<T>(-x, -y, -z);
    }

    inline vect3<T> operator*(const T &k) const {
        return vect3<T>(x * k, y * k, z * k);
    }

    inline vect3<T> operator/(const T &k) const {
        return vect3<T>(x / k, y / k, z / k);
    }

    // BASIC ARITHMETIC
    inline vect3<T> operator+(const vect3<T> &k) const {
        return vect3<T>(x + k.x, y + k.y, z + k.z);
    }

    inline vect3<T> operator-(const vect3<T> &k) const {
        return vect3<T>(x - k.x, y - k.y, z - k.z);
    }

    inline vect3<T> operator*(const vect3<T> &k) const {
        return vect3<T>(x * k.x, y * k.y, z * k.z);
    }

    //INDEXING OPERATOR
    T &operator[](int index) {
        assert(index >= 0 && index <= 2);
        switch (index) {
            case 0: return x;
            case 1: return y;
            case 2: return z;
        }
        return x;
    }

    const T &operator[](int index) const {
        assert(index >= 0 && index <= 2);
        switch (index) {
            case 0: return x;
            case 1: return y;
            case 2: return z;
        }
        return x;
    }

//SHORT-HAND MODIFIERS
    inline vect3<T> &operator+=(const T &k) {
        x += k;
        y += k;
        z += k;
        return *this;
    }

    inline vect3<T> &operator+=(const vect3<T> &k) {
        x += k.x;
        y += k.y;
        z += k.z;
        return *this;
    }

    inline vect3<T> &operator-=(const T &k) {
        x -= k;
        y -= k;
        y -= k;
        return *this;
    }

    inline vect3<T> &operator-=(const vect3<T> &k) {
        x -= k.x;
        y -= k.y;
        y -= k.z;
        return *this;
    }

    inline vect3<T> &operator*=(const T &k) {
        x *= k;
        y *= k;
        z *= k;
        return *this;
    }

    inline vect3<T> &operator*=(const vect3<T> &k) {
        x *= k.x;
        y *= k.y;
        z *= k.z;
        return *this;
    }

    inline vect3<T> operator/=(const T &k) {
        x /= k;
        y /= k;
        z /= k;
        return *this;
    }

//VECTOR METHODS

    inline T length() const {
        return sqrt(x * x + y * y + z * z);
    }

    inline T lengthSq() const {
        return x * x + y * y + z * z;
    }

    inline vect3<T> &normalize() {
        T length = this->length();
        x /= length;
        y /= length;
        z /= length;
        return *this;
    }

    inline vect3<T> unit() const {
        T length = this->length();
        return vect3<T>(x / length, y / length, z / length);
    }

    inline T dot(const vect3<T> &k) const {
        return x * k.x + y * k.y + z * k.z;
    }

    inline vect3<T> cross(const vect3<T> &v) const {
        return vect3<T>(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
    }

    inline T distance(const T &p, const T &q, const T &r) const {
        return vect3<T>(x - p, y - q, z - r).length();
    }

    inline bool isNull() const {
        return (x == 0. && y == 0. && z == 0.);
    }

    //I/O STREAMS
    friend std::ostream &operator<<(std::ostream &out, const vect3<T> &v) {
        out << "[" << v.x << ", " << v.y << ", " << v.z << "]";
        return out;
    }

    friend std::istream &operator>>(std::istream &in, vect3<T> &v) {
        in >> v.x >> v.y >> v.z;
        return in;
    }

};

template <class T>
inline T distance(const vect3<T> &v1, const vect3<T> &v2) {
    return (v1 - v2).length();
}


#endif //COMP_VECTOR_3D_H
