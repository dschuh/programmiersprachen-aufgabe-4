#include <iostream>
#include <cmath>
#include "mat2.hpp"

Mat2::Mat2():
  a11_{1.0f}, a12_{0.0f},
  a21_{0.0f}, a22_{1.0f}{}

Mat2::Mat2(float a1, float a2, float a3, float a4):
  a11_{a1}, a12_{a2},
  a21_{a3}, a22_{a4}{}

float Mat2::geta11() const {
	return a11_;
}

float Mat2::geta12() const {
	return a12_;
}

float Mat2::geta21() const {
	return a21_;
}

float Mat2::geta22() const {
	return a22_;
}

Mat2& Mat2::operator *= (Mat2 const& m){
  float a11=a11_; 
  float a12=geta12(); 
  float a21=geta21(); 
  float a22=geta22(); 
  a11_ = (a11 * m.a11_)+(a12 * m.a21_);
  a12_ = (a11 * m.a12_)+(a12 * m.a22_);
  a21_ = (a21 * m.a11_)+(a22 * m.a21_);
  a22_ = (a21 * m.a12_)+(a22 * m.a22_);
	return *this;
}

Mat2 operator *(Mat2 const& m1, Mat2 const& m2){
    Mat2 result{m1};
    result *= m2;
    return result;
}

float Mat2::det() const{
    return (a11_*a22_) - (a12_*a21_);
}

Vec2 operator *(Mat2 const& m, Vec2 const& v){
    Vec2 res{};
    res.x_=(m.a11_*v.x_)+(m.a12_*v.y_);
    res.y_=(m.a21_*v.x_)+(m.a22_*v.y_);
    return res;
}

Vec2 operator *(Vec2 const& v, Mat2 const& m){
    Vec2 res{};
    res.x_=(v.x_*m.a11_)+(v.x_*m.a21_);
    res.y_=(v.y_*m.a12_)+(v.y_*m.a22_);
    return res;
}

Mat2 inverse(Mat2 const& m){
  if(m.det()==0){
    std::cout << "Es existiert keine Inverse zu dieser Matrix! \n";
    return m;
  }
  else{
    Mat2 result{};
    float inv_det = 1.0f / m.det();
    result.a11_=m.a22_*(1 / m.det());
    result.a12_=(-1 * m.a12_)*(1 / m.det());
    result.a21_=(-1 * m.a21_)*(1 / m.det());
    result.a22_=m.a11_*(1 / m.det());
    return result;
    }
}

Mat2 transpose(Mat2 const& m){
  return Mat2{m.a11_, m.a21_, m.a12_, m.a22_};
}

Mat2 make_rotation_mat2(float phi){
  return Mat2{cos(phi), -sin(phi), sin(phi), cos(phi)};
}
