#include <dbmanager.h>

DbManager::DbManager(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
        qDebug() << "Error: the connection to the database failed";
    }
    else
    {
        qDebug() << "Database: conexion ok";
    }
}

DbManager::~DbManager()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}



bool DbManager::createTable()
{
    bool success = false;

    QSqlQuery query;
    query.prepare("CREATE TABLE login(id INTEGER PRIMARY KEY, username TEXT,password TEXT);");

    if (!query.exec())
    {
        qDebug() << "Could not create table 'login'";
        success = false;
    }

    return success;
}

bool DbManager::addUser(const QString& username,const QString& password)
{
    bool success = false;

    if (!username.isEmpty())
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO login (username, password) "
                      "VALUES (?, ?)");
        queryAdd.bindValue(0,username);
        queryAdd.bindValue(1, password);
        if(queryAdd.exec())
        {
            success = true;
            qDebug() << "Success";
        }
        else
        {
            qDebug() <<"Error adding user:" << queryAdd.lastError();
        }
    }
    else
    {
        qDebug() <<"Error adding user: name cannot be empty";
    }

    return success;
}

bool DbManager::removeUsername(const QString& username)
{
    bool success = false;

   if (userExists(username))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM login WHERE username = (:username)");
        queryDelete.bindValue(":username", username);
        success = queryDelete.exec();

        if(!success)
            qDebug() << "Delete user failure:" << queryDelete.lastError();
        else
            qDebug() << "User successfully deleted" << username;


    }
    else
    {
        qDebug() << "Error deleting user: user does not exist";
    }

    return success;
}

bool DbManager::userExists(const QString& name) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT username FROM login WHERE username = (:username)");
    checkQuery.bindValue(":username", name);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "User not found:" << checkQuery.lastError();
    }

    return exists;
}

bool DbManager::removeAllUsers()
{
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM login");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "Delete all users failed:" << removeQuery.lastError();
    }

    return success;
}
