#include <iostream>
#include <cstring>
#include <fstream>
#include "Blockchain.h"

using namespace std;

int main() {

	// Create Blockchain with difficulty 3
    Blockchain bChain = Blockchain(3);

    fstream file1;
    file1.open("test1.txt", fstream::in);
    bChain.AddBlock(&file1);
    cout << " Added file 1" << endl;
    file1.close();

    fstream file2;
    file2.open("test2.txt", fstream::in);
    bChain.AddBlock(&file2);
    cout << " Added file 2" << endl;
    bChain.Exists(&file2);
    file2.close();

    // Eventually this will be moved to the BlockChain, when we separate the Transaction Tree
    // from the blockchain class
    StateTree state = StateTree();
    //Create Accounts
    state.CreateAccount("aa");
    state.CreateAccount("ab");
    // Proof of capture
    state.RecordCapture("aa","test1.txt");
    // This will be combined with AddBlock and will store blockHash instead
    // of the filename
    state.RecordTransaction("aa","ab","test1.txt");
    state.RecordTransaction("ab","aa","test1.txt");
}
