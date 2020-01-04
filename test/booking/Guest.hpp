#ifndef _GUEST_HPP_
#define _GUEST_HPP_
#include <string>
#include <utility>
#include <optional>
#include "../../lib/nlohmannjson/json.hpp"
#include "../../lib/date/date.h"

class Guest
{
private:
    const std::string name;
    const std::string secondName;
    const std::string pesel;
    const std::string numberIDCard;
    date::year_month_day sinceHired;
    date::year_month_day untilWhenHired;

public:
    explicit Guest(const std::string &, const std::string &, const std::string &, const std::string &, const date::year_month_day &);
    explicit Guest(const std::string &, const std::string &, const std::string &, const std::string &, const date::year_month_day &, const date::year_month_day &);
    std::optional<nlohmann::json> guestData() const;
};

#endif