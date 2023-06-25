#include <string>
#include <filesystem>
#include <windows.h>

void Init() {
    std::string folder = ".\\dllmods";
    for (auto &file : std::filesystem::directory_iterator(folder))
      LoadLibrary(file.path().relative_path().string().c_str());
}