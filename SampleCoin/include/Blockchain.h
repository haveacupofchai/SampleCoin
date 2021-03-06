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
    Blockchain();
    Blockchain(uint32_t _difficulty);
    virtual ~Blockchain();

    bool AddBlock(Block* newBlock);
    bool Exists(fstream* _infile);
    void DumpBlocks();

    Block GetLastBlock() const;

private:
    uint32_t difficulty;
    vector<Block> chain;
    StateTree m_state;

};

#endif /* BLOCKCHAIN_H_ */
