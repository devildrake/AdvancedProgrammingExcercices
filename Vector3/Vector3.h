#ifndef VECTOR3_H
#define VECTOR3_H
#include <math.h>
#include <iostream>

constexpr float PI = 3.141592653589793;

template <typename T>


class Vector3 {

public:
	T x, y, z;

	Vector3() :x(0), y(0), z(0) {}
	Vector3(T _x, T _y, T _z) :x(_x), y(_y), z(_z) {}
	Vector3(T _x, T _y) :x(_x), y(_y), z(0) {}
	Vector3(T a) :x(a.x), y(a.y), z(a.z) {}

	Vector3<T>(const Vector3<T>& a) {
		x = a.x;
		y = a.y;
		z = a.z;

	}

	~Vector3() {

	}

	void Normalize() {
		this = this->normalized();
	}

	Vector3 normalized() const {
		float mag = magnitude();
		Vector3 v(x, y, z);
		v.x /= mag;
		v.y /= mag;
		v.z /= mag;
		return v;
	}

	T magnitude()const {
		return sqrt(x * x + y * y + z * z);
	}

	T distance_to(const Vector3& v)const {
		Vector3 vector = v - *this;

		return vector.magnitude();
	}

	T dot_product(const Vector3& v)const {
		return (this->x * v.x + this->y * v.y + this->z * v.z);

	}
	Vector3 cross_product(const Vector3& v) {
		Vector3 c;
		c.x = (y * v.z - z * v.y);
		c.y = (z * v.x - x * v.z);
		c.z = (x * v.y - y * v.x);
		return c;
	}

	float angle_between(const Vector3& v)const {
		float mag = magnitude();
		float vMag = v.magnitude();

		float cos = dot_product(v) / (mag * vMag);

		return acos(cos) * 180 / PI;
	}
	void print_info()const {
		std::cout << "x: " << x << " y: " << y << " z:" << z << std::endl;
	}

	inline Vector3<float> operator + (const Vector3<float>& b)const {
		Vector3<float> v;

		v.x = this->x + b.x;
		v.y = this->y + b.y;
		v.z = this->z + b.z;

		return v;
	}

	Vector3<float> operator - (const Vector3<float>& b) {
		Vector3<float> v;

		v.x = this->x - b.x;
		v.y = this->y - b.y;
		v.z = this->z - b.z;
		return v;
	}

	void operator += (const Vector3<float>& b) {
		this->x = this->x + b.x;
		this->y = this->y + b.y;
		this->z = this->z + b.z;
	}


	void operator -= (const Vector3<float>& b) {
		this->x = this->x - b.x;
		this->y = this->y - b.y;
		this->z = this->z - b.z;
	}

	Vector3<double> operator + (const Vector3<double>& b)const {
		Vector3<double> v;

		v.x = this->x + b.x;
		v.y = this->y + b.y;
		v.z = this->z + b.z;

		return v;
	}

	void operator += (const Vector3<double>& b) {
		this->x = this->x + b.x;
		this->y = this->y + b.y;
		this->z = this->z + b.z;
	}

	void operator -= (const Vector3<double>& b) {
		this->x = this->x + b.x;
		this->y = this->y + b.y;
		this->z = this->z + b.z;
	}

	Vector3<double> operator - (const Vector3<double>& b) {
		Vector3<double> v;

		v.x = this->x - b.x;
		v.y = this->y - b.y;
		v.z = this->z - b.z;
		return v;
	}

	Vector3<int> operator + (const Vector3<int>& b)const {
		Vector3 <int> v;

		v.x = this->x + b.x;
		v.y = this->y + b.y;
		v.z = this->z + b.z;

		return v;
	}

	Vector3<int> operator - (const Vector3<int>& b) {
		Vector3<int> v;

		v.x = this->x - b.x;
		v.y = this->y - b.y;
		v.z = this->z - b.z;
		return v;
	}

	void  operator += (const Vector3<int>& b) {
		this->x = this->x + b.x;
		this->y = this->y + b.y;
		this->z = this->z + b.z;

	}

	void  operator -= (const Vector3<int>& b) {
		this->x = this->x + b.x;
		this->y = this->y + b.y;
		this->z = this->z + b.z;

	}

};

#endif // !VECTOR3_H
