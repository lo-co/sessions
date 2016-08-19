/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SerialSession.h
 * Author: mrichardson
 *
 * Created on August 18, 2016, 3:35 PM
 */

#ifndef SERIALSESSION_H
#define SERIALSESSION_H

#include "Session.h"

namespace session {

    /** Serial session data structure used for initializing serial connections. */
    struct serData : sData {
        int port = 0;
        int baud = 19200;
        int data_bits = 8;
        int stop_bits = 0;
        int flow_ct = 0;
    };

    class SerialSession : public Session {
        int COM = 0;

        bool open_port();
    public:
        SerialSession(serData initData);
        virtual ~SerialSession();
    private:

    };
}

#endif /* SERIALSESSION_H */

