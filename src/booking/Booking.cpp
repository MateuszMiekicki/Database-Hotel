#include "../../header/booking/Booking.hpp"
#include "../../header/booking/Guest.hpp"
#include "../../lib/nlohmannjson/json.hpp"
#include "../../lib/date/date.h"
#include <vector>
#include <sstream>
#include <stdexcept>
#include <string>
#include <filesystem>
#include <algorithm>
#include <fstream>
#include <iostream>
namespace
{
bool saveBooking(const nlohmann::json &data)
{
    if (std::filesystem::exists("guest.json"))
    {
        std::ifstream fileJson("guest.json");
        nlohmann::json dataWithFile = nullptr;
        try
        {
            fileJson >> dataWithFile;
            if (dataWithFile.find(data["numberIDCard"]) != dataWithFile.end())
            {
                std::cerr << "Account already exists.\n";
                return false;
            }
            else
            {
                std::ofstream writer("guest.json", std::ios::in);
                dataWithFile[std::string(data["numberIDCard"])] = data;
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
        std::ofstream writer("guest.json");
        nlohmann::json header;
        header[std::string(data["numberIDCard"])] = data;
        writer << header.dump(4);
        return true;
    }
}
} // namespace
Booking::Booking(const Guest &guest, const date::year_month_day &untilWhenHired)
{
    using namespace date;
    if (guest.guestData() == std::nullopt)
        throw std::invalid_argument("Data user is incorect.");
    nlohmann::json guestData = guest.guestData().value();
    auto today = date::floor<date::days>(std::chrono::system_clock::now());
    std::stringstream todayStream;
    todayStream << today;
    std::stringstream untilWhenHiredStream;
    untilWhenHiredStream << untilWhenHired;
    nlohmann::json data = {
        {"name", guestData["name"]},
        {"secondName", guestData["secondName"]},
        {"pesel", guestData["pesel"]},
        {"numberIDCard", guestData["numberIDCard"]},
        {"sinceHired", todayStream.str()},
        {"untilWhenHired", untilWhenHiredStream.str()}};
    if(!saveBooking(data))
        throw std::runtime_error("write failed.");
}
Booking::Booking(const Guest &guest, const date::year_month_day &sinceHired, const date::year_month_day &untilWhenHired)
{
    using namespace date;
    if (guest.guestData() == std::nullopt)
        throw std::invalid_argument("Data user is incorect.");
    nlohmann::json guestData = guest.guestData().value();
    std::stringstream sinceHiredStream;
    sinceHiredStream << sinceHired;
    std::stringstream untilWhenHiredStream;
    untilWhenHiredStream << untilWhenHired;
    nlohmann::json data = {
        {"name", guestData["name"]},
        {"secondName", guestData["secondName"]},
        {"pesel", guestData["pesel"]},
        {"numberIDCard", guestData["numberIDCard"]},
        {"sinceHired", sinceHiredStream.str()},
        {"untilWhenHired", untilWhenHiredStream.str()}};
    if(!saveBooking(data))
        throw std::runtime_error("write failed.");
}
Booking::Booking(const std::vector<Guest> &guests, const date::year_month_day &untilWhenHired) {}
Booking::Booking(const std::vector<Guest> &guests, const date::year_month_day &sinceHired, const date::year_month_day &untilWhenHired) {}