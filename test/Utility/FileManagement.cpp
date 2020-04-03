#include <filesystem>
#include <string>
#include <fstream>
#include "FileManagement.hpp"

bool FileManagement::creteFile(std::string fileNameWithExtension,
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
    pathForCretefile.first = path;
    pathForCretefile.second = fileNameWithExtension;
    return true;
}

bool FileManagement::creteFile(std::string fileNameWithExtension,
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
    pathForCretefile.first = path;
    pathForCretefile.second = fileNameWithExtension;
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
    deleteFile(pathForCretefile.second, pathForCretefile.first);
}