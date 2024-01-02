#include "customscene.h"

CustomScene::CustomScene(QObject *parent) :
    QGraphicsScene()
{
    Q_UNUSED(parent);
}

void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    emit MoveMouseSignal(event->scenePos());
}
