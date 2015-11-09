#include "cattools.h"
#include "ui_cattools.h"
#include "iostream"
#include "stdio.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QIODevice>
#include <QTreeWidgetItem>
#include <QXmlStreamReader>


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
    QFile file(QFileDialog::getOpenFileName(this, tr("Open XML File"), "/", tr("XML Files (*.xml)")));

    if(file.open(QIODevice::ReadOnly)){
        readFile(file);
    }
}

void CatTools::readFile(QFile &file){
    reader.setDevice(&file);

    while(!reader.atEnd() && !reader.hasError()){
        reader.readNext();
        if (reader.isStartElement())
        {
            QString name = reader.name().toString();

            //Set what to look for here.
            if (name == "firstName" || name == "lastName")
            {
                ui->lineEdit->setText(reader.readElementText());
            }
        }
    }

    reader.clear();
    file.close();
}

void CatTools::on_closeButton_clicked()
{
    this->close();
}
