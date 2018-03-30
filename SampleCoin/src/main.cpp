#include <iostream>
#include <cstring>
#include <fstream>
#include "Blockchain.h"

using namespace std;

Blockchain bChain = Blockchain(3);

void fileExists(string input) {
    cout << " File : " << input << " -> ";
    fstream file;
    file.open(input, fstream::in);
    bChain.Exists(&file);
    file.close();
    cout << endl;
}

int main() {

    fstream file1;
    file1.open("tempfiles/test1.txt", fstream::in);
    bChain.AddBlock(&file1);
    file1.close();

    fstream file2;
    file2.open("tempfiles/test2.txt", fstream::in);
    bChain.AddBlock(&file2);
    file2.close();

    fileExists("tempfiles/test2.txt");
    fileExists("tempfiles/test3.txt");

    // Eventually this will be moved to the BlockChain, when we separate the Transaction Tree
    // from the blockchain class
    StateTree state = StateTree();
    //Create Accounts
    state.CreateAccount("aa");
    state.CreateAccount("ab");
    // Proof of capture
    state.RecordCapture("aa","../tempfiles/test1.txt");
    // This will be combined with AddBlock and will store blockHash instead
    // of the filename
    state.RecordTransaction("aa","ab","../tempfiles/test1.txt");
    state.RecordTransaction("ab","aa","../tempfiles/test1.txt");
}
