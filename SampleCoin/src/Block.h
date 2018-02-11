#include "stddef.h"
#include <iostream>
#include <vector>

using namespace std;

class Block {
public:

	string previousHash;

	Block(string _previousHash, string _contents) {
		previousHash = _previousHash;
		contents = _contents;
		nonce = 0;
	}
	void CalculateHash();
	string GetHash();

	void MineBlock(uint32_t nDifficulty);

private:
	string contents;
	string hashOfBlock;
    int64_t nonce;
};
