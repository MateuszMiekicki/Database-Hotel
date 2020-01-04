#ifndef _GUEST_HPP_
#define _GUEST_HPP_
#include <string>
#include <utility>

class Guest
{
private:
    std::string name;
    std::string secondName;
    std::string pesel;
    std::string numberIDCard;

public:
    explicit Guest(const std::string &, const std::string &, const std::string &, const std::string &);
};

#endif