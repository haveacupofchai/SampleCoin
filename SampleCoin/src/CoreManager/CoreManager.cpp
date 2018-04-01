#include <iostream>
#include <fstream>
#include <cstring>
#include "CoreManager.h"
#include "utils.h"

CoreManager::CoreManager() {
	m_chain = Blockchain(3);
	m_stateTree = StateTree();
}

CoreManager::~CoreManager() {
}

void CoreManager::Setup() {
	// Dummy setup
	m_stateTree.CreateAccount("aa");
	m_stateTree.CreateAccount("ab");
}

Block* CoreManager::createNewBlock(string const& from, string const& to, string file, int opcode) {
	Block* newBlock = new Block(m_chain.GetLastBlock().GetHash(), from, to, file, opcode);
	return newBlock;
}

void CoreManager::Click(string const& user, fstream *_pInfile) {
	string file;
	Block* newBlock = NULL;
	if ((user == "") | (_pInfile == nullptr)) {
		// TODO figure out bad inputs
		return;
	}
	*_pInfile >> file;
	if (m_stateTree.RecordCapture(getId(user), file)) {
		newBlock = createNewBlock("", user, file, CLICK);
		m_chain.AddBlock(newBlock);
	}
}

void CoreManager::Transfer(string const& from, string const& to, fstream *_pInfile) {
	string file;
	Block* newBlock = NULL;
	if ((from == "") | (to == "") | (_pInfile == nullptr)) {
		// TODO figure out bad inputs
		return;
	}
	*_pInfile >> file;
	if (m_stateTree.RecordTransaction(getId(from), getId(to), file)) {
		newBlock = createNewBlock(from, to, file, TRANSFER);
		m_chain.AddBlock(newBlock);
	}
}

void CoreManager::Transaction(string const& from, string const& to, string input) {
	fstream file;
	file.open(input, fstream::in);
	if (from == "" && to != "") {
		Click(to, &file);
	} else if (from != "" && to != "") {
		Transfer(from, to, &file);
	}
	file.close();
}

bool CoreManager::CheckIfFileIsInChain(string input) {
	bool result = false;
	fstream file;
        file.open(input, fstream::in);
	result = m_chain.Exists(&file);
	file.close();
	return result;
}

void CoreManager::Run() {
	Setup();
	Transaction("", "aa", "tempfiles/test1.txt");
	CheckIfFileIsInChain("tempfiles/test1.txt");
	Transaction("", "ab", "tempfiles/test2.txt");
	CheckIfFileIsInChain("tempfiles/test2.txt");
	Transaction("aa", "ab", "tempfiles/test1.txt");
	Transaction("aa", "ab", "tempfiles/test1.txt");
	m_chain.DumpBlocks();
}
