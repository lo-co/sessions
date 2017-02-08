/* 
 * File:   logSession.h
 * Author: mrichardson
 *
 * Created on August 19, 2016, 1:00 PM
 */

#ifndef LOGSESSION_H
#define LOGSESSION_H

namespace session {

    class logSession:public fileSession {
    public:
        logSession();
        logSession(const logSession& orig);
        virtual ~logSession();
    private:

    };
}

#endif /* LOGSESSION_H */

