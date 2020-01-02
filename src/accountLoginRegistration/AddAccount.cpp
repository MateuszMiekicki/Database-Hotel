#include "../../header/accountLoginRegistration/AddAccount.hpp"
#include "../../header/accountLoginRegistration/AccountRegistration.hpp"
#include "../../lib/nlohmannjson/json.hpp"
#include <fstream>
#include <string>
#include <stdexcept>
#include <filesystem>
#include <iostream>

AddAccount::AddAccount(const AccountRegistration &_account) : account(_account) {}

bool AddAccount::add() const noexcept
{
    if (std::filesystem::exists("user.json"))
    {
        std::ifstream fileJson("user.json");
        nlohmann::json dataWithFile = nullptr;
        try
        {
            fileJson >> dataWithFile;
            if (dataWithFile.find(account.userData["pesel"]) != dataWithFile.end())
            {
                std::cerr << "Account already exists.\n";
                return false;
            }
            else
            {
                std::ofstream writer("user.json", std::ios::in);
                dataWithFile[std::string(account.userData["pesel"])] = account.userData;
                writer << dataWithFile.dump(4);
            }
            return true;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return false;
        }
    }
    else
    {
        std::cerr << "File does not exist.\n";
        std::ofstream writer("user.json");
        nlohmann::json header;
        header[std::string(account.userData["pesel"])] = account.userData;
        writer << header.dump(4);
        return true;
    }
    return false;
}
