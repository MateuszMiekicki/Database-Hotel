#ifndef Database_hpp
#define Database_hpp

namespace Database
{
class Database
{
public:
    virtual bool connect() noexcept = 0;
    virtual bool disconnect() noexcept = 0;
    virtual bool request() noexcept = 0;
    ~Database() {}
};
} // namespace Database

#endif