#pragma once
#include <math.h>

template <typename T>
struct Point2
{
	T x, y;

	Point2()
	{
		x = T();
		y = T();
	}

	Point2(T x, T y) :x(x), y(y) {}

	Point2<T> operator+(Point2<T> const& r) const {
		Point2<T> res;
		res.x = x + r.x;
		res.y = y + r.y;
		return res;
	}

	Point2<T> operator+(T r) const {
		Point2<T> res;
		res.x = x + r;
		res.y = y + r;
		return res;
	}

	Point2<T> operator-(Point2<T> const& r) const {
		Point2<T> res;
		res.x = x - r.x;
		res.y = y - r.y;
		return res;
	}

	Point2<T> operator-(T r) const {
		Point2<T> res;
		res.x = x - r;
		res.y = y - r;
		return res;
	}

	Point2<T> operator*(Point2<T> const& r) const {
		Point2<T> res;
		res.x = x * r.x;
		res.y = y * r.y;
		return res;
	}

	Point2<T> operator*(T r) const {
		Point2<T> res;
		res.x = x * r;
		res.y = y * r;
		return res;
	}

	Point2<T> operator/(Point2<T> r) const {
		Point2<T> res;
		res.x = x / r.x;
		res.y = y / r.y;
		return res;
	}

	Point2<T> operator/(T r) const {
		Point2<T> res;
		res.x = x / r;
		res.y = y / r;
		return res;
	}

	Point2<T>& operator+=(Point2<T> const& r) {
		x = x + r.x;
		y = y + r.y;
		return *this;
	}

	Point2<T>& operator+=(T r) {
		x = x + r;
		y = y + r;
		return *this;
	}

	Point2<T>& operator-=(Point2<T> const& r) {
		x = x - r.x;
		y = y - r.y;
		return *this;
	}

	Point2<T>& operator-=(T r) {
		x = x - r;
		y = y - r;
		return *this;
	}

	Point2<T>& operator*=(Point2<T> const& r) {
		x = x * r.x;
		y = y * r.y;
		return *this;
	}

	Point2<T>& operator*=(T r) {
		x = x * r;
		y = y * r;
		return *this;
	}

	Point2<T>& operator/=(Point2<T> r) {
		x = x / r.x;
		y = y / r.y;
		return *this;
	}

	Point2<T>& operator/=(T r) {
		x = x / r;
		y = y / r;
		return *this;
	}

};

template <typename T>
struct Point3
{
	T x, y, z;

	Point3()
	{
		x = T();
		y = T();
		z = T();
	}

	Point3(T x, T y, T z) :x(x), y(y), z(z) {}

	Point3<T> operator+(Point3<T> const& r) const {
		Point3<T> res;
		res.x = x + r.x;
		res.y = y + r.y;
		res.z = z + r.z;
		return res;
	}

	Point3<T> operator+(T r) const {
		Point3<T> res;
		res.x = x + r;
		res.y = y + r;
		res.z = z + r;
		return res;
	}

	Point3<T> operator-(Point3<T> const& r) const {
		Point3<T> res;
		res.x = x - r.x;
		res.y = y - r.y;
		res.z = z - r.z;
		return res;
	}

	Point3<T> operator-(T r) const {
		Point3<T> res;
		res.x = x - r;
		res.y = y - r;
		res.z = z - r;
		return res;
	}

	Point3<T> operator*(Point3<T> const& r) const {
		Point3<T> res;
		res.x = x * r.x;
		res.y = y * r.y;
		res.z = z * r.z;
		return res;
	}

	Point3<T> operator*(T r) const {
		Point3<T> res;
		res.x = x * r;
		res.y = y * r;
		res.z = z * r;
		return res;
	}

	Point3<T> operator/(Point3<T> r) const {
		Point3<T> res;
		res.x = x / r.x;
		res.y = y / r.y;
		res.z = z / r.z;
		return res;
	}

