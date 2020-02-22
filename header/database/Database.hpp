#ifndef Database_hpp
#define Database_hpp

namespace Database
{
class Database
{
public:
    virtual bool connect(std::string_view) noexcept = 0;
    virtual bool disconnect() noexcept = 0;
    virtual ~Database(){};
};
} // namespace Database

#endif