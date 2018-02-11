/*
 * Blockchain.h
 *
 *  Created on: Jan 20, 2018
 *      Author: vikda
 */
#include <vector>
#include "Block.h"

#ifndef BLOCKCHAIN_H_
#define BLOCKCHAIN_H_

class Blockchain {
public:
	Blockchain(uint32_t _difficulty);
	virtual ~Blockchain();

    void AddBlock(string content);

    Block _GetLastBlock() const;

private:
    uint32_t difficulty;
    vector<Block> chain;

};

#endif /* BLOCKCHAIN_H_ */
