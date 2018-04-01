#include "utils.h"
#include "sha256.h"

string HashWrapper(string data) {
	char *hashstr = new char[data.length() + 1];
	strcpy(hashstr, data.c_str());
	string resulthash = SHA256(hashstr);
	delete hashstr;
        return resulthash;
}

string getId(string const& input) {
	return input;
}
