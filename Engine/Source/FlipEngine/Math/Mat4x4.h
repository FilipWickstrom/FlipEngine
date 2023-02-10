#pragma once

// Make it Column-major?
// [11, 21, 31, 41]
// [12, 22, 32, 42]
// [13, 23, 33, 43]
// [14, 24, 34, 44]

// Direct3D / HLSL uses mainly Column-major

// Simplemath:	Row-major
// Assimp:	Row-major
// GLM:		Column-major
// Irrlicht 	Row-major	Translations in 4:th row	



// Template based
class Mat4x4
{
public:


private:
	float val[16];

};