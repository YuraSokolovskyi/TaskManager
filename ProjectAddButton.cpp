#include "ProjectAddButton.h"
#include "ProjectGroup.h"

ProjectAddButton::ProjectAddButton(QWidget *parent, QString imgPath) : QPushButton(parent){
    this->setIcon(QIcon(imgPath));
    this->setIconSize(QSize(15, 15));
}

void ProjectAddButton::enterEvent(QEnterEvent *event) {
    this->setStyleSheet("background-color: #9384D1;");
    QPushButton::enterEvent(event);
}

void ProjectAddButton::leaveEvent(QEvent *event) {
    this->setStyleSheet("background-color: #6C5DD3;");
    QPushButton::leaveEvent(event);
}

void ProjectAddButton::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton){
        this->setStyleSheet("background-color: #574AAB;");
        ((ProjectGroup *) (this->parentWidget()))->addProject();
    }
    QPushButton::mousePressEvent(event);
}

void ProjectAddButton::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton){
        this->setStyleSheet("background-color: #6C5DD3;");
    }
    QPushButton::mouseReleaseEvent(event);
}
