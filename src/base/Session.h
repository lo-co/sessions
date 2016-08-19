/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/** 
 * @file:   Session.h
 * @author: MSR Consulting, LLC
 * @date: August, 2016
 * @brief Provides an API for session based applications.
 * 
 * The Session API provides an interface for developing session based
 * applications.  Sessions include such instances as file operations and
 * instrument communication.  In these cases, the application may wish to 
 * access to the session (in the first case a reference to the file and in
 * the second reference to a instrument connection) across multiple layers
 * of the application. The API allows the caller to open the reference 
 * safely in multiple places without duplication.  The API also handles 
 * calls to shutdown the session such that the session is destroyed 
 * *only* when all connections to the session are closed.
 * 
 * 
 */

#include <string>
#include <list>
#include<map>

#ifndef SESSION_H
#define SESSION_H


using namespace std;

/**
 * This is the default data structure for opening a session.  The base contains
 * only a single property - ``ID`` - used to identify the session.
 */

namespace session {

    struct sData {
        string ID;
    };

    class Session {
        /** Number of connections to the session open. */
        int nopen = 0;

        /** Unique ID of the session. */
        string ID = "";


    public:

        /** This map is a shared by all sessions.  It contains a list of 
         * references to existing sessions identified by the ID defined 
         * in the private members.
         */
        static map<string, Session *> sessions;

        inline string get_id() {
            return this->ID;
        }

        Session(sData initData);

        /** @brief Call to close connection to Session
         *  
         *  This decrements the number of open connections (``nopen``) and 
         *  calls the destructor when that number reaches 0.  
         */
        int close();

        /** @brief Increments the counter on the session connections (``nopen``). */
        inline void increment_nopen() {
            ++this->nopen;
        }

        /**
         * 
         * @param name unique ID used to identify the session requested
         * @return reference to session created (if it didn't exist) or the one that
         * exists
         * 
         * @brief Provides a reference to the session identified by ``name``
         * 
         * Template for opening or retrieving a reference to a session.  This is 
         * the meat of this class.  This function searches the ``sessions`` map for
         * an entry corresponding to the key ``name``.  If it is found, it will 
         * increment the variable ``nopen`` and return the reference to that session.
         * If it is not present, then  it will call the constructor for the 
         * session with type ``T`` defined in the template.  It is important to note
         * that this will throw an error if ``T`` is not of type ``Session`` or a 
         * child thereof as we need the constructor called to correspond that 
         * in the function.
         */
        template<typename T>
        static T *open(sData temp) {

            map<string, Session *>::iterator it = sessions.find(temp.ID);
            if (it != sessions.end()) {
                Session *CurrentSession = it->second;
                CurrentSession->increment_nopen();
                return CurrentSession;
            } else {
                T *tempSession = new T(temp);
                return tempSession;
            }
        }

        virtual ~Session();


    };
}

#endif /* SESSION_H */