	Point3<T> operator/(T r) const {
		Point3<T> res;
		res.x = x / r;
		res.y = y / r;
		res.z = z / r;
		return res;
	}

	Point3<T>& operator+=(Point3<T> const& r) {
		x = x + r.x;
		y = y + r.y;
		z = z + r.z;
		return *this;
	}

	Point3<T>& operator+=(T r) {
		x = x + r;
		y = y + r;
		z = z + r;
		return *this;
	}

	Point3<T>& operator-=(Point3<T> const& r) {
		x = x - r.x;
		y = y - r.y;
		z = z - r.z;
		return *this;
	}

	Point3<T>& operator-=(T r) {
		x = x - r;
		y = y - r;
		z = z - r;
		return *this;
	}

	Point3<T>& operator*=(Point3<T> const& r) {
		x = x * r.x;
		y = y * r.y;
		z = z * r.z;
		return *this;
	}

	Point3<T>& operator*=(T r) {
		x = x * r;
		y = y * r;
		z = z * r;
		return *this;
	}

	Point3<T>& operator/=(Point3<T> r) {
		x = x / r.x;
		y = y / r.y;
		z = z / r.z;
		return *this;
	}

	Point3<T>& operator/=(T r) {
		x = x / r;
		y = y / r;
		z = z / r;
		return *this;
	}

};

template <typename T>
inline bool operator==(const Point3<T> r, const Point3<T> l) {
	return l.x == r.x && l.y == r.y && l.z == r.z;
}

template <typename T>
inline bool operator==(const Point2<T> r, const Point2<T> l) {
	return l.x == r.x && l.y == r.y;
}

template <typename T>
struct Vec2
{
	T x, y;
	
	Vec2() {
		x = T();
		y = T();
	}
	
	Vec2(T x, T y) :x(x), y(y) {}
	
	Vec2<T> operator+(Vec2<T> const& r) const {
		Vec2<T> res;
		res.x = x + r.x;
		res.y = y + r.y;
		return res;
	}

	Vec2<T> operator+(T r) const {
		Vec2<T> res;
		res.x = x + r;
		res.y = y + r;
		return res;
	}

	Vec2<T> operator-(Vec2<T> const& r) const {
		Vec2<T> res;
		res.x = x - r.x;
		res.y = y - r.y;
		return res;
	}

	Vec2<T> operator-(T r) const {
		Vec2<T> res;
		res.x = x - r;
		res.y = y - r;
		return res;
	}

	T operator*(Vec2<T> const& r) const {
		T res;
		res = x * r.x + y * r.y;
		return res;
	}
	
	Vec2<T> operator*(T r) const {
		Vec2<T> res;
		res.x = x * r;
		res.y = y * r;
		return res;
	}
	
	Vec2<T> operator/(T r) const {
		Vec2<T> res;
		res.x = x / r;
		res.y = y / r;
		return res;
	}

	Vec2<T>& operator+=(Vec2<T> const& r) {
		x = x + r.x;
		y = y + r.y;
		return *this;
	}

	Vec2<T>& operator+=(T r) {
		x = x + r;
		y = y + r;
		return *this;
	}

	Vec2<T>& operator-=(Vec2<T> const& r) {
		x = x - r.x;
		y = y - r.y;
		return *this;
	}

	Vec2<T>& operator-=(T r) {
		x = x - r;
		y = y - r;
		return *this;
	}
	
	Vec2<T>& operator*=(T r) {
		x = x * r;
		y = y * r;
		return *this;
	}
	
	Vec2<T>& operator/=(T r) {
		x = x / r;
		y = y / r;
		return *this;
	}
	
	double length() {
		return sqrt(x * x + y * y);
	}
	
	Vec2<T> unit_vec() {
		double len = this->length();
		return { x / len, y / len };
	}
};

template <typename T>
inline bool operator==(const Vec2<T> r, const Vec2<T> l) {
	return l.x == r.x && l.y == r.y;
}