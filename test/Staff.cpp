#include "gtest/include/gtest/gtest.h"
#include "../header/staff/Staff.hpp"
#include <string>
#include <optional>
#include <tuple>

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
    worker.set(name, seconddName, IDNumber);
    auto temp = worker.get();
    std::tuple<std::string, 
                std::string, 
                std::string> workerData(name, seconddName, IDNumber);
    EXPECT_EQ(temp, std::nullopt);
}

TEST(Staff, setMethodEmptySecondName)
{
    std::string name("Jan");
    std::string seconddName("");
    std::string IDNumber("ABS123456");
    Staff::Staff worker;
    worker.set(name, seconddName, IDNumber);
    auto temp = worker.get();
    std::tuple<std::string, 
                std::string, 
                std::string> workerData(name, seconddName, IDNumber);
    EXPECT_EQ(temp, std::nullopt);
}

TEST(Staff, setMethodWrongIDNumber)
{
    std::string name("Jan");
    std::string seconddName("Kowalski");
    std::string IDNumber("BS123456");
    Staff::Staff worker;
    worker.set(name, seconddName, IDNumber);
    auto temp = worker.get();
    std::tuple<std::string, 
                std::string, 
                std::string> workerData(name, seconddName, IDNumber);
    EXPECT_EQ(temp, std::nullopt);
}

TEST(Staff, setMethodEmptyIDNumber)
{
    std::string name("Jan");
    std::string seconddName("Kowalski");
    std::string IDNumber("");
    Staff::Staff worker;
    worker.set(name, seconddName, IDNumber);
    auto temp = worker.get();
    std::tuple<std::string, 
                std::string, 
                std::string> workerData(name, seconddName, IDNumber);
    EXPECT_EQ(temp, std::nullopt);
}

TEST(Staff, setMethodWrongPesel)
{
    std::string name("Jan");
    std::string seconddName("Kowalski");
    std::string pesel("9009051583");
    Staff::Staff worker;
    worker.set(name, seconddName, pesel);
    auto temp = worker.get();
    std::tuple<std::string, 
                std::string, 
                std::string> workerData(name, seconddName, pesel);
    EXPECT_EQ(temp, std::nullopt);
}

TEST(Staff, setMethodEmptyPesel)
{
    std::string name("Jan");
    std::string seconddName("Kowalski");
    std::string pesel("");
    Staff::Staff worker;
    worker.set(name, seconddName, pesel);
    auto temp = worker.get();
    std::tuple<std::string, 
                std::string, 
                std::string> workerData(name, seconddName, pesel);
    EXPECT_EQ(temp, std::nullopt);
}