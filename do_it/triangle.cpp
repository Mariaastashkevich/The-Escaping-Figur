#include "triangle.h"
#include "physics.h"
#include "vector.h"

Triangle::Triangle(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    trigger_rad_=45;

}

Triangle::~Triangle()
{

}

QRectF Triangle::boundingRect() const
{
    return QRectF(-20,-30,40,60);
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPolygon polygon;
    polygon << QPoint(0,-30) << QPoint(20,30) << QPoint(-20,30);
    painter->setBrush(Qt::green);
    painter->setPen(Qt::black);
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
 // moveMouseEvent проверка того тригеррится или нет
// таймер в конструктор треугольника и конекчу с :UsePhysicsToMoveSlot
void Triangle::UsePhysicsToMoveSlot(QPointF point)
{
    //timer->start(1000);
// *resistF = ( *velocity * (-1) * (1.0 / velocity->module()) * nuge * mass );
    double delta = 0.01;
     cursor_ = point; // текущее положение курсора мыши
     QPointF target = mapToScene(QPoint(0,0)); // координаты текущие нашего треугольника
     QLineF C_T(cursor_,target); // типо вектор CT
     QPointF R_C(target.x()-cursor_.x(), target.y()-cursor_.y()); // координаты вектора CT
     double k = (trigger_rad_/C_T.length());
     double m = 0.004; // ok
     R_C = QPointF(k*R_C.x(), k*R_C.y());
     QPointF R(cursor_.x()-R_C.x(), cursor_.y()-R_C.y());
     QPointF F_cursor(cursor_.x()-R.x(),cursor_.y()-R.y()); //координаты вектора силы курсора мыши
     //QLineF F_vec(R,cursor_); // вектор силы курсора мыши
     QPointF F_result(F_cursor.x(), F_cursor.y());
     QLineF a_(R*(1/m), cursor_*(1/m));

     double a_x = a_.dx();
     double a_y = a_.dy();
     double velocity_x = a_x*delta;
     double velocity_y = a_y*delta;
     if(sqrt(velocity_x*velocity_x + velocity_y*velocity_y) < 1.6){
         setPos(QPointF(0,0));
     }
     else
     setPos(pos() + QPointF(velocity_x*delta, velocity_y*delta));

     //timer->stop();
}

void Triangle::Update(QPointF point)
{

}
