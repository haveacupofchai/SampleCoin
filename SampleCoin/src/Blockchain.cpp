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

void Blockchain::AddBlock(string content)
{
	Block *newBlock = new Block(_GetLastBlock().GetHash(), content);
	newBlock->MineBlock(difficulty);
	chain.push_back(*newBlock);
}



Block Blockchain::_GetLastBlock() const
{
    return chain.back();
}
