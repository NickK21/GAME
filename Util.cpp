#include "Util.hpp"
#include <cstdlib>

int RNG(int low, int high) 
{
    return (std::rand() % (high - low + 1)) + low;
}