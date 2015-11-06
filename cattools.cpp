#include "cattools.h"
#include "ui_cattools.h"
#include "iostream"

#include <QFileDialog>
#include <QMessageBox>
#include <QIODevice>
#include <QTreeWidgetItem>

using namespace std;

CatTools::CatTools(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CatTools)
{
    ui->setupUi(this);
}

CatTools::~CatTools()
{
    delete ui;
}

void CatTools::on_openButton_clicked()
{
    //TODO(Demetry): Create a dialog to open file.
    /*
     * Then open XML file and read contents
     */

    fileName = QFileDialog::getOpenFileName(this, tr("Open XML File"), "/", tr("XML Files (*.xml)"));
    QFile *file = new QFile(fileName);

    const QStringList *l = new QStringList(fileName);

    ui->treeWidget->addTopLevelItem(new QTreeWidgetItem(*l, 0));
}

void CatTools::on_closeButton_clicked()
{
    this->close();
}
