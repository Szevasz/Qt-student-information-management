#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <page_login.h>
#include "stusql.h"
#include <dlg_addstu.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void keyPressEvent(QKeyEvent *event);

private slots:
    void on_btn_exit_clicked();

    void on_btn_simulation_clicked();

    void on_btn_add_clicked();

    void on_btn_clear_clicked();
    void on_btn_del_clicked();

    void on_btn_update_clicked();

    void on_pushButton_4_clicked();

    void on_btn_new_clicked();

private:
    void updateTable();


private:
    Ui::MainWindow *ui;
    Page_Login m_dlgLogin;
    stuSql *m_ptrStuSql;
    QStringList m_lNames;
    Dlg_AddStu m_dlgAddStu;
};
#endif // MAINWINDOW_H
