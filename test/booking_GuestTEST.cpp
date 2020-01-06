#include "lib/include/gtest/gtest.h"
#include "../header/booking/Guest.hpp"
#include <string>

TEST(Guest, initializationGuestDataUntilWhenHired)
{
    Guest guest(std::string("Ania"), std::string("Kot"), std::string("90090515836"), std::string("ABS123456"));
    nlohmann::json data = {
        {"name", "Ania"},
        {"secondName", "Kot"},
        {"pesel", "90090515836"},
        {"numberIDCard", "ABS123456"}};
    EXPECT_EQ(data, guest.guestData());
}

TEST(Guest, incorectPeselGuestData)
{
    Guest guest(std::string("Ania"), std::string("Kot"), std::string("10090515836"), std::string("ABS123456"));
    nlohmann::json data = {
        {"name", "Ania"},
        {"secondName", "Kot"},
        {"pesel", "90090515836"},
        {"numberIDCard", "ABS123456"}};
    EXPECT_EQ(std::nullopt, guest.guestData());
}

TEST(Guest, incorectNumberIDCardGuestData)
{
    Guest guest(std::string("Ania"), std::string("Kot"), std::string("90090515836"), std::string("ABA123456"));
    nlohmann::json data = {
        {"name", "Ania"},
        {"secondName", "Kot"},
        {"pesel", "90090515836"},
        {"numberIDCard", "ABS123456"}};
    EXPECT_EQ(std::nullopt, guest.guestData());
}

TEST(Guest, incorectNameData)
{
    Guest guest(std::string(""), std::string("Kot"), std::string("90090515836"), std::string("ABA123456"));
    nlohmann::json data = {
        {"name", "Ania"},
        {"secondName", "Kot"},
        {"pesel", "90090515836"},
        {"numberIDCard", "ABS123456"}};
    EXPECT_EQ(std::nullopt, guest.guestData());
}

TEST(Guest, incorectSecondNameGuestData)
{
    Guest guest(std::string("Ania"), std::string(""), std::string("90090515836"), std::string("ABS123456"));
    nlohmann::json data = {
        {"name", "Ania"},
        {"secondName", "Kot"},
        {"pesel", "90090515836"},
        {"numberIDCard", "ABS123456"}};
    EXPECT_EQ(std::nullopt, guest.guestData());
}

TEST(Guest, getDataGuest)
{
    Guest guest(std::string("Ania"), std::string("Kot"), std::string("92071314764"), std::string("ABS123456"));
    nlohmann::json data = {
        {"name", "Ania"},
        {"numberIDCard", "ABS123456"},
        {"pesel", "90090515836"},
        {"secondName", "Kot"},
        {"sinceHired", "2020-01-06"},
        {"untilWhenHired", "2019-12-12"}};
    EXPECT_EQ(guest.getGuestDataWithFile(), data);
}