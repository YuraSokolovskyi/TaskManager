#include "TaskManager.h"
#include "QScrollBar"

TaskManager::TaskManager(QWidget *parent) : QWidget(parent) {
    // set defaults
    this->setObjectName("mainWindow");
    this->resize(1440, 951);
    this->setMouseTracking(true);

    // side panel
    sidePanel = new SidePanel(this);

    // project view
    projectView = new ProjectView(this);
    projectView->move(sidePanel->width(), 0);

    // current view
    currentView = projectView;

    // scroll area
    scrollArea = new QScrollArea(this);
    scrollArea->setObjectName("scrollArea");
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    scrollArea->setWidget(currentView);
}

void TaskManager::resizeEvent(QResizeEvent *event) {
    std::cout << "taskManager resized" << this->width() << " " << this->height() <<"\n";
    // side panel
    sidePanel->resize(sidePanel->sidePanelWidth, this->height());
    sidePanel->move(0, 0);

    // scroll area
    scrollArea->resize(this->width() - sidePanel->width(), this->height());
    scrollArea->move(sidePanel->width(), 0);

    // current view
    resizeCurrentView();

    QWidget::resizeEvent(event);
}

void TaskManager::resizeCurrentView() {
    int currentViewHeight = std::max(currentView->getMinHeight(), scrollArea->height());
    int currentViewWidth = std::max(currentView->getMinWidth(), scrollArea->width());
    currentView->resize(currentViewWidth, currentViewHeight);
}
