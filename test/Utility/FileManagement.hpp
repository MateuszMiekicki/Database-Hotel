#ifndef FileManagement_hpp
#define FileManagement_hpp
#include <filesystem>
#include <string>
#include <utility>
#include <vector>
#include <fstream>

namespace Utility
{
    class FileManagement final
    {
    public:
        FileManagement() = default;
        inline bool createFile(std::string fileNameWithExtension,
                               std::string conntent = "",
                               std::filesystem::path path = std::filesystem::current_path()) noexcept;
        inline bool createFile(std::string fileNameWithExtension,
                               std::vector<std::string> conntentContainer,
                               std::filesystem::path path = std::filesystem::current_path()) noexcept;
        inline bool isFileExist(std::string fileNameWithExtension,
                                std::filesystem::path path = std::filesystem::current_path())
            const noexcept;
        inline bool deleteFile(std::string fileNameWithExtension,
                               std::filesystem::path path = std::filesystem::current_path())
            const noexcept;
        inline ~FileManagement();

    private:
        std::vector<std::pair<std::filesystem::path, std::string>> pathToFile;
    };

    bool FileManagement::createFile(std::string fileNameWithExtension,
                                    std::string conntent,
                                    std::filesystem::path path) noexcept
    {
        try
        {
            if (isFileExist(std::string(path.generic_string() +
                                        '\\' +
                                        fileNameWithExtension)))
            {
                return false;
            }
            else
            {
                std::ofstream file(std::string(path.generic_string() +
                                               '\\' +
                                               fileNameWithExtension));
                file << conntent;
            }
        }
        catch (...)
        {
            return false;
        }
        pathToFile.emplace_back(path, fileNameWithExtension);
        return true;
    }

    bool FileManagement::createFile(std::string fileNameWithExtension,
                                    std::vector<std::string> conntentContainer,
                                    std::filesystem::path path) noexcept
    {
        try
        {
            if (isFileExist(std::string(path.generic_string() +
                                        '\\' +
                                        fileNameWithExtension)))
            {
                return false;
            }
            else
            {
                std::ofstream file(std::string(path.generic_string() +
                                               '\\' +
                                               fileNameWithExtension));
                for (const auto &conntent : conntentContainer)
                {
                    file << conntent;
                }
            }
        }
        catch (...)
        {
            return false;
        }
        pathToFile.emplace_back(path, fileNameWithExtension);
        return true;
    }
    bool FileManagement::isFileExist(std::string fileNameWithExtension,
                                     std::filesystem::path path) const noexcept
    {
        return std::filesystem::exists(path.generic_string() +
                                       '\\' + fileNameWithExtension)
                   ? true
                   : false;
    }

    bool FileManagement::deleteFile(std::string fileNameWithExtension,
                                    std::filesystem::path path) const noexcept
    {
        try
        {
            std::filesystem::remove(path.generic_string() + '\\' + fileNameWithExtension);
            return true;
        }
        catch (...)
        {
            return false;
        }
    }

    FileManagement::~FileManagement()
    {
        for (const auto &file : pathToFile)
            deleteFile(file.second, file.first);
    }
} // namespace Utility

#endif