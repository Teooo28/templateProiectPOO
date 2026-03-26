#pragma once
#include <stdexcept>
#include <string>

class EroareDateInvalide : public std::logic_error {
public:
    EroareDateInvalide(const std::string& mesaj);
};

class EroareCapacitate : public std::logic_error {
public:
    EroareCapacitate(const std::string& mesaj);
};

class EroareIdInexistent : public std::runtime_error {
public:
    EroareIdInexistent(const std::string& mesaj);
};