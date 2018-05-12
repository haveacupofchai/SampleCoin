/*
 * CaptureClient.h
 *
 *  Created on: May 11, 2018
 *      Author: vikda
 */

#ifndef CAPTURECLIENT_H_
#define CAPTURECLIENT_H_
#include "Client.h"

class CaptureClient : public Client {
public:
	CaptureClient();
	virtual ~CaptureClient();

    void Run();
    void TakePhoto(string filePath);
    string TakeHash(fstream *_pInfile, char *ptm);
    void GetLocation();
	void GetTimeStamp(char* timestamp, int ts_length);
};

#endif /* CAPTURECLIENT_H_ */
