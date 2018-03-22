#include <iostream>
#include "stddef.h"
#include <cstring>
#include <string>

#pragma once

using namespace std;

#define CHECKNULL(val)  if (val == NULL) return false;

string HashWrapper(string data);

