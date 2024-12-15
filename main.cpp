#include "implementation/exceptions.h"
#include <iostream>

int main() {
    int x = 10;
    MYSTUFF_DEBUG(x == 10);
    MYSTUFF_DEBUG(x == 11);
}
