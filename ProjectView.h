#ifndef TASKMANAGERGUI_PROJECTVIEW_H
#define TASKMANAGERGUI_PROJECTVIEW_H

#include "QWidget"
#include "ProjectGroup.h"
#include "View.h"

#include "iostream"

class ProjectView : public View {
private:
    int margin = 30; // margin between groups
    std::vector<ProjectGroup*> groups; // all groups
public:
    ProjectView(QWidget *parent);
    int getMinWidth() override; // get groups width with margins
    int getMinHeight() override; // get max group height
    void updateViewSize() override; // update size of a view
protected:
    void resizeEvent(QResizeEvent *event) override;
};


#endif //TASKMANAGERGUI_PROJECTVIEW_H
