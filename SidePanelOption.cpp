#include "SidePanel.h"
#include "iostream"
#include "SidePanelOption.h"
#include "QDebug"


SidePanelOption::SidePanelOption(SidePanel *parent, QString imgPath, QString imgPathSelected, QString imgPathHovered, QString str) : QWidget(parent){
    sidePanel = parent;
    this->setObjectName("sidePanelOption");
    // icon
    imagePath = imgPath;
    imagePathSelected = imgPathSelected;
    imagePathHovered = imgPathHovered;
    image = new QLabel(this);
    image->setPixmap(QPixmap(imgPath));
    image->resize(24, 24);

    // name
    text = new QLabel(this);
    text->setObjectName("sidePanelOptionText");
    text->setText(str);
    // font for name
    QFont font = text->font();
    font.setWeight(QFont::DemiBold);
    font.setPointSize(15);
    text->setFont(font);
}

void SidePanelOption::resizeEvent(QResizeEvent *event) {
    image->move(0, (this->height() - image->height()) / 2);
    text->move(image->width() + 10, this->height() / 2 - text->font().pointSize());
    QWidget::resizeEvent(event);
}

void SidePanelOption::enterEvent(QEnterEvent *event) { // hover enter
    if (selected) return;
    text->setStyleSheet("color: #9384D1;");
    image->setPixmap(imagePathHovered);
    QWidget::enterEvent(event);
}

void SidePanelOption::leaveEvent(QEvent *event) { // hover leave
    if (selected) return;
    text->setStyleSheet("color: #B6B6B6;");
    image->setPixmap(imagePath);
    QWidget::leaveEvent(event);
}

void SidePanelOption::select() {
    sidePanel->unselectOptions();
    selected = true;
    text->setStyleSheet("color: #6C5DD3;");
    image->setPixmap(imagePathSelected);
}

void SidePanelOption::unselect() {
    selected = false;
    text->setStyleSheet("color: #B6B6B6;");
    image->setPixmap(imagePath);
}

bool SidePanelOption::isSelected() {
    return selected;
}

void SidePanelOption::mousePressEvent(QMouseEvent *event) {
    select();
    QWidget::mousePressEvent(event);
}

