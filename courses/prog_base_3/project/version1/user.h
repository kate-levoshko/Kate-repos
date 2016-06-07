#ifndef USER_H
#define USER_H

class user
{
public:
    user();
private:
    char* name;
    char* surname;
    char* phone_number;
    double points;

    char* nickname;
    char* password;
};

#endif // USER_H
