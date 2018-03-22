/*

 * StateTree.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: vikda
 */

#include "StateTree.h"
#include <algorithm>
#include <iostream>

StateTree::StateTree() {
	// TODO Auto-generated constructor stub
	head = new Node();
	head->data = 0;
}

StateTree::~StateTree() {
	// TODO Auto-generated destructor stub
}

void StateTree::CreateAccount(string const& address) {
	//TODO: Fail if "Account already exists"?
	Node *current = head;
	for (unsigned int i = 0; i < address.length(); i++) {
		int letter = (int) address[i] - (int) 'a';
		if (current->child[letter] == NULL) {
			current->child[letter] = new Node();
			current->child[letter]->account = new Account();
			// TODO: Use data to optimize search function
			current->data++;
		}
		current = current->child[letter];
	}
}

bool StateTree::RecordTransaction(string const& fromAddress, string const& toAddress, string fileStr)
{
	Account *fromAccount = NULL;
	Account *toAccount = NULL;
	if (SearchAccount(fromAddress, &fromAccount)&& SearchAccount(toAddress, &toAccount))
	{
		return UpdateAccounts(fromAccount, toAccount, fileStr);
	}

	return false;
}

bool StateTree::RecordCapture(string const& accountAddress, const string fileStr)
{
	Account* ac = NULL;
	if (!SearchAccount(accountAddress, &ac))
		return false;

	return AddFile(&ac,fileStr);
}

bool StateTree::AddFile(Account** account, const string fileStr)
{
	CHECKNULL(account);
	CHECKNULL(*account);

	(*account)->m_files.push_back(fileStr);

	return true;
}

bool StateTree::UpdateAccounts(Account* fromAccount, Account* toAccount, const string fileStr)
{
	CHECKNULL(fromAccount);
	CHECKNULL(toAccount);

	auto it = std::find(fromAccount->m_files.begin(), fromAccount->m_files.end(), fileStr);
	if(it == fromAccount->m_files.end())
	{
		cout << "Account does not have file" << endl;
		return false;
	}

	fromAccount->m_files.erase(it);

	if (AddFile(&toAccount, fileStr) == false)
	{
		cout << "Unable to add file" << endl;
		return false;
	}
	cout << "Transaction successful" << endl;

	return true;
}

bool StateTree::SearchAccount(string const& address, Account** account)
{
	CHECKNULL(account);

	Node *current = head;

	for (unsigned int i = 0; i < address.length(); i++) {
		int letter = (int) address[i] - (int) 'a';
		if (current->child[letter] == NULL) {
			cout << "Account does not exist";
			return false;
		}
		current = current->child[letter];
	}
	*account = current->account;

	return true;
}
