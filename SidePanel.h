#ifndef TASKMANAGER_SIDEPANEL_H
#define TASKMANAGER_SIDEPANEL_H

#include "QWidget"
#include "SidePanelOption.h"

class SidePanel : public QWidget{
public:
    int sidePanelWidth = 250;

    explicit SidePanel(QWidget *parent);
    int calculateOptionWidth();
    void addOptions();
    void unselectOptions();
private:
    std::vector<SidePanelOption*> options = {};
    int defaultOptionHeight = 40;
    void repositionOptions();
protected:
    void resizeEvent(QResizeEvent *event) override;
};


#endif //TASKMANAGER_SIDEPANEL_H
