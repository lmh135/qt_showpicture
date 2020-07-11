#ifndef PICTURE_H
#define PICTURE_H

#include <QMainWindow>
#include <QLabel>
#include <QMovie>
#include <QFileDialog>
#include <iostream>
#include <QMessageBox>

namespace Ui {
class picture;
}

class picture : public QMainWindow
{
    Q_OBJECT

public:
    explicit picture(QWidget *parent = 0);
    ~picture();

private slots:
    void on_ShowPictureBtn_clicked();

    void on_exitBtn_clicked();

    void on_pushButton_clicked();

private:
    Ui::picture *ui;
};

#endif // PICTURE_H
