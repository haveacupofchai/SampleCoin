#include "Blockchain.h"
#include "Network.h"

#ifndef COREMANAGER_H_
#define COREMANAGER_H_

class CoreManager {
public:
    CoreManager();
    virtual ~CoreManager();
	void Transaction(string const& from, string const& to, string file);
	void Run(bool _isMiner);

private:
	void Setup();
	bool CheckIfFileIsInChain(string file);
	void Transfer(string const& from, string const& to, fstream * _pInfile);
	void Click(string const& user, fstream * _pInfile);
	Block* createNewBlock(string const& from, string const& to, string file, int opcode);

	Blockchain m_chain;
	StateTree m_stateTree;
	Network m_network;
};

#endif /* COREMANAGER_H_ */
