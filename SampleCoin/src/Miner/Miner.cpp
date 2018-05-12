#include "Miner.h"

Miner::Miner() {
	m_chain = Blockchain(3);
	m_stateTree = StateTree();
	// TODO: Eventually cloud will send the initial block to all miners
	m_network = Network();
}

Miner::~Miner() {
}

void Miner::Setup() {
	// Dummy setup
	m_stateTree.CreateAccount("aa");
	m_stateTree.CreateAccount("ab");
}

Block* Miner::createNewBlock(string const& from, string const& to, string file, int opcode) {
	Block* newBlock = new Block(m_chain.GetLastBlock().GetHash(), from, to, file, opcode);
	return newBlock;
}

void Miner::Run()
{
	m_network.StartListening();
}

void ProcessRequest()
{

}
