/* 
 * File:   logSession.h
 * Author: mrichardson
 *
 * Created on August 19, 2016, 1:00 PM
 */

#ifndef LOGSESSION_H
#define LOGSESSION_H

#include "../file/fileSession.h"

namespace session {

    class logSession:public fileSession {
        
        int num_msgs[3] = {0,0,0};
        
    protected:
        fs::path generate_file_name();
    public:
        logSession(fileData fdata);
        
        void log_error(string err);
        void log_warning(string warn);
        
        inline int* get_num_msgs(){return this->num_msgs;};
        
        virtual ~logSession();
    private:

    };
}

#endif /* LOGSESSION_H */

