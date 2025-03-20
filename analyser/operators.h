#pragma once

#include "token.h"
#include <unordered_map>
#include <string>

// Declare the map as extern to avoid multiple definitions
extern const std::unordered_map<std::string, TokenType> operators;