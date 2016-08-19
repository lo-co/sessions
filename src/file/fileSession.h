/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fileSession.h
 * Author: mrichardson
 *
 * Created on August 19, 2016, 1:02 PM
 */

#ifndef FILESESSION_H
#define FILESESSION_H

#include <fstream>

namespace session {

    struct fileData : sData{
        string main_path = "";
        int max_size = 50;
    };
    class fileSession : public Session{
        fstream fileRef;
    public:
        inline fstream get_ref(){return this->fileRef;};
        fileSession(fileData fdata);
        virtual ~fileSession();
    private:

    };
}

#endif /* FILESESSION_H */

