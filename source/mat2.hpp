#ifndef MAT2_HPP
#define MAT2_HPP

#include "Vec2.hpp"
struct Mat2{
//Constructors
Mat2();
Mat2(float a1, float a2, float a3, float a4);

float a11_;
float a12_;
float a21_;
float a22_;

float geta11() const;
float geta12() const;
float geta21() const;
float geta22() const;

float det() const;

Mat2& operator *=(Mat2 const& m);
};

Vec2 operator *(Mat2 const& m, Vec2 const& v);
Vec2 operator *(Vec2 const& v, Mat2 const& m);

Mat2 operator *(Mat2 const& m1, Mat2 const& m2);
Mat2 inverse(Mat2 const& m);
Mat2 transpose(Mat2 const& m);
Mat2 make_rotation_mat2(float phi);

#endif