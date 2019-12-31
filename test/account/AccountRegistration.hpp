#ifndef _ACCOUNT_REGISTRATION_HPP_
#define _ACCOUNT_REGISTRATION_HPP_
#include <string>
class AccountRegistration
{
    private:
    enum class Permissions{root = -1, read = 0, write, readWrite};
    std::string name{""};
    std::string secondName{""};
    std::string pesel{""};
    std::string email{""};
    std::string password{""};
    Permissions permissions = Permissions::read;
    public:
    explicit AccountRegistration(std::string _name, std::string _secondName, std::string _pesel, std::string email, std::string _password, Permissions _permissions);
    AccountRegistration(const AccountRegistration& accountRegistration)
    {
        name = accountRegistration.name;
        secondName = accountRegistration.secondName;
        pesel = accountRegistration.pesel;
        email = accountRegistration.email;
        password = accountRegistration.password;
        permissions = accountRegistration.permissions;
    }
    AccountRegistration& operator=(const AccountRegistration& accountRegistration)
    {
        if(&accountRegistration != this)
        {
            name = accountRegistration.name;
            secondName = accountRegistration.secondName;
            pesel = accountRegistration.pesel;
            email = accountRegistration.email;
            password = accountRegistration.password;
            permissions = accountRegistration.permissions;
        }
        return *this;
    }
};

#endif