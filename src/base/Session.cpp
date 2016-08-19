/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Session.cpp
 * Author: mrichardson
 * 
 * Created on August 17, 2016, 11:37 AM
 */

#include "Session.h"
namespace session {

    /* Aggravating - don't know why this has to be done this way but it seems to
     * have to be done this way or you get an error.
     */
    list<string> tmp;

    map<string, Session *> ts;

    // MAGIC!! Only runs once?
    map<string, Session *> Session::sessions(ts);

    Session::Session(sData initData) {
        this->ID = initData.ID;

        Session::sessions.insert(pair<string, Session *>(initData.ID, this));

        // Increment the number of connections available
        ++nopen;
    }

    /* This is the public facing method that will call the destructor which 
     * will clean everything up properly (i.e. close connections).
     */
    int Session::close() {

        /* If this is the last reference to the session, remove it from the 
         * list of sessions and destroy it.
         */
        if (--this->nopen <= 0) {
            this->~Session();
        }

    }

    Session::~Session() {

        // Remove the session from the map
        sessions.erase(sessions.find(this->ID));
    }
}

