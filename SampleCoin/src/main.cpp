#include <iostream>
#include <cstring>
#include <fstream>
#include "CoreManager.h"

using namespace std;

int main(int argc, char* argv[]) {

	bool isMiner = false;
	if(argc == 2 && !strcmp(argv[1], "miner"))
	{
		isMiner = true;
	}
	CoreManager *runner = new CoreManager();
	runner->Run(isMiner);
}
