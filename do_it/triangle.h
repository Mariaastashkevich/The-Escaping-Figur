#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <QPainter>
#include <QTimer>
#include <QPolygon>
#include <QObject>
#include <QGraphicsItem>
#include <QPointF>
#include <cmath>
class Triangle : public QObject, public QGraphicsItem
{ Q_OBJECT
public:
    Triangle(QObject* parent = 0);
    ~Triangle();

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
public slots:
    void UsePhysicsToMoveSlot(QPointF point);
    void Update(QPointF point);
private:
    QPointF cursor_;
    QTimer* timer;
    int trigger_rad_;
};



#endif // TRIANGLE_H
