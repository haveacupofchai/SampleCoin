#include "NodeCore.h"
#include "Blockchain.h"
#include "Network.h"

using namespace std;

class Miner
{
	public:
	void Run();

	private:
	void ProcessRequest();
    bool Validate();
    bool AddBlock();
    bool RecordTransaction();
    bool Broadcast();
    void Setup();
    Block* createNewBlock(string const& from, string const& to, string file, int opcode);
    Blockchain m_chain;
    StateTree m_stateTree;
    MinerNode m_node;
    Network m_network;
};
