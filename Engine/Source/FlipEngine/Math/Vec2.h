#pragma once

template <typename T> 
class Vec2
{
public:
	Vec2();
	Vec2(const T& x, const T& y);
	Vec2(const T& scalar);
	~Vec2() = default;

	/*
		Operations between vectors
	*/ 

	Vec2	operator+(const Vec2& vec) const;
	Vec2	operator-(const Vec2& vec) const;
	Vec2	operator*(const Vec2& vec) const;
	Vec2	operator/(const Vec2& vec) const;
	Vec2&	operator+=(const Vec2& vec);
	Vec2&	operator-=(const Vec2& vec);
	Vec2&	operator*=(const Vec2& vec);
	Vec2&	operator/=(const Vec2& vec);
	bool	operator==(const Vec2& vec) const;
	bool	operator!=(const Vec2& vec) const;

	/*
		Operations with scalars
	*/

	Vec2 operator*(const T& scalar) const;
	Vec2 operator/(const T& scalar) const;

	/*
		Special functions
	*/ 

	T			Length() const;
	void		Normalize();
	static Vec2 Lerp(const Vec2& vec1, const Vec2& vec2, float time);
	T			Distance(const Vec2& vec) const;
	T			DistanceSquared(const Vec2& vec) const;

public:
	T x;
	T y;

};

template<typename T>
inline Vec2<T>::Vec2()
	: x(0), y(0)
{
}

template<typename T>
inline Vec2<T>::Vec2(const T& x, const T& y)
	: x(x), y(y)
{
}

template<typename T>
inline Vec2<T>::Vec2(const T& scalar)
	: x(scalar), y(scalar)
{
}

template<typename T>
inline Vec2<T> Vec2<T>::operator+(const Vec2& vec) const
{
	return Vec2<T>(x + vec.x, y + vec.y);
}

template<typename T>
inline Vec2<T> Vec2<T>::operator-(const Vec2& vec) const
{
	return Vec2<T>(x - vec.x, y - vec.y);
}

template<typename T>
inline Vec2<T> Vec2<T>::operator*(const Vec2& vec) const
{
	return Vec2<T>(x * vec.x, y * vec.y);
}

template<typename T>
inline Vec2<T> Vec2<T>::operator/(const Vec2& vec) const
{
	return Vec2<T>(x / vec.x, y / vec.y);
}

template<typename T>
inline Vec2<T>& Vec2<T>::operator+=(const Vec2& vec)
{
	return *this = *this + vec;
}

template<typename T>
inline Vec2<T>& Vec2<T>::operator-=(const Vec2& vec)
{
	return *this = *this - vec;
}

template<typename T>
inline Vec2<T>& Vec2<T>::operator*=(const Vec2& vec)
{
	return *this = *this * vec;
}

template<typename T>
inline Vec2<T>& Vec2<T>::operator/=(const Vec2& vec)
{
	return *this = *this / vec;
}

template<typename T>
inline bool Vec2<T>::operator==(const Vec2& vec) const
{
	return	x == vec.x && 
			y == vec.y;
}

template<typename T>
inline bool Vec2<T>::operator!=(const Vec2& vec) const
{
	return	x != vec.x || 
			y != vec.y;
}

template<typename T>
inline Vec2<T> Vec2<T>::operator*(const T& scalar) const
{
	return Vec2<T>(x * scalar, y * scalar);
}

template<typename T>
inline Vec2<T> Vec2<T>::operator/(const T& scalar) const
{
	float div = 1 / scalar;
	return Vec2<T>(x * div, y * div);
}

template<typename T>
inline T Vec2<T>::Length() const
{
	// SquareRoot(x^2 + y^2)
	return sqrt(x*x + y*y);
}

template<typename T>
inline void Vec2<T>::Normalize()
{
	// Divide all the components by the length/magnitude
	*this /= this->Length();
}

template<typename T>
inline Vec2<T> Vec2<T>::Lerp(const Vec2& vec1, const Vec2& vec2, float time)
{
	return Vec2<T>( vec1 + (vec2-vec1) * time );
}

template<typename T>
inline T Vec2<T>::Distance(const Vec2& vec) const
{
	T dx = vec.x - x;
	T dy = vec.y - y;
	return sqrt( (dx * dx) + (dy * dy) );
}

template<typename T>
inline T Vec2<T>::DistanceSquared(const Vec2& vec) const
{
	T dx = vec.x - x;
	T dy = vec.y - y;
	return (dx * dx) + (dy * dy);
}


typedef Vec2<float>			Vec2f;
typedef Vec2<int>			Vec2i;
typedef Vec2<unsigned int>	Vec2u;
