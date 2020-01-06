#ifndef _ACCOUNT_LOGIN_HPP_
#define _ACCOUNT_LOGIN_HPP_
#include "Permissions.hpp"
#include <string>
#include <optional>

class AccountLogin
{
private:
    const std::string PESEL;
    const std::string PASSWORD;

public:
    AccountLogin(const std::string &, const std::string &);
    Permissions persmission = Permissions::null;
    std::optional<Permissions> login() noexcept;
};

#endif