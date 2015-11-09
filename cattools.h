#ifndef CATTOOLS_H
#define CATTOOLS_H

#include "stdio.h"
#include "iostream"

#include <QMainWindow>
#include <QFileDialog>
#include <QXmlStreamReader>

namespace Ui {
class CatTools;
}

class CatTools : public QMainWindow
{
    Q_OBJECT

public:
    explicit CatTools(QWidget *parent = 0);
    ~CatTools();

private slots:
    void on_openButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::CatTools *ui;
    QString fileName;
    QXmlStreamReader reader;

    void readFile(QFile&);
};

#endif // CATTOOLS_H
