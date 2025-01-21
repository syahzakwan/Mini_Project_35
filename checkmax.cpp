#include "checkmax.hpp"

bool isClassFullyBooked(bool seats[], int totalSeats) {
    for (int i = 0; i < totalSeats; i++) {
        if (!seats[i]) { 
            return false;
        }
    }
    return true; 
}