/*
 * CaptureClient.cpp
 *
 *  Created on: May 11, 2018
 *      Author: vikda
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include "utils.h"
#include "CaptureClient.h"

using namespace std;
static const int s_tsLength = 50;

CaptureClient::CaptureClient() {
	// TODO Auto-generated constructor stub

}

CaptureClient::~CaptureClient() {
	// TODO Auto-generated destructor stub
}

void CaptureClient::Run()
{
	Setup();
	TakePhoto("tempfiles/test1.txt");
	m_node.Broadcast();
}

void CaptureClient::GetTimeStamp(char* timestamp, int ts_length)
{
	// TODO: Modify to get stamp from cloud
	time_t rawtime;
	struct tm * ptm;
	time ( &rawtime );
	ptm = gmtime ( &rawtime );
	strftime(timestamp,ts_length,"%c",ptm);
}

void CaptureClient::TakePhoto(string filePath)
{
	fstream file;
	file.open(filePath, fstream::in);
	char ts[s_tsLength];
	GetTimeStamp((char*)ts, s_tsLength);
	// TODO: Also pass in account info and location
	string contentsHash = TakeHash(&file, ts);
	m_node.Broadcast();
	file.close();
}

string CaptureClient::TakeHash(fstream *_pInfile, char *ts)
{
	string fileStr;
	*_pInfile >> fileStr;
	char *cstr = new char[strlen(fileStr.c_str()) + strlen(ts)];
	strcpy(cstr, fileStr.c_str());
	strcat(cstr, ts);

	// This is string to char array to string!
	// Can change this to add another HashWrapper that may take in char array
	// as input
	string contentsHash = HashWrapper(string(cstr));

	cout << "Hash of file " << contentsHash << endl;
	delete cstr;

	return contentsHash;

}

void CaptureClient::GetLocation()
{
	// TODO: Define a format to store location
}
