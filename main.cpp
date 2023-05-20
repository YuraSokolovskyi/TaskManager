#include <QApplication>
#include "QFile"
#include "TaskManager.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    TaskManager taskManager;
    taskManager.show();

    // load styles
    QFile styles(R"(..\styles\light.css)");
    if(styles.open(QIODevice::ReadOnly)){
        QTextStream textStream(&styles);
        QString styleText = textStream.readAll();
        styles.close();
        app.setStyleSheet(styleText);
    }

    return QApplication::exec();
}
