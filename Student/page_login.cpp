#include "page_login.h"
#include "ui_page_login.h"

#include <qmessagebox.h>


Page_Login::Page_Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page_Login)
{
    ui->setupUi(this);

}

Page_Login::~Page_Login()
{
    delete ui;
}
void Page_Login::on_btn_login_clicked()
{
    //数据库查找用户名和密码

    //失败就提示

    //成功进入主界面

    QString text1=ui->le_user->text();
    QString text2=ui->le_password->text();
    if(text1=="szevasz"&&text2=="guohengjie0910")
    {
        emit sendLoginSuccess();
    }
    else
    {
        QMessageBox::information(nullptr,"警告","密码错误,请你好好想想密码");
    }


}



void Page_Login::on_btn_exit_clicked()
{
    //退出

    exit(0);
}

