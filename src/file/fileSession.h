/* 
 * File:   fileSession.h
 * Author: mrichardson
 *
 * Created on August 19, 2016, 1:02 PM
 */

#ifndef FILESESSION_H
#define FILESESSION_H

#include <fstream>
#include <string>

namespace session {

    struct fileData : sData{
        std::string main_path = "";
        int max_size = 50;
    };
    class fileSession : public Session{
        std::fstream fileRef;
    public:
        inline std::fstream get_ref(){return this->fileRef;};
        fileSession(fileData fdata);
        virtual ~fileSession();
    private:

    };
}

#endif /* FILESESSION_H */

