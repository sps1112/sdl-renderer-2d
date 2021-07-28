#ifndef UTILS_H
#define UTILS_H

// Standard Headers
#include <iostream>
#include <string>

// Prints Character Array
void Print(const char *message)
{
    std::cout << message;
}

// Prints String
void Print(std::string message)
{
    Print(message.c_str());
}

// Logs a Character Array to a Line
void Log(const char *message)
{
    std::cout << message << std::endl;
}

// Logs a String to a Line
void Log(std::string message)
{
    Log(message.c_str());
}

#endif // UTILS_H
