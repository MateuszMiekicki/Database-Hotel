#include <string>
#include <optional>
#include <tuple>
#include "../gtest/include/gtest/gtest.h"
#include "../../header/staff/Staff.hpp"


TEST(Staff, setMethod_correctDataEmployeeWithPesel)
{
    std::string name("Jan");
    std::string seconddName("Kowalski");
    std::string pesel("90090515836");
    Staff::Staff worker;
    worker.set(name, seconddName, pesel);
    auto temp = worker.get();
    std::tuple<std::string, 
                std::string, 
                std::string> workerData(name, seconddName, pesel);
    ASSERT_EQ(temp, workerData);
}

TEST(Staff, setMethod_correctDataEmployeeWithIDNumber)
{
    std::string name("Jan");
    std::string seconddName("Kowalski");
    std::string IDNumber("ABS123456");
    Staff::Staff worker;
    worker.set(name, seconddName, IDNumber);
    auto temp = worker.get();
    std::tuple<std::string, 
                std::string, 
                std::string> workerData(name, seconddName, IDNumber);
    ASSERT_EQ(temp, workerData);
}

TEST(Staff, setMethodEmptyName)
{
    std::string name("");
    std::string seconddName("Kowalski");
    std::string IDNumber("ABS123456");
    Staff::Staff worker;
    try
    {
        worker.set(name, seconddName, IDNumber);
    }
    catch (const std::invalid_argument &e)
    {
        EXPECT_EQ(e.what(),
                  std::string("Setting up staff data: " 
                            "the name must not be empty."));
    }
}

TEST(Staff, setMethodEmptySecondName)
{
    std::string name("Jan");
    std::string seconddName("");
    std::string IDNumber("ABS123456");
    Staff::Staff worker;
    try
    {
        worker.set(name, seconddName, IDNumber);
    }
    catch (const std::invalid_argument &e)
    {
        EXPECT_EQ(e.what(),
                  std::string("Setting up staff data: " 
                            "the second name must not be empty."));
    }
}

TEST(Staff, setMethodWrongIDNumber)
{
    std::string name("Jan");
    std::string seconddName("Kowalski");
    std::string IDNumber("BS123456");
    Staff::Staff worker;
    try
    {
        worker.set(name, seconddName, IDNumber);
    }
    catch (const std::invalid_argument &e)
    {
        EXPECT_EQ(e.what(),
                  std::string("Setting up staff data: "
                            "the wrong identification number (pesel or id) is given."));
    }
}

TEST(Staff, setMethodWrongPesel)
{
    std::string name("Jan");
    std::string seconddName("Kowalski");
    std::string pesel("9009051583");
    Staff::Staff worker;
    try
    {
        worker.set(name, seconddName, pesel);
    }
    catch (const std::invalid_argument &e)
    {
        EXPECT_EQ(e.what(),
                  std::string("Setting up staff data: "
                            "the wrong identification number (pesel or id) is given."));
    }
}