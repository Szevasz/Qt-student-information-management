#include "dlg_addstu.h"
#include "ui_dlg_addstu.h"
#include "stusql.h"
#include <QMessageBox>
Dlg_AddStu::Dlg_AddStu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_AddStu)
{
    ui->setupUi(this);
}

Dlg_AddStu::~Dlg_AddStu()
{
    delete ui;
}

void Dlg_AddStu::setType(bool isAdd,StuInfo info)
{
    m_isAdd = isAdd;
    m_info = info;
    ui->le_name->setText(info.name);
    ui->sb_age->setValue(info.age);
    ui->le_grade->setText(QString::number(info.grade));
    ui->le_class->setText(QString::number(info.uiclass));
    ui->le_seq->setText(QString::number(info.studentid));
    ui->le_phone->setText(info.phone);
    ui->le_wechat->setText(info.Wechat);
}

void Dlg_AddStu::on_btn_save_clicked()
{
    StuInfo info;
    auto ptr = stuSql::getinstance();

    info.name = ui->le_name->text();
    info.age = ui->sb_age->text().toUInt();
    info.grade = ui->le_grade->text().toUInt();
    info.uiclass = ui->le_class->text().toUInt();
    info.studentid = ui->le_seq->text().toUInt();
    info.phone = ui->le_phone->text();
    info.Wechat = ui->le_wechat->text();


    if(m_isAdd)
    {
        ptr->addStu(info);
    }
    else
    {
        info.id=m_info.id;
        ptr->updateStuInfo(info);
    }
    QMessageBox::information(nullptr,"信息","存储成功");
    this->hide();

}


void Dlg_AddStu::on_pushButton_2_clicked()
{
    this->hide();
}

