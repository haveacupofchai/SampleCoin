#include "stddef.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <cstring>

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
	void CalculateHashOfBlock();
        string GetHashOfFile();
	string GetHash();

	void MineBlock(uint32_t nDifficulty);

private:

	static const int ts_length = 30;
	string contents;
        int64_t nonce;
        char timestamp[ts_length];
	string hashOfBlock;
	string hashOfFileData;

        int GetBlockLength();

};
