#ifndef TASKMANAGERGUI_VIEW_H
#define TASKMANAGERGUI_VIEW_H

#include "QWidget"

class View : public QWidget {
public:
    View(QWidget *parent) : QWidget(parent){}
    virtual int getMinWidth() = 0; // get groups width with margins
    virtual int getMinHeight() = 0; // get max height of all groups
    virtual void updateViewSize() = 0; // update size of a view
};


#endif //TASKMANAGERGUI_VIEW_H
