/*
 * Blockchain.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: vikda
 */

#include "Blockchain.h"

Blockchain::Blockchain(uint32_t _difficulty) {
	// TODO Auto-generated constructor stub
	difficulty = _difficulty;
	Block *firstBlock = new Block("", "First Block");
	firstBlock->MineBlock(difficulty);
	chain.push_back(*firstBlock);
}

Blockchain::~Blockchain() {

}

bool Blockchain::AddBlock(fstream * _pInfile)
{
	if (_pInfile == nullptr)
	{
		return false;
	}

    string fileStr;
    *_pInfile >> fileStr;

#ifdef DBG
    std::cout << fileStr << "\n";
#endif

	Block *newBlock = new Block(GetLastBlock().GetHash(), fileStr);
	newBlock->MineBlock(difficulty);
	chain.push_back(*newBlock);

	return true;
}



Block Blockchain::GetLastBlock() const
{
    return chain.back();
}
