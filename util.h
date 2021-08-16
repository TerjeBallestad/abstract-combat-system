#include <stdlib.h> 
#include <cstdlib> 

#pragma once

inline float Random() {
    return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}