#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <QString>

class PasswordGenerator {
public:
    static QString generatePassword(int length = 12);
};

#endif // PASSWORDGENERATOR_H
