#include "ProjectView.h"
#include "TaskManager.h"
#include "QScrollArea"

ProjectView::ProjectView(QWidget *parent) : View(parent) {
    // defaults
    this->setObjectName("projectView");

    // groups
    groups = {
            new ProjectGroup(this, "Working"),
            new ProjectGroup(this, "In Progress"),
            new ProjectGroup(this, "Completed"),
    };
    for (ProjectGroup *group : groups) group->resize(ProjectGroup::projectGroupWidth, group->height());
}

void ProjectView::resizeEvent(QResizeEvent *event) {
    std::cout << "projectView resized" << this->width() << " " << this->height() <<"\n";
    // it can not be smaller than all groups
    if (this->width() < getMinWidth()) {
        this->resize(getMinWidth(), this->height());
        return;
    }

    // groups
    int start = std::max((this->width() - getMinWidth()) / 2, 0); // start position of first group
    for (int i = 0; i < groups.size(); i++){ // move all groups
        groups[i]->move(30 + start + i * (ProjectGroup::projectGroupWidth + margin), 30);
    }

    QWidget::resizeEvent(event);
}

int ProjectView::getMinWidth() {
    return groups.size() * ProjectGroup::projectGroupWidth + (groups.size() - 1) * margin + 60;
}

int ProjectView::getMinHeight() {
    int temp = 0;
    for (ProjectGroup *group : groups) if (temp < group->height()) temp = group->height();
    return temp + 60;
}

void ProjectView::updateViewSize() {
    if (this->height() < getMinHeight()) this->resize(this->width(), getMinHeight());
    if (this->width() < getMinWidth()) this->resize(getMinWidth(), this->height());
}
