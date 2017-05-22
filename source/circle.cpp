#include <cmath>
#include "circle.hpp"
#include "Vec2.hpp"
#include "color.hpp"
#include "mat2.hpp"

Circle::Circle():
    center_(0.0f, 0.0f),
    radius_(1.0f),
    color_(0.0f, 0.0f, 0.0f){}


Circle::Circle(Vec2 const& c, float r):
    center_(c),
    radius_(r),
    color_(0.0f, 0.0f, 0.0f){}

Circle::Circle(Vec2 const& a, float r, Color const& c):
    center_(a),
    radius_(r),
    color_(c){}

Vec2 Circle::getCenter() const {
	return center_;
}

float Circle::getRadius() const {
	return radius_;
}

Color Circle::getColor() const {
	return color_;
}

float Circle::circumference() const {
	return M_PI*radius_*2;
}


bool Circle::isInsideCirc (Vec2 const& p)const{
	float xcenter=getCenter().x_;
	float ycenter=getCenter().y_;
	float rad=getRadius();
	float a = p.x_-xcenter;
	float b = p.y_-ycenter;
	if(sqrt(pow(a, 2)+pow(b, 2))<rad){
		return true;
	}else return false;
} 

bool Circle::operator < (Circle const& c){
        return(radius_< c.radius_);
    }

bool Circle::operator > (Circle const& c){
        return(radius_> c.radius_);
    }

bool Circle::operator == (Circle const& c){
        return(radius_== c.radius_);
    }