#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>

class CustomScene : public QGraphicsScene
{ Q_OBJECT
public:
    CustomScene(QObject* parent = 0);
signals:
    void MoveMouseSignal(QPointF point);
private:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

};

#endif // CUSTOMSCENE_H
