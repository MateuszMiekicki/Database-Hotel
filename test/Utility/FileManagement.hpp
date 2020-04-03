#ifndef FileManagement_hpp
#define FileManagement_hpp
#include <filesystem>
#include <string>
#include <utility>
#include <vector>
class FileManagement final
{
public:
    FileManagement() = default;
    bool creteFile(std::string fileNameWithExtension, 
                std::string conntent = "", 
                std::filesystem::path path = std::filesystem::current_path()) 
                                                             noexcept;
    bool creteFile(std::string fileNameWithExtension, 
                std::vector<std::string> conntentContainer, 
                std::filesystem::path path = std::filesystem::current_path()) 
                                                             noexcept;
    bool isFileExist(std::string fileNameWithExtension, 
                std::filesystem::path path = std::filesystem::current_path()) 
                                                            const noexcept;
    bool deleteFile(std::string fileNameWithExtension, 
                std::filesystem::path path = std::filesystem::current_path()) 
                                                            const noexcept;
    ~FileManagement();

private:
    std::pair<std::filesystem::path, std::string> pathForCretefile;
};
#endif