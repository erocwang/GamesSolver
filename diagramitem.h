#ifndef DIAGRAMITEM_H
#define DIAGRAMITEM_H

#include <QGraphicsPixmapItem>
#include <QInputDialog>
#include <QGraphicsTextItem>
#include <QVector>

using namespace std;

QT_BEGIN_NAMESPACE
class QPixmap;
class QGraphicsSceneContextMenuEvent;
class QMenu;
class QPolygonF;
QT_END_NAMESPACE

class Edge;

class DiagramItem : public QGraphicsPolygonItem {
public:
    enum DiagramType {StartEnd,Node};
    DiagramItem(DiagramType diagramType, QGraphicsItem *parent = nullptr);
    void removeEdge(Edge *edge);
    void removeEdges();
    DiagramType diagramType() const {
        return myDiagramType;
    }
    QPolygonF polygon() const {
        return myPolygon;
    }
    void addEdge(Edge *edge);
    QPixmap image() const;
    int type() const override {
        return Type;
    }
    pair<int,int> payoff;
    QVector<Edge*> outEdges;
    DiagramItem * parentNode;
    Edge * parentEdge;
    bool player1;

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;

private:
    DiagramType myDiagramType;
    QPolygonF myPolygon;
    QColor itemColor;
    QVector<Edge*> edges;
    QGraphicsTextItem * payoffLabel;

};

#endif // DIAGRAMITEM_H
