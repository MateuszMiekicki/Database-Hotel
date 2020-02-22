#ifndef FileManagement_hpp
#define FileManagement_hpp
#include <filesystem>
#include <string>

class FileManagement final
{
public:
    FileManagement() = default;
    bool creteFile(std::string, std::string conntent = "", std::filesystem::path path = std::filesystem::current_path()) const noexcept;
    bool isFileExist(std::string, std::filesystem::path path = std::filesystem::current_path()) const noexcept;
    bool deleteFile(std::string, std::filesystem::path path = std::filesystem::current_path()) const noexcept;
};
#endif