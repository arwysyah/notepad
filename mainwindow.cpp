#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open the File");
    QFile file(fileName);
    currentFile = fileName;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Warning","Cannot Open File"+ file.errorString());
        return;
    }
    this->setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
}


void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Save As");
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"Warning","Cannot Save File"+ file.errorString());
        return;
    }else{
     QMessageBox::information(this,"Succes","Succesfully Saved the file");
       printf("Success");
         return;
    }
   this->setWindowTitle(fileName);
    QTextStream out(&file);
    QString textFile = ui->textEdit->toPlainText();

    out << textFile;
    file.close();

}


void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Printer Name");
    QPrintDialog pDialog (&printer,this);
    if(pDialog.exec() == QDialog::Rejected){
        QMessageBox::warning(this,"Warning","Cannot Access Printer");
    }
    ui->textEdit->print(&printer);
}



void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}



void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}




void MainWindow::on_actionPaste_triggered()
{
     ui->textEdit->paste();
}


void MainWindow::on_actionUndo_triggered()
{
       ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
     ui->textEdit->redo();
}


void MainWindow::on_actionSave_triggered()

{
      qDebug() << "file exists+ "+windowTitle();
      qInfo () << "hello world";
 return;
//    ui->textEdit->saveGeometry();
}

