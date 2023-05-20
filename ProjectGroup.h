#ifndef TASKMANAGERGUI_PROJECTGROUP_H
#define TASKMANAGERGUI_PROJECTGROUP_H

#include "QWidget"
#include "QLabel"
#include "QPushButton"
#include "ProjectAddButton.h"
#include "Project.h"

#include "iostream"

class ProjectGroup : public QWidget {
private:
    std::string name; // name of the group
    QLabel *nameLabel; // label with name
    QLabel *countLabel; // label with number of projects
    std::vector<Project*> projects; // list with all projects
    ProjectAddButton *projectAddButton; // button to add new project


public:
    static const int projectGroupWidth = 345; // default group width

    ProjectGroup(QWidget *parent, std::string name);
    ProjectGroup* setName(std::string name); // set name of the group
    void addProject(); // add new project
    void repositionProjects(); // move all project to the right position
    void updateCounter(); // update project counter


protected:
    void resizeEvent(QResizeEvent *event) override;
};


#endif //TASKMANAGERGUI_PROJECTGROUP_H
