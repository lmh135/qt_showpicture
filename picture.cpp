#include "picture.h"
#include "ui_picture.h"


picture::picture(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::picture)
{
    ui->setupUi(this);
    connect(ui->exitBtn,SIGNAL(clicked()),this,SLOT(close()));
}

picture::~picture()
{
    delete ui;
}


void picture::on_ShowPictureBtn_clicked()
{
    QString fileName=QFileDialog::getOpenFileName(this,QString("open data"));
    if ( (fileName.contains(".jpg") || fileName.contains(".png"))==0 )
    {
        QMessageBox::information(this,"error","It's not a picture!"); //绑定失败弹出信息对话框
    }
    QByteArray fn=(fileName).toLocal8Bit();
    const char* file_name=fn.data();
    std::cout<<file_name<<std::endl;

    QPixmap *img1 = new QPixmap(file_name);
    img1->scaled(ui->label->size(), Qt::KeepAspectRatio);
    ui->label->setScaledContents(true);
    ui->label->setPixmap(*img1);
}

void picture::on_exitBtn_clicked()
{

}

void picture::on_pushButton_clicked()
{
      disconnect(ui->exitBtn,SIGNAL(clicked()),this,SLOT(close()));
}
