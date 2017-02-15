/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   test_main.cpp
 * Author: mrichardson
 *
 * Created on February 14, 2017, 4:35 PM
 */

#include <cstdlib>
#include <iostream>
#include "../src/base/Session.h"
#include <vector>

using namespace std;
using namespace session;

/**
 * This is just a dumb little program that demonstrates actually what is
 * going on when you properly instantiate a session.  In this example, we create
 * a new type based off of the base data type ``sData`` from ``Session.h`` and 
 * give it an ID "Test".  We then create a vector of new sessions  and an 
 * individual instance.  The number of sessions open is probed as individual 
 * instances are closed.
 * 
 * That is all...
 */
int main(int argc, char** argv) {
    sData newType;
    newType.ID = "Test";
    
    vector<Session*> s = {Session::open<Session>(newType),Session::open<Session>(newType),Session::open<Session>(newType)};
    Session* testSession;
    
    testSession = Session::open<Session>(newType);
    cout << "Current session is " << testSession->get_id() << "." << endl;
    cout << "Current number open is " << s[2]->get_nopen() << "." << endl;
    cout << "Current number open is " << testSession->get_nopen() << "." << endl;
    testSession->close();
    
    for(int i = 0; i < s.size(); i++){
        cout << "Current number open is " << s[i]->get_nopen() << "." << endl;
        s[i]->close();
        
    }
    
    return 0;
}

