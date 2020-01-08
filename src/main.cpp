#include <numeric>
#include <iostream>
#include <limits>
#include <string>
#include "../header/accountLoginRegistration/AccountLogin.hpp"
#include "../header/accountLoginRegistration/AccountRegistration.hpp"
#include "../header/accountLoginRegistration/AddAccount.hpp"
#include "../header/accountLoginRegistration/Permissions.hpp"
#include "../header/booking/Guest.hpp"
#include "../header/booking/Booking.hpp"
#include "../lib/date/date.h"

namespace
{
void clearBufferIOStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
int menuLoginRegister()
{
    std::cout << "1. Log in." << '\n';
    std::cout << "2. Register." << '\n';
    std::cout << "3. Exit." << '\n';
    int choice{1};
    while (!std::cin.operator>>(choice))
    {
        clearBufferIOStream();
    }
    return choice;
}
int menuGuestLoginRegister()
{
    std::cout << "1. Booking." << '\n';
    std::cout << "2. Check the information." << '\n';
    std::cout << "3. Check out." << '\n';
    std::cout << "4. Log out." << '\n';
    int choice{1};
    while (!std::cin.operator>>(choice))
    {
        clearBufferIOStream();
    }
    return choice;
}
} // namespace
int main()
{
    Permissions permissionsUser = Permissions::null;
    while (true)
    {
        switch (menuLoginRegister())
        {
        case 1:
        {
            std::cout << "Enter the pesel\n";
            std::string pesel;
            std::cin >> pesel;
            clearBufferIOStream();
            std::cout << "Enter the passwor\n";
            std::string password;
            std::cin >> password;
            clearBufferIOStream();
            AccountLogin account(pesel, password);
            if (auto loginStatus = account.login(); loginStatus)
            {
                permissionsUser = loginStatus.value();
                goto exit_loop;
            }
            else
            {
                std::cout << "Unfortunately, you gave the wrong data\n";
            }
        }
        break;
        case 2:
        {
            try
            {
                std::cout << "Entry name: ";
                std::string name;
                std::cin >> name;
                clearBufferIOStream();
                std::cout << "Entry second name: ";
                std::string secondName;
                std::cin >> secondName;
                clearBufferIOStream();
                std::cout << "Entry pesel: ";
                std::string pesel;
                std::cin >> pesel;
                clearBufferIOStream();
                std::cout << "Entry password: ";
                std::string password;
                std::cin >> password;
                clearBufferIOStream();
                std::cout << "Entry email: ";
                std::string email;
                std::cin >> email;
                clearBufferIOStream();
                std::cout << "Entry permission: ";
                unsigned permission{0};
                std::cin >> permission;
                clearBufferIOStream();
                AccountRegistration newAccount(name, secondName, pesel, email, password, static_cast<Permissions>(permission));
                AddAccount add(newAccount);
                add.add();
                break;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        break;
        case 3:
        {
            return 0;
        }
        break;
        default:
            std::cout << "Unfortunately, there is no such option.\n";
            break;
        }
    }
exit_loop:;
    while (true)
    {
        switch (menuGuestLoginRegister())
        {
        case 1:
        {
            std::cout << "Booking.\n";
            std::cout << "Name: ";
            std::string name;
            std::cin >> name;
            clearBufferIOStream();
            std::cout << "Second name: ";
            std::string secondName;
            std::cin >> secondName;
            clearBufferIOStream();
            std::cout << "Pesel: ";
            std::string pesel;
            std::cin >> pesel;
            clearBufferIOStream();
            std::cout << "Number ID card: ";
            std::string numberIDCard;
            std::cin >> numberIDCard;
            clearBufferIOStream();
            std::cout << "Enter the date of your arrival day-month-year(leaving the field blank will enter today's date): ";
            std::string date;
            getline(std::cin, date);
            std::cout << "Enter date of departure day-month-year: ";
            std::string dateDeparture;
            std::cin >> dateDeparture;
            try
            {

                if (date.size() == 0)
                {
                    date::day dayDeparture((std::stoi(std::string(dateDeparture.begin(), dateDeparture.begin() + 2))));
                    date::month monthDeparture((std::stoi(std::string(dateDeparture.begin() + 3, dateDeparture.begin() + 5))));
                    date::year yearDeparture((std::stoi(std::string(dateDeparture.begin() + 7, dateDeparture.begin() + 9))));
                    Booking booking(Guest(name, secondName, pesel, numberIDCard), date::year_month_day(yearDeparture, monthDeparture, dayDeparture));
                }
                else
                {
                    date::day dayArrival((std::stoi(std::string(date.begin(), date.begin() + 2))));
                    date::month monthArrival((std::stoi(std::string(date.begin() + 3, date.begin() + 5))));
                    date::year yearArrival((std::stoi(std::string(date.begin() + 7, date.begin() + 9))));
                    date::day dayDeparture((std::stoi(std::string(dateDeparture.begin(), dateDeparture.begin() + 2))));
                    date::month monthDeparture((std::stoi(std::string(dateDeparture.begin() + 3, dateDeparture.begin() + 5))));
                    date::year yearDeparture((std::stoi(std::string(dateDeparture.begin() + 7, dateDeparture.begin() + 9))));
                    Booking booking(Guest(name, secondName, pesel, numberIDCard), date::year_month_day(yearArrival, monthArrival, dayArrival), date::year_month_day(yearDeparture, monthDeparture, dayDeparture));
                }
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        break;
        case 2:
        {
            std::cout << "Entry number id card guest: ";
            std::string numberIDCard;
            std::cin >> numberIDCard;
            clearBufferIOStream();
            if (auto guest = Guest::getGuestDataWithFile(numberIDCard); guest)
            {
                std::cout << guest.value().dump(2);
                std::cout << '\n';
            }
            else
            {
                std::cout << "There is no such visitor.\n";
            }
        }
        break;
        case 3:
        {
            std::cout << "Number ID card: ";
            std::string numberIDCard;
            std::cin >> numberIDCard;
            if(Booking::checkOut(numberIDCard))
                std::cout<<"Ok";

        }
        break;
        case 4:
        {
            return 0;
        }
        break;
        default:
            break;
        }
    }
}