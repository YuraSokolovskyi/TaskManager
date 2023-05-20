#ifndef TASKMANAGERGUI_TASKMANAGER_H
#define TASKMANAGERGUI_TASKMANAGER_H

#include "QWidget"
#include "SidePanel.h"
#include "QScrollArea"
#include "ProjectView.h"
#include "QScrollBar"

//temp
#include "iostream"

class TaskManager : public QWidget {
private:
    SidePanel *sidePanel; // side panel with different views
    ProjectView *projectView; // project view
    QScrollArea *scrollArea = nullptr; // scroll area for views
    View *currentView; // current view


public:
    TaskManager(QWidget *parent = nullptr);
    void resizeCurrentView(); // fit current view into scroll area


protected:
    void resizeEvent(QResizeEvent *event) override;
};


#endif //TASKMANAGERGUI_TASKMANAGER_H
