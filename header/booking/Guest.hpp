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

public:
    Guest() = delete;
    explicit Guest(const std::string &, const std::string &, const std::string &, const std::string &);
    std::optional<nlohmann::json> guestData() const;
    std::optional<nlohmann::json> getGuestDataWithFile() const;
    static std::optional<nlohmann::json> getGuestDataWithFile(const std::string&);
};

#endif