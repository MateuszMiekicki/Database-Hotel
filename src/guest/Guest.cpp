#include <string_view>
#include <tuple>
#include <optional>
#include <stdexcept>
#include "../../header/guest/Guest.hpp"
#include "../../header/validationDate/ValidationEmail.hpp"

Guest::Guest::Guest(std::string_view name,
                    std::string_view secondName,
                    std::string_view email)
{
    set(name, secondName, email);
}

void Guest::Guest::set(std::string_view name,
                       std::string_view secondName,
                       std::string_view email)
{
    Validation::ValidationEmail validation;
    if (name.size() != 0 &&
        secondName.size() != 0 &&
        validation.validated(email))
    {
        guestData = std::make_tuple(name, secondName, email);
    }
    else
    {
        throw std::invalid_argument("Setting up guest data: "
                                    "check the correctness of the data entered.");
    }
}

std::optional<std::tuple<std::string_view,
                         std::string_view,
                         std::string_view>>
Guest::Guest::get() const noexcept
{
    return guestData;
}
