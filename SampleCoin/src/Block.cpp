#include "Block.h"
#include "sha256.h"
#include <cstring>

void Block::CalculateHash() {
	char *cstr = new char[GetBlockLength()];
	strcpy(cstr, contents.c_str());
	strcat(cstr,to_string(nonce).c_str());
	strcat(cstr,timestamp);

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

int Block::GetBlockLength()
{
	return contents.length() + sizeof(nonce) + sizeof(timestamp);
}

void Block::MineBlock(uint32_t nDifficulty) {
    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

    string str(cstr);

do {
	nonce++;
    CalculateHash();
} while (GetHash().substr(0, nDifficulty) != str);

cout << "Block mined: " << hashOfBlock << endl;
}
