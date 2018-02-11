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
		time_t rawtime;
		struct tm * ptm;
		time ( &rawtime );
		ptm = gmtime ( &rawtime );
		strftime(timestamp,ts_length,"%c",ptm);
	}
	void CalculateHash();
	string GetHash();

	void MineBlock(uint32_t nDifficulty);

private:

	static const int ts_length = 30;
	string contents;
    char timestamp[ts_length];
	string hashOfBlock;
    int64_t nonce;

    int GetBlockLength();

};
