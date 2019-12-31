#include "../../header/account/AccountRegistration.hpp"
#include "../../header/accountDataValidate/PasswordValidation.hpp"
#include "../../header/accountDataValidate/EmailValidation.hpp"
#include "../../header/accountDataValidate/PeselValidation.hpp"

AccountRegistration::AccountRegistration(std::string _name, std::string _secondName, std::string _pesel, std::string _email, std::string _password, Permissions _permissions):
                                                                                                                                            name{_name},
                                                                                                                                            secondName{_secondName},
                                                                                                                                            pesel{_pesel},
                                                                                                                                            email(_email),
                                                                                                                                            password{_password},
                                                                                                                                            permissions{_permissions}
{
    if(!(PeselValidation::validated(pesel) && EmailValidation::validated(email) && PasswordValidation::validated(password)))
        throw;
}