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
}
