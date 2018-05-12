#include "Network.h"

Network::Network()
{
}

bool Network::Setup()
{
  m_socket = socket(AF_UNIX, SOCK_STREAM, 0);
  if(m_socket == 0)
  {
	printf("socket unsuccessful\n");
  }

  memset(&m_address, 0, sizeof(struct sockaddr_un));
  m_address.sun_family = AF_UNIX;
  strncpy(m_address.sun_path, m_path, sizeof(m_address.sun_path));

  return true;
}

bool Network::SetupClient()
{
	Setup();
    if((connect(m_socket, (struct sockaddr *) &m_address, sizeof(struct sockaddr_un))) == -1){
	    printf("connection unsuccessfully\n");
	}

	return true;
}

bool Network::StartListening()
{
	char buf[256];
	Setup();
	int ret = bind(m_socket, (struct sockaddr *)&m_address, sizeof(struct sockaddr_un));
	  if (ret !=0){
		printf("bind unsuccessful %d\n", errno);
	  }

	if (listen(m_socket, 8) != 0){
	  printf("listen failed\n");
	}

	 int cfd = accept(m_socket, NULL,NULL);
	 if( cfd != 0){
	     printf("accept failed\n");
	 }

	 while ((read(cfd, buf, 100)) > 0)
	 {
	     cout << "Block Received " << buf << endl;
	     // TODO: Create async notification in a separate thread to add blocks to the chain
	 }

   return true;
}

bool Network::Broadcast(string hashOfFile)
{
	  if (write(m_socket, hashOfFile.c_str(), strlen(hashOfFile.c_str())-1) > 0){
	    printf("write successful\n");
	  }
	  else{
	    printf("write unsuccessful\n");
	  }

	  return true;
}

Network::~Network()
{
	if(m_socket)
	{
		close(m_socket);
	}
}
