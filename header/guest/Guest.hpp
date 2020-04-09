#ifndef Guest_hpp
#define Guest_hpp

namespace Guest
{
class Guest
{
public:
    Guest() = default;
    explicit Guest(std::string_view, 
                    std::string_view, 
                    std::string_view) noexcept;
    void set(std::string_view, std::string_view, std::string_view) noexcept;
    std::optional<std::tuple<std::string_view,
                             std::string_view,
                             std::string_view>> get() const noexcept;

private:
    std::optional<std::tuple<std::string,
                             std::string,
                             std::string>> guestData = std::nullopt;
};
} // namespace Guest
#endif