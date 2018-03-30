#include "Block.h"
void Block::CalculateHashOfBlock() {
	char *cstr = new char[GetBlockLength()];
	strcpy(cstr, contents.c_str());
	strcat(cstr, to_string(nonce).c_str());
	strcat(cstr, timestamp);

	// This is string to char array to string!
	// Can change this to add another HashWrapper that may take in char array
	// as input
	string contentsHash = HashWrapper(string(cstr));
	delete cstr;

	string addedData = previousHash + contentsHash;
	hashOfBlock = HashWrapper(addedData);
}

string Block::GetHash() {
	return hashOfBlock;
}

string Block::GetHashOfFile() {
	return hashOfFileData;
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

    // Calculate Hash of the file data
    // Can do this here or even in the constructor
    hashOfFileData = HashWrapper(contents.c_str());

do {
	nonce++;
    CalculateHashOfBlock();
} while (GetHash().substr(0, nDifficulty) != str);

    cout << "Block mined: " << hashOfBlock << endl;
}
