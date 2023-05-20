#ifndef TASKMANAGERGUI_PROJECT_H
#define TASKMANAGERGUI_PROJECT_H

#include "QWidget"
#include "QLineEdit"
#include "QPlainTextEdit"

class Project : public QWidget {
private:
    QLineEdit *name;
    QPlainTextEdit *description;


public:
    static const int nameWidth = 230;

    Project(QWidget *parent);
    int getHeight();


protected:
    void resizeEvent(QResizeEvent *event) override;
};


#endif //TASKMANAGERGUI_PROJECT_H
