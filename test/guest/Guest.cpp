#include <optional>
#include <tuple>
#include "../gtest/include/gtest/gtest.h"
#include "../../header/guest/Guest.hpp"

TEST(Guest, constructor_correctDataGuest_1)
{
    std::string name("Jan");
    std::string secondName("Kowalski");
    std::string email("jan.kowalski@gmail.com");
    std::tuple<std::string_view, 
                std::string_view, 
                std::string_view> expectedData = std::make_tuple(name, 
                                                                secondName, 
                                                                email);
    Guest::Guest guest(name, secondName, email);
    auto temp = guest.get();
    EXPECT_EQ(temp, expectedData);
}

TEST(Guest, constructor_correctDataGuest_2)
{
    std::string name("Karol");
    std::string secondName("Matejczyk");
    std::string email("matejczyk@wp.pl");
    std::tuple<std::string_view, 
                std::string_view, 
                std::string_view> expectedData = std::make_tuple(name, 
                                                                secondName, 
                                                                email);
    Guest::Guest guest(name, secondName, email);
    auto temp = guest.get();
    EXPECT_EQ(temp, expectedData);
}


TEST(Guest, constructor_emptyName)
{
    std::string name("");
    std::string secondName("Kowalski");
    std::string email("jan.kowalski@gmail.com");
    try
    {
        Guest::Guest guest(name, secondName, email);
    }
    catch (const std::invalid_argument &e)
    {
        EXPECT_EQ(e.what(),
                  std::string("Setting up guest data: "
                                "check the correctness of the data entered."));
    }
}

TEST(Guest, constructor_emptySecondName)
{
    std::string name("Jan");
    std::string secondName("");
    std::string email("jan.kowalski@gmail.com");
    try
    {
        Guest::Guest guest(name, secondName, email);
    }
    catch (const std::invalid_argument &e)
    {
        EXPECT_EQ(e.what(),
                  std::string("Setting up guest data: "
                                "check the correctness of the data entered."));
    }
}

TEST(Guest, constructor_emptyEmail)
{
    std::string name("Jan");
    std::string secondName("Kowalski");
    std::string email("");
    try
    {
        Guest::Guest guest(name, secondName, email);
    }
    catch (const std::invalid_argument &e)
    {
        EXPECT_EQ(e.what(),
                  std::string("Setting up guest data: "
                                "check the correctness of the data entered."));
    }
}

TEST(Guest, constructor_wrongEmail)
{
    std::string name("Jan");
    std::string secondName("Kowalski");
    std::string email("jan.kowalski@gmailcom");
    try
    {
        Guest::Guest guest(name, secondName, email);
    }
    catch (const std::invalid_argument &e)
    {
        EXPECT_EQ(e.what(),
                  std::string("Setting up guest data: "
                                "check the correctness of the data entered."));
    }
}