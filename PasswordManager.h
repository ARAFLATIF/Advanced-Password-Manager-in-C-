#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

#include <QString>
#include <QFile>
#include <QTextStream>

class PasswordManager {
public:
    static void savePassword(const QString& website, const QString& email, const QString& password);
};

#endif // PASSWORDMANAGER_H
