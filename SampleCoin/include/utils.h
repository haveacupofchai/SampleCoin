#include <iostream>
#include "stddef.h"
#include <cstring>
#include <string>

#pragma once

using namespace std;

#define CHECKNULL(val)  if (val == NULL) return false;

#define GENESIS 0
#define CLICK 1
#define TRANSFER 2

string HashWrapper(string data);
string getId(string const& input);
