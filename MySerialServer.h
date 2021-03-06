//
// Created by omri on 1/2/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_MYSERIALSERVER_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_MYSERIALSERVER_H


#include "Server.h"
#include <mutex>

class MySerialServer: public server_side::Server {

private:

    // setting a mutex for multithreading
    std::mutex myMutex;

    int _socketfd;

    bool _running;

    double _timeoutSec;

    // loop over the clients in serial form on teh socket by socketfd, with the clientHandler.
    void _loopOverClients(ClientHandler& clientHandler);
public:
    MySerialServer();

    MySerialServer(double timeout);

    void open(int port, ClientHandler &clientHandler) override;

    void stop() override;

    ~MySerialServer();
};


#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_MYSERIALSERVER_H
