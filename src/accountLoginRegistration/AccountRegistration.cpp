#include "../../header/accountLoginRegistration/AccountRegistration.hpp"
#include "../../header/accountDataValidate/PasswordValidation.hpp"
#include "../../header/accountDataValidate/EmailValidation.hpp"
#include "../../header/accountDataValidate/PeselValidation.hpp"
#include <stdexcept>

AccountRegistration::AccountRegistration(const std::string &_name, const std::string &_secondName, const std::string &_pesel, const std::string &_email, const std::string &_password, Permissions _permissions) : name{_name},
                                                                                                                                                                                                                   secondName{_secondName},
                                                                                                                                                                                                                   pesel{_pesel},
                                                                                                                                                                                                                   email(_email),
                                                                                                                                                                                                                   password{_password},
                                                                                                                                                                                                                   permissions{_permissions}
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
        {"permissions", permissions}};
}

AccountRegistration::AccountRegistration(const AccountRegistration &accountRegistration) : name{accountRegistration.name},
                                                                                           secondName{accountRegistration.secondName},
                                                                                           pesel{accountRegistration.pesel},
                                                                                           email{accountRegistration.email},
                                                                                           password{accountRegistration.password},
                                                                                           permissions{accountRegistration.permissions}
{
    userData = {
        {"name", accountRegistration.name},
        {"secondName", accountRegistration.secondName},
        {"pesel", accountRegistration.pesel},
        {"email", accountRegistration.email},
        {"password", accountRegistration.password},
        {"permissions", accountRegistration.permissions}};
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
        permissions = accountRegistration.permissions;
    }
    return *this;
}