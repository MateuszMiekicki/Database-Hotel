#include "../../header/accountLoginRegistration/AccountRegistration.hpp"
#include "../../header/accountDataValidate/PasswordValidation.hpp"
#include "../../header/accountDataValidate/EmailValidation.hpp"
#include "../../header/accountDataValidate/PeselValidation.hpp"
#include "../../header/accountLoginRegistration/Permissions.hpp"
#include <stdexcept>

AccountRegistration::AccountRegistration(const std::string &_name, const std::string &_secondName, const std::string &_pesel, const std::string &_email, const std::string &_password, Permissions _permission) : name{_name},
                                                                                                                                                                                                                   secondName{_secondName},
                                                                                                                                                                                                                   pesel{_pesel},
                                                                                                                                                                                                                   email(_email),
                                                                                                                                                                                                                   password{_password},
                                                                                                                                                                                                                   permission{_permission}
{
    if (!PeselValidation::validated(pesel))
        throw std::invalid_argument("Invalid pesel.");
    else if (!EmailValidation::validated(email))
        throw std::invalid_argument("Invalid email.");
    else if (!PasswordValidation::validated(password))
        throw std::invalid_argument("Invalid password.");
    userData = {
        {"name", name},
        {"secondName", secondName},
        {"pesel", pesel},
        {"email", email},
        {"password", password},
        {"permissions", permission}};
}

AccountRegistration::AccountRegistration(const AccountRegistration &accountRegistration) : name{accountRegistration.name},
                                                                                           secondName{accountRegistration.secondName},
                                                                                           pesel{accountRegistration.pesel},
                                                                                           email{accountRegistration.email},
                                                                                           password{accountRegistration.password},
                                                                                           permission{accountRegistration.permission}
{
    userData = {
        {"name", accountRegistration.name},
        {"secondName", accountRegistration.secondName},
        {"pesel", accountRegistration.pesel},
        {"email", accountRegistration.email},
        {"password", accountRegistration.password},
        {"permissions", accountRegistration.permission}};
}

AccountRegistration &AccountRegistration::operator=(const AccountRegistration &accountRegistration)
{
    if (&accountRegistration != this)
    {
        name = accountRegistration.name;
        secondName = accountRegistration.secondName;
        pesel = accountRegistration.pesel;
        email = accountRegistration.email;
        password = accountRegistration.password;
        permission = accountRegistration.permission;
    }
    return *this;
}