#include "errorMessage.hpp"

void errorMessage(const char* msg)
{
    std::cerr << msg << "\nError: " << SDL_GetError() << std::endl;
}