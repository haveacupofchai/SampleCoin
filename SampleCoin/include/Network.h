//#include <sys/un.h>
#include <stdio.h>
#include <unordered_set>
#include <thread>
#include <mutex>
#include <string>
#include <iostream>
#include <sys/types.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <pthread.h>
#include <unistd.h>

using namespace std;

#define NSTRS       3           /* no. of strings  */
#define ADDRESS     "testsocket"  /* addr to connect */

class Network
{

	public:

	Network();

	bool Broadcast(string hashOfFile);
	bool StartListening();
	void Listen();
	bool SetupClient();
	bool Setup();

	private:

	size_t c_socketPathMaxLength = sizeof(sockaddr_un::sun_path) / sizeof(sockaddr_un::sun_path[0]);
	const char* m_path = "/tmp/mytest";
	std::thread m_listenThread;
	sockaddr_un m_address;
	int m_socket;
};
