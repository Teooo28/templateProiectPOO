#include "ExceptiiCustom.h"

ValoareInvalidaException::ValoareInvalidaException(const std::string& mesajEroare) : mesaj(mesajEroare) {
}

const char* ValoareInvalidaException::what() const noexcept {
    return mesaj.c_str();
}