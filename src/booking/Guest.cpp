#include "../../header/booking/Guest.hpp"
#include "../../header/dataValidate/IDCardValidation.hpp"
#include "../../header/dataValidate/PeselValidation.hpp"
#include "../../lib/nlohmannjson/json.hpp"
#include "../../lib/date/date.h"
#include <optional>
#include <sstream>
#include <iostream>
#include <fstream>
#include <filesystem>

Guest::Guest(const std::string &_name, const std::string &_secondName, const std::string &_pesel, const std::string &_numberIDCard) : name{_name},
                                                                                                                                      secondName{_secondName},
                                                                                                                                      pesel{_pesel},
                                                                                                                                      numberIDCard{_numberIDCard} {}

std::optional<nlohmann::json> Guest::guestData() const
{
    if (name.size() < 2 || secondName.size() < 2 || !PeselValidation::validated(pesel) || !IDCardValidation::validated(numberIDCard))
        return std::nullopt;
    std::string temp = numberIDCard;
    temp.erase(std::remove(temp.begin(), temp.end(), ' '), temp.end());
    nlohmann::json data = {
        {"name", name},
        {"secondName", secondName},
        {"pesel", pesel},
        {"numberIDCard", temp}};
    return data;
}

std::optional<nlohmann::json> Guest::getGuestDataWithFile() const
{
    if (std::filesystem::exists("guest.json"))
    {
        std::ifstream fileJson("guest.json");
        nlohmann::json dataWithFile = nullptr;
        try
        {
            fileJson >> dataWithFile;
            if (dataWithFile.find(numberIDCard) != dataWithFile.end())
            {
                nlohmann::json guest = dataWithFile[numberIDCard];
                return guest;
            }
            else
            {
                return std::nullopt;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return std::nullopt;
        }
    }
    else
    {
        return std::nullopt;
    }
}

std::optional<nlohmann::json> Guest::getGuestDataWithFile(const std::string &_numberIDCard)
{
    if (std::filesystem::exists("guest.json"))
    {
        std::ifstream fileJson("guest.json");
        nlohmann::json dataWithFile = nullptr;
        try
        {
            fileJson >> dataWithFile;
            if (dataWithFile.find(_numberIDCard) != dataWithFile.end())
            {
                nlohmann::json guest = dataWithFile[_numberIDCard];
                return guest;
            }
            else
            {
                return std::nullopt;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return std::nullopt;
        }
    }
    else
    {
        return std::nullopt;
    }
}