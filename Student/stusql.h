#ifndef STUSQL_H
#define STUSQL_H

#include <QObject>
#include <QSqlDatabase>

struct StuInfo
{
    int id;
    QString name;
    quint8 age;
    quint16 grade;
    quint16 uiclass;
    quint32 studentid;
    QString phone;
    QString Wechat;
};
struct UserInfo
{
    QString username;
    QString password;
    QString aut;
};

class stuSql : public QObject
{
    Q_OBJECT
public:
    static stuSql *ptrstuSql;
    static stuSql *getinstance()
    {
        if(nullptr == ptrstuSql)
        {
            ptrstuSql = new stuSql;
        }
        return ptrstuSql;
    }
    explicit stuSql(QObject *parent = nullptr);

    void init();

    //查询学生数量
    quint32 getStuCnt();
    //查询第几页学生数据,页数从0开始
    QList<StuInfo> getPageStu(quint32 Page,quint32 uicnt);
    //增加学生
    bool addStu(StuInfo);
    //删除学生
    bool delStu(int id);
    //清空学生表
    bool clearStuTable();
    //修改学生信息
    bool updateStuInfo(StuInfo info);
    //查询所有用户
    QList<UserInfo> getAlluser();
    //查询用户名是否存在
    bool isExit(QString strUser);
    //更新用户信息
    bool updateUser(UserInfo info);
     //添加单个用户
    bool addUser(UserInfo info);
    //删除单个用户
    bool delUser(QString strUserName);
signals:
private:
    QSqlDatabase  m_db;

};


#endif // STUSQL_H
