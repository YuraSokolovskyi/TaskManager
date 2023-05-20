#include "Project.h"

Project::Project(QWidget *parent) : QWidget(parent) {
    // default
    this->setObjectName("projectWidget");

    // name
    name = new QLineEdit(this);
    name->setObjectName("projectName");
    name->resize(nameWidth, 30);
    name->move(20, 20);
    QFont fontName("Roboto", 19);
    fontName.setWeight(QFont::Medium);
    name->setFont(fontName);
    name->setPlaceholderText("Project name");

    // description
    description = new QPlainTextEdit(this);
    description->setObjectName("projectDescription");
    description->move(20, 60);
    QFont fontDescription("Roboto", 15);
    fontDescription.setWeight(QFont::Light);
    description->resize(nameWidth, 60);
    description->setFont(fontDescription);
    description->setPlaceholderText("Project description");
}

void Project::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
}

int Project::getHeight() {
    return 20 + name->height() + 10 + description->height() + 20;
}
