#ifndef FILESYSTEM_H
#define FILESYSTEM_H

// Standard Headers
#include <string>
#include <cstdlib>
#include "root_directory.h"

// File System Class
class FileSystem
{
private:
    typedef std::string (*Builder)(const std::string &path);

public:
    // Returns file path from string
    static std::string get_path(const std::string &path)
    {
        static std::string (*pathBuilder)(std::string const &) = get_path_builder();
        return (*pathBuilder)(path);
    }

private:
    static std::string const &get_path_root()
    {
        static char const *envRoot = getenv("LOGL_ROOT_PATH");
        static char const *givenRoot = (envRoot != nullptr ? envRoot : logl_root);
        static std::string root = (givenRoot != nullptr ? givenRoot : "");
        return root;
    }
    static Builder get_path_builder()
    {
        if (get_path_root() != "")
        {
            return &FileSystem::get_path_relative_root;
        }
        else
        {
            return &FileSystem::get_path_relative_binary;
        }
    }
    static std::string get_path_relative_root(const std::string &path)
    {
        return (get_path_root() + std::string("/") + path);
    }
    static std::string get_path_relative_binary(const std::string &path)
    {
        return ("../../../" + path);
    }
};

#endif // !FILESYSTEM_H
