/*
 * StateTree.h
 *
 *  Created on: Mar 10, 2018
 *      Author: vikda
 */

#include <unordered_map>
#include <vector>
#include "utils.h"

#pragma once

#define MAX_AC_LENGTH 26

struct Account
{
	/// Account's balance.
    vector<string> m_files;
};

struct Node
{
	int data; // This is to optimize the account tree later.
	struct Node* child[MAX_AC_LENGTH];
	Account *account;
};

class StateTree {
public:
	StateTree();
	virtual ~StateTree();

	void CreateAccount(string const& address);
	bool RecordTransaction(string const& fromAddress, string const& toAddress, string fileStr);
	bool RecordCapture(string const& accountAddress, const string fileStr);

private:
	struct Node* head;
	bool AddFile(Account** account, const string fileStr);
	bool SearchAccount(string const& address, Account** account);
	bool UpdateAccounts(Account* fromAccount, Account* toAccount, string fileStr);

};
