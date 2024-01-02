#include "vector.h"

Vector::Vector(double x, double y) :
 vector(Point(x,y))
{

}

Vector::Vector(const Vector &other)
{
    vector.x_ = other.vector.x_;
    vector.y_ = other.vector.y_;
}

Vector::Vector()
{
    vector.x_=0;
    vector.y_=0;
}

Vector Vector::vector_by_scale(double scale) // умножение вектора на скаляр
{
    return Vector(vector.x_*scale, vector.y_*scale);
}

double Vector::scale(){ // длина вектора
 return sqrt(vector.x_*vector.x_ + vector.y_*vector.y_);
}
Vector Vector::operator +(Vector &other){ // сложение векторов
 Vector temp;
 temp.vector.x_ = vector.x_ + other.vector.x_;
 temp.vector.y_ = vector.y_ + other.vector.y_;
 return temp;
}

Vector& Vector::operator=(const Vector &othr){
 if(this==&othr)  return *this;
     vector.x_ = othr.vector.x_;
     vector.y_ = othr.vector.y_;
     return *this;

}

Point::Point()
{

}
Point::Point(double x, double y){
 x_=x;
 y_=y;
}
