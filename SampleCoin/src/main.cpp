#include <iostream>
#include <cstring>
#include <fstream>
#include "Blockchain.h"

using namespace std;

int main() {

	// Create Blockchain with difficulty 3
    Blockchain bChain = Blockchain(3);

    fstream file;
    file.open("test.txt", fstream::in);

    // TODO: Add graceful failure
    bChain.AddBlock(&file);
    file.close();
}
