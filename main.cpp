#include "Meniu.h"

int main() {
    Meniu* aplicatie = Meniu::getInstance();
    aplicatie->ruleaza();
    return 0;
}