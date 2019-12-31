#include "../../header/accountLoginRegistration/AccountRegistration.hpp"
#include "../../header/accountDataValidate/PasswordValidation.hpp"
#include "../../header/accountDataValidate/EmailValidation.hpp"
#include "../../header/accountDataValidate/PeselValidation.hpp"
#include <stdexcept>

AccountRegistration::AccountRegistration(std::string _name, std::string _secondName, std::string _pesel, std::string _email, std::string _password, Permissions _permissions):
                                                                                                                                                                                name{_name},
                                                                                                                                                                                secondName{_secondName},
                                                                                                                                                                                pesel{_pesel},
                                                                                                                                                                                email(_email),
                                                                                                                                                                                password{_password},
                                                                                                                                                                                permissions{_permissions}
{
    if(!PeselValidation::validated(pesel))
        throw std::invalid_argument("Invalid pesel.");
    else if(!EmailValidation::validated(email))
        throw std::invalid_argument("Invalid email.");
    else if(!PasswordValidation::validated(password))
        throw std::invalid_argument("Invalid password.");
}

AccountRegistration::AccountRegistration(const AccountRegistration& accountRegistration):
                                                                                        name{accountRegistration.name},
                                                                                        secondName{accountRegistration.secondName},
                                                                                        pesel{accountRegistration.pesel},
                                                                                        email{accountRegistration.email},
                                                                                        password{accountRegistration.password},
                                                                                        permissions{accountRegistration.permissions}{}

AccountRegistration& AccountRegistration::operator=(const AccountRegistration& accountRegistration)
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