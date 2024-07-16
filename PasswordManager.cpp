#include "PasswordManager.h"

void PasswordManager::savePassword(const QString& website, const QString& email, const QString& password) {
    QFile file("data.txt");
    if(file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << website << " | " << email << " | " << password << "\n";
    }
    file.close();
}
