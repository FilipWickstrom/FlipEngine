#pragma once

template <typename T>
class Vec3
{
public:
	Vec3();
	Vec3(const T& x, const T& y, const T& z);
	Vec3(const T& scalar);
	~Vec3() = default;

	/*
		Addition
	*/
	Vec3<T>		operator+(const Vec3<T>& vec)	const;
	Vec3<T>		operator+(const T scalar)		const;
	Vec3<T>&	operator+=(const Vec3<T>& vec);
	Vec3<T>&	operator+=(const T scalar);
	
	/*
		Subtraction
	*/
	Vec3<T>		operator-(const Vec3<T>& vec)	const;
	Vec3<T>		operator-(const T scalar)		const;
	Vec3<T>&	operator-=(const Vec3<T>& vec);
	Vec3<T>&	operator-=(const T scalar);

	/*
		Multiplication
	*/
	Vec3<T>		operator*(const Vec3<T>& vec)	const;
	Vec3<T>		operator*(const T scalar)		const;
	Vec3<T>&	operator*=(const Vec3<T>& vec);
	Vec3<T>&	operator*=(const T scalar);

	/*
		Division
	*/
	Vec3<T>		operator/(const Vec3<T>& vec)	const;
	Vec3<T>		operator/(const T scalar)		const;
	Vec3<T>&	operator/=(const Vec3<T>& vec);
	Vec3<T>&	operator/= (const T scalar);

	/*
		Comparison
	*/
	bool	operator==(const Vec3& vec) const;
	bool	operator!=(const Vec3& vec) const;

	/*
		Index operation
	*/
	//T		operator[](const int& index) const;
	//T&	operator[](const int& index);

	/*
		Special functions
	*/
	T			Length() const;
	void		Normalize();
	static Vec3 Lerp(const Vec3& vec1, const Vec3& vec2, float time);
	T			Dot(const Vec3& vec) const;
	Vec3		Cross(const Vec3& vec) const;
	T			Distance(const Vec3& vec) const;
	T			DistanceSquared(const Vec3& vec) const;

public:
	T x;
	T y;
	T z;

};



template<typename T>
inline Vec3<T>::Vec3()
	: x(0), y(0), z(0)
{
}
template<typename T>
inline Vec3<T>::Vec3(const T& x, const T& y, const T& z)
	: x(x), y(y), z(z)
{
}
template<typename T>
inline Vec3<T>::Vec3(const T& scalar)
	: x(scalar), y(scalar), z(scalar)
{
}



template<typename T>
inline Vec3<T> Vec3<T>::operator+(const Vec3<T>& vec) const
{
	return Vec3<T>( x + vec.x, y + vec.y, z + vec.z );
}
template<typename T>
inline Vec3<T> Vec3<T>::operator+(const T scalar) const
{
	return Vec3<T>( x + scalar, y + scalar, z + scalar);
}
template<typename T>
inline Vec3<T>& Vec3<T>::operator+=(const Vec3& vec)
{
	return *this = *this + vec;
}
template<typename T>
inline Vec3<T>& Vec3<T>::operator+=(const T scalar)
{
	return *this + scalar;
}


template<typename T>
inline Vec3<T> Vec3<T>::operator-(const Vec3<T>& vec) const
{
	return Vec3<T>(x - vec.x, y - vec.y, z - vec.z);
}
template<typename T>
inline Vec3<T> Vec3<T>::operator-(const T scalar) const
{
	return Vec3<T>(x - scalar, y - scalar, z - scalar);
}
template<typename T>
inline Vec3<T>& Vec3<T>::operator-=(const Vec3& vec)
{
	return *this = *this - vec;
}
template<typename T>
inline Vec3<T>& Vec3<T>::operator-=(const T scalar)
{
	return *this - scalar;
}



template<typename T>
inline Vec3<T> Vec3<T>::operator*(const Vec3<T>& vec) const
{
	return Vec3<T>(x * vec.x, y * vec.y, z * vec.z);
}
template<typename T>
inline Vec3<T> Vec3<T>::operator*(const T scalar) const
{
	return Vec3<T>(x * scalar, y * scalar, z * scalar);
}
template<typename T>
inline Vec3<T>& Vec3<T>::operator*=(const Vec3& vec)
{
	return *this = *this * vec;
}
template<typename T>
inline Vec3<T>& Vec3<T>::operator*=(const T scalar)
{
	return *this * scalar;
}



template<typename T>
inline Vec3<T> Vec3<T>::operator/(const Vec3<T>& vec) const
{
	return Vec3<T>(x / vec.x, y / vec.y, z / vec.z);
}
template<typename T>
inline Vec3<T> Vec3<T>::operator/(const T scalar) const
{
	float div = 1.f / scalar;
	return Vec3<T>(x * div, y * div, z * div);
}
template<typename T>
inline Vec3<T>& Vec3<T>::operator/=(const Vec3& vec)
{
	return *this = *this / vec;
}
template<typename T>
inline Vec3<T>& Vec3<T>::operator/=(const T scalar)
{
	return *this / scalar;
}



template<typename T>
inline bool Vec3<T>::operator==(const Vec3& vec) const
{
	return	x == vec.x && 
			y == vec.y && 
			z == vec.z;
}
template<typename T>
inline bool Vec3<T>::operator!=(const Vec3& vec) const
{
	return	x != vec.x ||
			y != vec.y ||
			z != vec.z;
}



template<typename T>
inline T Vec3<T>::Length() const
{
	// SquareRoot(x^2 + y^2 + z^2)
	return sqrt(x * x + y * y + z * z);
}
template<typename T>
inline void Vec3<T>::Normalize()
{
	// Divide all the components by the length/magnitude
	*this /= this->Length();
}
template<typename T>
inline Vec3<T> Vec3<T>::Lerp(const Vec3& vec1, const Vec3& vec2, float time)
{
	return Vec3<T>(vec1 + (vec2 - vec1) * time);
}
template<typename T>
inline T Vec3<T>::Dot(const Vec3& vec) const
{
	return (x * vec.x) + (y * vec.y) + (z * vec.z);
}
template<typename T>
inline Vec3<T> Vec3<T>::Cross(const Vec3& vec) const
{
	return Vec3<T>	(y * vec.z - z * vec.y,
					 z * vec.x - x * vec.z,
					 x * vec.y - y * vec.x);
}
template<typename T>
inline T Vec3<T>::Distance(const Vec3& vec) const
{
	T dx = vec.x - x;
	T dy = vec.y - y;
	T dz = vec.z - z;
	return sqrt( (dx * dx) + (dy * dy) + (dz * dz) );
}
template<typename T>
inline T Vec3<T>::DistanceSquared(const Vec3& vec) const
{
	T dx = vec.x - x;
	T dy = vec.y - y;
	T dz = vec.z - z;
	return (dx * dx) + (dy * dy) + (dz * dz);
}



typedef Vec3<float>			Vec3f;
typedef Vec3<int>			Vec3i;
typedef Vec3<unsigned int>	Vec3u;
