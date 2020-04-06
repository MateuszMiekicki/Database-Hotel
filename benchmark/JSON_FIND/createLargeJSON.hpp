#include "../../test/Utility/FileManagement.hpp"
#include <random>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>

std::vector<unsigned> randomNumber(std::pair<unsigned, unsigned> bound,
                                   std::size_t howMuch)
{
    std::vector<unsigned> lotto(bound.second);
    std::iota(lotto.begin(), lotto.end(), bound.first);
    std::mt19937 random{std::random_device{}()};

    std::shuffle(lotto.begin(), lotto.end(), random);
    std::vector<unsigned> vectorWithNumberToReturn;
    vectorWithNumberToReturn.reserve(howMuch);
    std::copy_n(lotto.begin(),
                howMuch,
                std::back_inserter(vectorWithNumberToReturn));
    return vectorWithNumberToReturn;
}

std::vector<std::string> fileContent(std::size_t howMuch = 10000)
{
    std::pair<unsigned, unsigned> BOUND(0, howMuch);
    std::vector<std::string> content;
    content.reserve(1 + howMuch + 1); //one sign on each side for the start and stop clamps
    auto randomNumberVec = randomNumber(BOUND, howMuch);
    content.push_back("{");
    for (std::size_t it{0}; it < howMuch; ++it)
    {
        std::string line = "\"" +
                           std::to_string(randomNumberVec.at(it)) +
                           "\"" +
                           ": [\"name\",10,true,\"poland\"],";
        content.push_back(line);
    }
    content.at(howMuch).erase(content.at(howMuch).size() - 1);
    content.push_back("}");
    return content;
}
