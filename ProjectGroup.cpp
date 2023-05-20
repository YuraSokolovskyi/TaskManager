#include "ProjectGroup.h"
#include "ProjectView.h"

ProjectGroup::ProjectGroup(QWidget *parent, std::string name) : QWidget(parent) {
    // default
    this->setObjectName("projectGroup");
    this->name = name;

    // name label
    nameLabel = new QLabel(name.c_str(), this);
    QFont font("Roboto", 19);
    font.setWeight(QFont::Weight::Medium);
    nameLabel->setFont(font);
    nameLabel->setObjectName("projectGroupName");

    // label with project counter
    countLabel = new QLabel(this);
    countLabel->setText("(0)");
    QFont countFont("Roboto", 16);
    countFont.setWeight(QFont::Weight::Normal);
    countLabel->setFont(countFont);
    countLabel->move(nameLabel->fontMetrics().boundingRect(nameLabel->text()).width() + 10, 0);
    countLabel->setObjectName("projectGroupCount");

    // project add button
    projectAddButton = new ProjectAddButton(this, "../images/projectAddButton.png");
    projectAddButton->setObjectName("projectAddButton");
}

ProjectGroup *ProjectGroup::setName(std::string name) {
    this->name = std::move(name);
    nameLabel->setText(name.c_str());
    return this;
}

void ProjectGroup::addProject() {
    Project *temp = new Project(this);
    temp->resize(this->width(), temp->getHeight());
    projects.push_back(temp);
    repositionProjects();

    // resize project view
    ((ProjectView*)(this->parentWidget()))->updateViewSize();

    for (Project *project : projects) project->show();
    updateCounter();
}

void ProjectGroup::resizeEvent(QResizeEvent *event) {
    std::cout << "projectGroup resized" << this->width() << " " << this->height() <<"\n";
    // project add button
    projectAddButton->resize(nameLabel->height(), nameLabel->height());
    projectAddButton->move(this->width() - nameLabel->height(), 0);

    QWidget::resizeEvent(event);
}

void ProjectGroup::repositionProjects() {
    int temp = nameLabel->height() + 20;
    for(int i = 0; i < projects.size(); i++){
        projects[i]->move(0, temp);
        temp += projects[i]->height() + 20;
    }
    this->resize(this->width(), temp - 20);
}

void ProjectGroup::updateCounter() {
    std::string temp = "(" + std::to_string(projects.size()) + ")";
    countLabel->setText(temp.c_str());
    QFont font = countLabel->font();
    QFontMetrics metrics(font);
    countLabel->resize(metrics.size(0, temp.c_str()).width(), countLabel->height());
}
