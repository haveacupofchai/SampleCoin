#include "stddef.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Block {
public:

	string previousHash;

	Block(string _previousHash, string _from, string _to,
		       string _contents, int opcode) {
		previousHash = _previousHash;
		contents = _contents;
		userFromId = _from;
		userToId = _to;
		OpCode = opcode;
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

	inline string getUserFrom() {
		return userFromId;
	}

	inline string getUserTo() {
		return userToId;
	}

	inline int getOpCode() {
		return OpCode;
	}
private:

	static const int ts_length = 30;
	string contents;
        int64_t nonce;
        char timestamp[ts_length];
	string hashOfBlock;
	string hashOfFileData;
	string userFromId;
	string userToId;
	int OpCode;
        int GetBlockLength();

};
