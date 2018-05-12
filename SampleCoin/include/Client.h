/*
 * Client.h
 *
 *  Created on: May 11, 2018
 *      Author: vikda
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "NodeCore.h"

class Client {
public:
	Client();
	virtual ~Client();

protected:
    void TakeHash(); // TODO: internally call Media::TakeHash
    void Setup();
    void Destroy();

    //Account m_account;
    //Media m_media;
    ClientNode m_node;

};

#endif /* CLIENT_H_ */
