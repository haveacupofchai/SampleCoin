#include "Blockchain.h"
#include <iostream>
#include <cstring>

using namespace std;

int main() {

	// Create Blockchain with difficulty 3
    Blockchain bChain = Blockchain(3);

    bChain.AddBlock("Second Block");
    bChain.AddBlock("Third Block");

}
