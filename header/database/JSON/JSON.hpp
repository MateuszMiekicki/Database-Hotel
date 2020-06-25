#ifndef JSON_hpp
#define JSON_hpp

namespace Database
{
    class JSON
    {
    public:
        JSON() = default;
        explicit JSON(std::string_view);
        void connect(std::string_view);
        nlohmann::json getDataWithDB() const noexcept;
        std::optional<nlohmann::json> find(const std::string &) const noexcept;
        bool disconnect() noexcept;
        ~JSON();
        bool operator==(const JSON &objectToCompare) const noexcept;
        bool operator==(const nlohmann::json &objectToCompare) const
                                                               noexcept;

    private:
        std::pair<std::fstream, nlohmann::json> session;
    };
} // namespace Database

#endif