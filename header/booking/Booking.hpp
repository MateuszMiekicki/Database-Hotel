#ifndef _BOOKING_HPP_
#define _BOOKING_HPP_
#include "Guest.hpp"
#include <vector>
#include "../../lib/date/date.h"
#include "../../lib/nlohmannjson/json.hpp"
class Booking
{
private:
public:
    Booking() = delete;
    explicit Booking(const Guest &, const date::year_month_day &);
    explicit Booking(const Guest &, const date::year_month_day &, const date::year_month_day &);
    explicit Booking(const std::vector<Guest> &, const date::year_month_day &);
    explicit Booking(const std::vector<Guest> &, const date::year_month_day &, const date::year_month_day &);
    static bool checkOut(const std::string &);
};

#endif