#include <string>
using namespace std;

enum NodeType
{
    Client,
    Miner
};

enum RequestType
{
    CreateAccount,
    AddTransaction,
    AddBlock,
    Validate,
    Response,
    Buy // This is for future; might need more implementation
};

struct Node
{
    NodeType type;
    unsigned int ip_address;
};

struct Request
{
    unsigned int requestId;
    Node fromNode;
    RequestType type;
    std::string hash; // from client-> this is the hash of file+a/c+ts OR the account hash; from other miner -> this is the hash of block created
};

struct Response
{
    unsigned int requestId;
    Node fromNode;
    RequestType type;
    bool response;
};


class NodeCore
{
	public:
		void Setup();

	protected:
		bool SendRequest();

	private:
		Node m_currentNode;
		//Network m_network;
};


class ClientNode : public NodeCore
{
	public:
	void FindPreferredNode();
	bool SendRequest();
    bool Broadcast();
    Node m_preferredNode; // Sets up a preferred miner node for the 1:1 request:response
};

class MinerNode : NodeCore
{
	public:
	void FindPeers();
    bool Broadcast();
    void SendResponse(); // Sends response to a particular request eg. validate
};
