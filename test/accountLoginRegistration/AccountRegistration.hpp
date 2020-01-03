#ifndef _ACCOUNT_REGISTRATION_HPP_
#define _ACCOUNT_REGISTRATION_HPP_
#include <string>
#include "../../lib/nlohmannjson/json.hpp"
#include "Permissions.hpp"

class AccountRegistration
{
public:
    explicit AccountRegistration(const std::string &, const std::string &, const std::string &, const std::string &, const std::string &, Permissions);
    AccountRegistration(const AccountRegistration &);
    AccountRegistration &operator=(const AccountRegistration &);
    nlohmann::json userData = nullptr;
private:
    std::string name{""};
    std::string secondName{""};
    std::string pesel{""};
    std::string email{""};
    std::string password{""};
    Permissions permission = Permissions::null;
    AccountRegistration() = default;
};

#endif