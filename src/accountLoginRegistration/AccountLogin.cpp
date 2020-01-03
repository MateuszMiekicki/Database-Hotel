#include "../../header/accountLoginRegistration/AccountLogin.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include "../../lib/nlohmannjson/json.hpp"

AccountLogin::AccountLogin(const std::string &pesel, const std::string &passowrd) : PESEL{pesel},
                                                                                    PASSWORD{passowrd} {}
bool AccountLogin::login() const noexcept
{
    if (std::filesystem::exists("user.json"))
    {
        std::ifstream fileJson("user.json");
        nlohmann::json dataWithFile = nullptr;
        try
        {
            fileJson >> dataWithFile;
            if (dataWithFile.find(PESEL) != dataWithFile.end())
            {
                std::string passwordWtihFile(dataWithFile[PESEL]["password"]);
                return (passwordWtihFile == PASSWORD) ? true : false;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return false;
}
