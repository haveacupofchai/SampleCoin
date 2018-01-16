#include "Block.h"
#include "sha256.h"
#include <cstring>

void Block::CalculateHash() {
	char *cstr = new char[contents.length() + 1];
	strcpy(cstr, contents.c_str());
	string contentsHash = SHA256(cstr);
	delete cstr;

	string addedData = previousHash + contentsHash;

	char *hashstr = new char[addedData.length() + 1];
	strcpy(hashstr, addedData.c_str());
	hashOfBlock = SHA256(hashstr);
	delete hashstr;
}

string Block::GetHash() {
	return hashOfBlock;
}
