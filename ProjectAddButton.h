#ifndef TASKMANAGER_PROJECTADDBUTTON_H
#define TASKMANAGER_PROJECTADDBUTTON_H

#include "QPushButton"
#include "QMouseEvent"

class ProjectAddButton : public QPushButton{
public:
    explicit ProjectAddButton(QWidget *parent, QString imgPath);

protected:
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
};


#endif //TASKMANAGER_PROJECTADDBUTTON_H
