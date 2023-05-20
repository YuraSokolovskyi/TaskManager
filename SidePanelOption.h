#ifndef TASKMANAGER_SIDEPANELOPTION_H
#define TASKMANAGER_SIDEPANELOPTION_H

#include "QWidget"
#include "QLabel"

class SidePanel;

class SidePanelOption : public QWidget{
public:
    explicit SidePanelOption(SidePanel *parent, QString imgPath, QString imgPathSelected, QString imgPathHovered, QString str);
    void select();
    void unselect();
    bool isSelected();
private:
    SidePanel *sidePanel;
    bool selected = false;
    QString imagePath;
    QString imagePathSelected;
    QString imagePathHovered;
    QLabel *image;
    QLabel *text;
protected:
    void resizeEvent(QResizeEvent *event) override;
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};


#endif //TASKMANAGER_SIDEPANELOPTION_H
