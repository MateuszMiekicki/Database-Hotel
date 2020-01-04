#ifndef _ADD_ACCOUNT_HPP_
#define _ADD_ACCOUNT_HPP_
#include "AccountRegistration.hpp"

class AddAccount
{
private:
    const AccountRegistration account;

public:
    explicit AddAccount(const AccountRegistration &);
    bool add() const noexcept;
};

#endif