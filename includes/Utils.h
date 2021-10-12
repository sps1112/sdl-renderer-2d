#ifndef UTILS_H
#define UTILS_H

// Standard Headers
#include <iostream>
#include <string>

// Prints Character Array
void print_message(const char *message)
{
    std::cout << message;
}

// Prints String
void print_message(std::string message)
{
    print_message(message.c_str());
}

// Logs a Character Array to a Line
void log_message(const char *message)
{
    std::cout << message << std::endl;
}

// Logs a String to a Line
void log_message(std::string message)
{
    log_message(message.c_str());
}

#endif // UTILS_H
