#ifndef JSON_hpp
#define JSON_hpp
#include "Database.hpp"

namespace Database
{
class JSON : public Database
{
public:
    virtual bool connect() noexcept override;
    virtual bool disconnect() noexcept override;
    virtual bool request() noexcept override;
    ~JSON() {}
};
} // namespace Database

#endif