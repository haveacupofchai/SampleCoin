/*
 * Blockchain.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: vikda
 */

#include "Blockchain.h"

Blockchain::Blockchain() {
}

Blockchain::Blockchain(uint32_t _difficulty) {
	// TODO Auto-generated constructor stub
	difficulty = _difficulty;
	Block *firstBlock = new Block("", "", "", "First Block", GENESIS);
	firstBlock->MineBlock(difficulty);
	chain.push_back(*firstBlock);
}

Blockchain::~Blockchain() {

}

bool Blockchain::Exists(fstream * _pInfile) {

	if (_pInfile == nullptr) {
		return false;
	}
	string filestr;
	*_pInfile >> filestr;

        string toCheck = HashWrapper(filestr);

	for (Block currBlock : chain) {
		if (toCheck == currBlock.GetHashOfFile()) {
			cout << " File exists" << endl;
			return true;
		}
	}
	return false;
}

bool Blockchain::AddBlock(Block* newBlock)
{
	if (newBlock == nullptr) {
		return false;
	}

	newBlock->MineBlock(difficulty);
	chain.push_back(*newBlock);

	return true;
}


void Blockchain::DumpBlocks() {
	for (Block currBlock : chain) {
		cout << "BLOCK DETAILS: " << endl;
		cout << "  Opcode : " << currBlock.getOpCode() << endl;
		cout << "  From : " << currBlock.getUserFrom() << endl;
		cout << "  To : " << currBlock.getUserTo() << endl;
	}
}

Block Blockchain::GetLastBlock() const
{
        return chain.back();
}
