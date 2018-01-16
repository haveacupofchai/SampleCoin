#include "Block.h"
#include <iostream>
#include <cstring>

using namespace std;

int main() {
	Block *firstBlock = new Block("", "First Block");
	firstBlock->CalculateHash();
	cout << "Hash of new block is : " << firstBlock->GetHash() << endl;
}
