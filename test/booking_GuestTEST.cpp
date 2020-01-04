#include "lib/include/gtest/gtest.h"
#include "booking/Guest.hpp"
#include <string>
#include <chrono>
#include "../lib/date/date.h"
TEST(Guest, initializationGuestDataUntilWhenHired)
{
    Guest guest(std::string("Ania"), std::string("Kot"), std::string("90090515836"), std::string("ABS123456"), date::year_month_day(date::year(2022), date::month(12), date::day(12)));
    std::stringstream tempStream;
    date::year_month_day temp = date::floor<date::days>(std::chrono::system_clock::now());
    tempStream << temp;
    nlohmann::json data = {
        {"name", "Ania"},
        {"secondName", "Kot"},
        {"pesel", "90090515836"},
        {"numberIDCard", "ABS123456"},
        {"sinceHired", tempStream.str()},
        {"untilWhenHired", "2022-12-12"}};
    EXPECT_EQ(data, guest.guestData());
}

TEST(Guest, initializationGuestDataSinceHiredUntilWhenHired)
{
    Guest guest(std::string("Ania"), std::string("Kot"), std::string("90090515836"), std::string("ABS123456"), date::year_month_day(date::year(2019), date::month(12), date::day(12)), date::year_month_day(date::year(2022), date::month(12), date::day(12)));
    nlohmann::json data = {
        {"name", "Ania"},
        {"secondName", "Kot"},
        {"pesel", "90090515836"},
        {"numberIDCard", "ABS123456"},
        {"sinceHired", "2019-12-12"},
        {"untilWhenHired", "2022-12-12"}};
    EXPECT_EQ(data, guest.guestData());
}

TEST(Guest, incorectPeselGuestData)
{
    Guest guest(std::string("Ania"), std::string("Kot"), std::string("10090515836"), std::string("ABS123456"), date::year_month_day(date::year(2022), date::month(12), date::day(12)));
    nlohmann::json data = {
        {"name", "Ania"},
        {"secondName", "Kot"},
        {"pesel", "90090515836"},
        {"numberIDCard", "ABS123456"}};
    EXPECT_EQ(std::nullopt, guest.guestData());
}

TEST(Guest, incorectNumberIDCardGuestData)
{
    Guest guest(std::string("Ania"), std::string("Kot"), std::string("90090515836"), std::string("ABA123456"), date::year_month_day(date::year(2022), date::month(12), date::day(12)));
    nlohmann::json data = {
        {"name", "Ania"},
        {"secondName", "Kot"},
        {"pesel", "90090515836"},
        {"numberIDCard", "ABS123456"}};
    EXPECT_EQ(std::nullopt, guest.guestData());
}

TEST(Guest, incorectNameData)
{
    Guest guest(std::string(""), std::string("Kot"), std::string("90090515836"), std::string("ABA123456"), date::year_month_day(date::year(2022), date::month(12), date::day(12)));
    nlohmann::json data = {
        {"name", "Ania"},
        {"secondName", "Kot"},
        {"pesel", "90090515836"},
        {"numberIDCard", "ABS123456"}};
    EXPECT_EQ(std::nullopt, guest.guestData());
}

TEST(Guest, incorectSecondNameGuestData)
{
    Guest guest(std::string("Ania"), std::string(""), std::string("90090515836"), std::string("ABS123456"), date::year_month_day(date::year(2022), date::month(12), date::day(12)));
    nlohmann::json data = {
        {"name", "Ania"},
        {"secondName", "Kot"},
        {"pesel", "90090515836"},
        {"numberIDCard", "ABS123456"}};
    EXPECT_EQ(std::nullopt, guest.guestData());
}