#pragma once
#include <exception>
#include <string>

class ValoareInvalidaException : public std::exception {
private:
    std::string mesaj;

public:
    ValoareInvalidaException(const std::string& mesajEroare);

    const char* what() const noexcept override;
};