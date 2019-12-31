#ifndef _ACCOUNT_REGISTRATION_HPP_
#define _ACCOUNT_REGISTRATION_HPP_
#include <string>
class AccountRegistration
{
    public:
    enum class Permissions{root = -1, read = 0, write, readWrite};
    explicit AccountRegistration(std::string _name, std::string _secondName, std::string _pesel, std::string email, std::string _password, Permissions _permissions);
    AccountRegistration(const AccountRegistration& accountRegistration);
    AccountRegistration& operator=(const AccountRegistration& accountRegistration);
    private:
    std::string name{""};
    std::string secondName{""};
    std::string pesel{""};
    std::string email{""};
    std::string password{""};
    Permissions permissions = Permissions::read;
};

#endif