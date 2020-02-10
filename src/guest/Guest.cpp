#include "../../header/guest/Guest.hpp"
#include "../../header/validationDate/ValidationEmail.hpp"
#include <string_view>
#include <tuple>
#include <optional>

Guest::Guest::Guest(std::string_view name, std::string_view secondName, std::string_view email) noexcept
{
    Validation::ValidationEmail validation;
    if (name.size() != 0 && secondName.size() != 0 && validation.validated(email))
        guestData = std::make_tuple(name, secondName, email);
    else
        guestData = std::nullopt;
}
std::optional<std::tuple<std::string_view, std::string_view, std::string_view>> Guest::Guest::get() const noexcept
{
    return guestData;
}
