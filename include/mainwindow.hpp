#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QLoggingCategory>
#include <QFileDialog>
#include <QMessageBox>
#include <QSpinBox>
#include <QPdfBookmarkModel>
#include <QPdfDocument>
#include <QPdfPageNavigator>
#include <QStandardPaths>
#include <QtMath>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void open_file(const QUrl doc_location);

private:
    Ui::MainWindow *ui;

    QPdfDocument *pdf_doc;
    QFileDialog *file_dialog;
};

#endif // MAINWINDOW_H