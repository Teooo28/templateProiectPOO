#include "ExceptiiCustom.h"

EroareDateInvalide::EroareDateInvalide(const std::string& mesaj) 
    : std::logic_error(mesaj) {}

EroareCapacitate::EroareCapacitate(const std::string& mesaj) 
    : std::logic_error(mesaj) {}

EroareIdInexistent::EroareIdInexistent(const std::string& mesaj) 
    : std::runtime_error(mesaj) {}