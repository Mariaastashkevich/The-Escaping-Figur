#ifndef PHYSICS_H
#define PHYSICS_H
#include "vector.h"
#include <QObject>
#include <QPoint>
class Physics : public QObject
{ Q_OBJECT
public:
    Physics(QObject* parent = 0) :
        QObject(parent)
    {

    }
    Point update(double delta, QPoint x_c, QPoint y_c){ // передаем дельту времени и координаты вектора силы курсора мыши
//        double m = 0.04;
//        F_r = Vector(0,0);
//        F_c = Vector(x_c,y_c);
//        Vector F_result = F_r + F_c;
//        a_ = F_result.vector_by_scale(1/m); // вектор ускорения
//        double a_x = a_


    }
private:
    Vector F_c; // cursor force
    Vector F_p; // push force
    Vector F_r; // repulsion force
    Vector a_;
    double velocity_x;
    double velocity_y;
    double x_cur;
    double y_cur;
};

#endif // PHYSICS_H
