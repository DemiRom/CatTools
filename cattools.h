#ifndef CATTOOLS_H
#define CATTOOLS_H

#include <QMainWindow>
#include <QFileDialog>

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
    QFileDialog *dialog;
    QString fileName;
};

#endif // CATTOOLS_H
