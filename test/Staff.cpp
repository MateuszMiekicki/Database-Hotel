#include "../gtest/include/gtest/gtest.h"
#include "../header/staff/Staff.hpp"
#include "../header/staff/Permissions.hpp"
#include <string>
#include <optional>
#include <tuple>

TEST(Staff, setMethod_correctDataEmployeeWithPesel)
{
    std::string name("Jan");
    std::string seconddName("Kowalski");
    std::string email("jan.kowalski@gmail.com");
    std::string password("SuperStrongPassword1234");
    std::string pesel("90090515836");
    Staff::Permissions permissions = Staff::Permissions::write;
    Staff::Staff worker;
    worker.set(name, seconddName, email, password, pesel, permissions);
    auto temp = worker.get();
    std::tuple<std::string, std::string, std::string, std::string, std::string, Staff::Permissions> workerData(name, seconddName, email, password, pesel, permissions);
    ASSERT_EQ(temp, workerData);
}

TEST(Staff, setMethod_correctDataEmployeeWithIDNumber)
{
    std::string name("Jan");
    std::string seconddName("Kowalski");
    std::string email("jan.kowalski@gmail.com");
    std::string password("SuperStrongPassword1234");
    std::string IDNumber("ABS123456");
    Staff::Permissions permissions = Staff::Permissions::write;
    Staff::Staff worker;
    worker.set(name, seconddName, email, password, IDNumber, permissions);
    auto temp = worker.get();
    std::tuple<std::string, std::string, std::string, std::string, std::string, Staff::Permissions> workerData(name, seconddName, email, password, IDNumber, permissions);
    ASSERT_EQ(temp, workerData);
}

TEST(Staff, setMethod_constructor_emptyName)
{
    std::string name("");
    std::string seconddName("Kowalski");
    std::string email("jan.kowalski@gmail.com");
    std::string password("SuperStrongPassword1234");
    std::string IDNumber("ABS123456");
    Staff::Permissions permissions = Staff::Permissions::write;
    Staff::Staff worker;
    worker.set(name, seconddName, email, password, IDNumber, permissions);
    auto temp = worker.get();
    std::tuple<std::string, std::string, std::string, std::string, std::string, Staff::Permissions> workerData(name, seconddName, email, password, IDNumber, permissions);
    EXPECT_EQ(temp, std::nullopt);
}

TEST(Staff, setMethod_constructor_emptySecondName)
{
    std::string name("Jan");
    std::string seconddName("");
    std::string email("jan.kowalski@gmail.com");
    std::string password("SuperStrongPassword1234");
    std::string IDNumber("ABS123456");
    Staff::Permissions permissions = Staff::Permissions::write;
    Staff::Staff worker;
    worker.set(name, seconddName, email, password, IDNumber, permissions);
    auto temp = worker.get();
    std::tuple<std::string, std::string, std::string, std::string, std::string, Staff::Permissions> workerData(name, seconddName, email, password, IDNumber, permissions);
    EXPECT_EQ(temp, std::nullopt);
}

TEST(Staff, setMethod_constructor_emptyEmail)
{
    std::string name("Jan");
    std::string seconddName("Kowalski");
    std::string email("");
    std::string password("SuperStrongPassword1234");
    std::string IDNumber("ABS123456");
    Staff::Permissions permissions = Staff::Permissions::write;
    Staff::Staff worker;
    worker.set(name, seconddName, email, password, IDNumber, permissions);
    auto temp = worker.get();
    std::tuple<std::string, std::string, std::string, std::string, std::string, Staff::Permissions> workerData(name, seconddName, email, password, IDNumber, permissions);
    EXPECT_EQ(temp, std::nullopt);
}

TEST(Staff, setMethod_constructor_wrongEmail)
{
    std::string name("Jan");
    std::string seconddName("Kowalski");
    std::string email("jan.kowalskigmail.com");
    std::string password("SuperStrongPassword1234");
    std::string IDNumber("ABS123456");
    Staff::Permissions permissions = Staff::Permissions::write;
    Staff::Staff worker;
    worker.set(name, seconddName, email, password, IDNumber, permissions);
    auto temp = worker.get();
    std::tuple<std::string, std::string, std::string, std::string, std::string, Staff::Permissions> workerData(name, seconddName, email, password, IDNumber, permissions);
    EXPECT_EQ(temp, std::nullopt);
}

