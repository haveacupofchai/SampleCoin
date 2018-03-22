/*
 * Blockchain.h
 *
 *  Created on: Jan 20, 2018
 *      Author: vikda
 */
#include <vector>
#include "Block.h"
#include "StateTree.h"
#include <fstream>

#ifndef BLOCKCHAIN_H_
#define BLOCKCHAIN_H_

// #define DBG // Debug Macro

class Blockchain {
public:
	Blockchain(uint32_t _difficulty);
	virtual ~Blockchain();

    bool AddBlock(fstream* _infile);
    bool Exists(fstream* _infile);

    Block GetLastBlock() const;

private:
    uint32_t difficulty;
    // TODO: Move to Transaction Tree
    vector<Block> chain;
    // TODO: Move logic from main.cpp
    StateTree m_state;

};

#endif /* BLOCKCHAIN_H_ */
