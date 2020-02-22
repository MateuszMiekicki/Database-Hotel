#include <filesystem>
#include <string>
#include <fstream>
#include "FileManagement.hpp"

bool FileManagement::creteFile(std::string fileNameWithExtension, std::string conntent, std::filesystem::path path) const noexcept
{
    try
    {
        if (isFileExist(std::string(path.generic_string() + '/' + fileNameWithExtension)))
            return false;
        else
        {
            std::ofstream file(fileNameWithExtension);
            file << conntent;
        }
    }
    catch (...)
    {
        return false;
    }
    return true;
}

bool FileManagement::isFileExist(std::string fileNameWithExtension, std::filesystem::path path) const noexcept
{
    return std::filesystem::exists(path.generic_string() + '/' + fileNameWithExtension) ? true : false;
}

bool FileManagement::deleteFile(std::string fileNameWithExtension, std::filesystem::path path) const noexcept
{
    try
    {
        std::filesystem::remove(path.generic_string() + '/' + fileNameWithExtension);
        return true;
    }
    catch (...)
    {
        return false;
    }
}