TEST(Staff, setMethod_constructor_wrongPassword)
{
    std::string name("Jan");
    std::string seconddName("Kowalski");
    std::string email("jan.kowalski@gmail.com");
    std::string password("Su");
    std::string IDNumber("ABS123456");
    Staff::Permissions permissions = Staff::Permissions::write;
    Staff::Staff worker;
    worker.set(name, seconddName, email, password, IDNumber, permissions);
    auto temp = worker.get();
    std::tuple<std::string, std::string, std::string, std::string, std::string, Staff::Permissions> workerData(name, seconddName, email, password, IDNumber, permissions);
    EXPECT_EQ(temp, std::nullopt);
}

TEST(Staff, setMethod_constructor_emptyPassword)
{
    std::string name("Jan");
    std::string seconddName("Kowalski");
    std::string email("jan.kowalski@gmail.com");
    std::string password("");
    std::string IDNumber("ABS123456");
    Staff::Permissions permissions = Staff::Permissions::write;
    Staff::Staff worker;
    worker.set(name, seconddName, email, password, IDNumber, permissions);
    auto temp = worker.get();
    std::tuple<std::string, std::string, std::string, std::string, std::string, Staff::Permissions> workerData(name, seconddName, email, password, IDNumber, permissions);
    EXPECT_EQ(temp, std::nullopt);
}

TEST(Staff, setMethod_constructor_wrongIDNumber)
{
    std::string name("Jan");
    std::string seconddName("Kowalski");
    std::string email("jan.kowalski@gmail.com");
    std::string password("SuperStrongPassword1234");
    std::string IDNumber("BS123456");
    Staff::Permissions permissions = Staff::Permissions::write;
    Staff::Staff worker;
    worker.set(name, seconddName, email, password, IDNumber, permissions);
    auto temp = worker.get();
    std::tuple<std::string, std::string, std::string, std::string, std::string, Staff::Permissions> workerData(name, seconddName, email, password, IDNumber, permissions);
    EXPECT_EQ(temp, std::nullopt);
}

TEST(Staff, setMethod_constructor_emptyIDNumber)
{
    std::string name("Jan");
    std::string seconddName("Kowalski");
    std::string email("jan.kowalski@gmail.com");
    std::string password("SuperStrongPassword1234");
    std::string IDNumber("");
    Staff::Permissions permissions = Staff::Permissions::write;
    Staff::Staff worker;
    worker.set(name, seconddName, email, password, IDNumber, permissions);
    auto temp = worker.get();
    std::tuple<std::string, std::string, std::string, std::string, std::string, Staff::Permissions> workerData(name, seconddName, email, password, IDNumber, permissions);
    EXPECT_EQ(temp, std::nullopt);
}

TEST(Staff, setMethod_constructor_wrongPesel)
{
    std::string name("Jan");
    std::string seconddName("Kowalski");
    std::string email("jan.kowalski@gmail.com");
    std::string password("SuperStrongPassword1234");
    std::string pesel("9009051583");
    Staff::Permissions permissions = Staff::Permissions::write;
    Staff::Staff worker;
    worker.set(name, seconddName, email, password, pesel, permissions);
    auto temp = worker.get();
    std::tuple<std::string, std::string, std::string, std::string, std::string, Staff::Permissions> workerData(name, seconddName, email, password, pesel, permissions);
    EXPECT_EQ(temp, std::nullopt);
}

TEST(Staff, setMethod_constructor_emptyPesel)
{
    std::string name("Jan");
    std::string seconddName("Kowalski");
    std::string email("jan.kowalski@gmail.com");
    std::string password("SuperStrongPassword1234");
    std::string pesel("");
    Staff::Permissions permissions = Staff::Permissions::write;
    Staff::Staff worker;
    worker.set(name, seconddName, email, password, pesel, permissions);
    auto temp = worker.get();
    std::tuple<std::string, std::string, std::string, std::string, std::string, Staff::Permissions> workerData(name, seconddName, email, password, pesel, permissions);
    EXPECT_EQ(temp, std::nullopt);
}