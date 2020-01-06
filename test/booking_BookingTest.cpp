#include "lib/include/gtest/gtest.h"
#include "booking/Guest.hpp"
#include "booking/Booking.hpp"
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <filesystem>

namespace
{
bool compareFiles(const std::string &p1, const std::string &p2)
{
    std::ifstream f1(p1, std::ifstream::binary | std::ifstream::ate);
    std::ifstream f2(p2, std::ifstream::binary | std::ifstream::ate);

    if (f1.fail() || f2.fail())
    {
        return false; //file problem
    }

    if (f1.tellg() != f2.tellg())
    {
        return false; //size mismatch
    }

    //seek back to beginning and use std::equal to compare contents
    f1.seekg(0, std::ifstream::beg);
    f2.seekg(0, std::ifstream::beg);
    return std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
                      std::istreambuf_iterator<char>(),
                      std::istreambuf_iterator<char>(f2.rdbuf()));
}
} // namespace

TEST(Booking, bookingGuestWithUntilWhenHired)
{
    if (std::filesystem::exists("guest.json"))
    {
        std::filesystem::remove("guest.json");
    }
    Guest guest(std::string("Ania"), std::string("Kot"), std::string("90090515836"), std::string("ABS123456"));
    Booking(guest, date::year_month_day(date::year(2019), date::month(12), date::day(12)));
    ASSERT_TRUE(compareFiles(std::string("guest.json"), std::string("bookingGuestWithUntilWhenHired.json")));
}

TEST(Booking, addingTheSameGuest)
{
    Guest guest(std::string("Ania"), std::string("Kot"), std::string("90090515836"), std::string("ABS123456"));
    try
    {
        Booking(guest, date::year_month_day(date::year(2019), date::month(12), date::day(12)), date::year_month_day(date::year(2012), date::month(2), date::day(12)));
    }
    catch (const std::exception &e)
    {
        EXPECT_EQ(e.what(), std::string("write failed."));
    }
}

TEST(Booking, bookingGuestWithUntilWhenHiredAndSinceHired)
{
    Guest guest(std::string("Ania"), std::string("Kot"), std::string("90090515836"), std::string("A   B   A   3   0   0   0   0   0"));
    Booking(guest, date::year_month_day(date::year(2019), date::month(12), date::day(12)),date::year_month_day(date::year(2029), date::month(12), date::day(12)));
    ASSERT_TRUE(compareFiles(std::string("guest.json"), std::string("bookingGuestWithUntilWhenHiredAndSinceHired.json")));
}
