#include "include/mainwindow.hpp"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) : 
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    pdf_doc(new QPdfDocument(this))
{
    ui->setupUi(this);
    setWindowTitle("TinyPDF");
    
    ui->pdfView->setDocument(pdf_doc);
    ui->pdfView->setZoomMode(QPdfView::ZoomMode::FitToWidth);
    ui->pdfView->setPageMode(QPdfView::PageMode::MultiPage);
}

MainWindow::~MainWindow() {
    
}

void MainWindow::open_file(const QUrl doc_location) {
    std::cout << doc_location.toString().toStdString() << std::endl;
    if(doc_location.isLocalFile()) {
        pdf_doc->load(doc_location.toLocalFile());
        const auto doc_title = pdf_doc->metaData(QPdfDocument::MetaDataField::Title).toString();
        setWindowTitle(!doc_title.isEmpty() ? doc_title : "Untitled");
    } else {
        QMessageBox::critical(this, "Error", "Invalid file path");
    }
}
