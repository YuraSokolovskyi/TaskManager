#include "SidePanel.h"
#include "iostream"

SidePanel::SidePanel(QWidget *parent) : QWidget(parent) {
    this->setObjectName("navigationPanel");
    addOptions();
    options[0]->select();
}

int SidePanel::calculateOptionWidth() {
    return 220;
}

void SidePanel::addOptions() {
    SidePanelOption *projects = new SidePanelOption(this, "../images/projects.png", "../images/projects_selected.png", "../images/projects_hovered.png", "Projects");
    SidePanelOption *projects1 = new SidePanelOption(this, "../images/projects.png", "../images/projects_selected.png", "../images/projects_hovered.png", "Test1");
    SidePanelOption *projects2 = new SidePanelOption(this, "../images/projects.png", "../images/projects_selected.png", "../images/projects_hovered.png", "Test2");

    options.push_back(projects);
    options.push_back(projects1);
    options.push_back(projects2);
}

void SidePanel::resizeEvent(QResizeEvent *event) {
    repositionOptions();
}

void SidePanel::repositionOptions() {
    for (int i = 0; i < options.size(); i++){
        options[i]->resize(calculateOptionWidth(), defaultOptionHeight);
        options[i]->move((this->width() - options[i]->width()) / 2, 30 + 70 * i);
    }
}

void SidePanel::unselectOptions() {
    for (auto option : options){
        option->unselect();
    }
}
