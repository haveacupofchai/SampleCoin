#include "stddef.h"
#include <iostream>
#include <vector>

using namespace std;

class Block {
public:
	Block(string _previousHash, string _contents) {
		previousHash = _previousHash;
		contents = _contents;
	}
	void CalculateHash();
	string GetHash();
private:
	string previousHash;
	string contents;
	string hashOfBlock;
};
