#pragma once

/*
	Regular matrix rotations can lead to Gimbal Lock.
	Quaternions can't do that which is great.
*/

class Quaternion
{
public:
	Quaternion();
	Quaternion(const float& x, const float& y, const float& z, const float& w);
	~Quaternion() = default;

	// All operations



public:
	float x;
	float y;
	float z;
	float w;

};