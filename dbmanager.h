#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

/**
 * \class DbManager
 *
 * \brief SQL Database Manager class
 *
 * DbManager sets up the connection with SQL database
 * and performs some basics queries. The class requires
 * existing SQL database. You can create it with sqlite:
 * 1. $ sqlite3 people.db
 * 2. sqilte> CREATE TABLE people(ids integer primary key, name text);
 * 3. sqlite> .quit
 */
class DbManager
{
public:
    /**
     * @brief Constructor
     *
     * Constructor sets up connection with db and opens it
     * @param path - absolute path to db file
     */
    DbManager(const QString& path);

    /**
     * @brief Destructor
     *
     * Close the db connection
     */
    ~DbManager();

    bool isOpen() const;

    /**
     * @brief Creates a new 'people' table if it doesn't already exist
     * @return true - 'people' table created successfully, false - table not created
     */
    bool createTable();

    /**
     * @brief Add person data to db
     * @param name - name of person to add
     * @return true - person added successfully, false - person not added
     */
    bool addUser(const QString& username,const QString& password);

    /**
     * @brief Remove person data from db
     * @param name - name of person to remove.
     * @return true - person removed successfully, false - person not removed
     */
    bool removeUsername(const QString& username);

    /**
     * @brief Check if person of name "name" exists in db
     * @param name - name of person to check.
     * @return true - person exists, false - person does not exist
     */
    bool userExists(const QString& name) const;


    /**
     * @brief Remove all persons from db
     * @return true - all persons removed successfully, false - not removed
     */
    bool removeAllUsers();

private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
