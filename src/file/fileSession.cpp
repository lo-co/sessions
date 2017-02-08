/* 
 * File:   fileSession.cpp
 * Author: mrichardson
 * 
 * Created on August 19, 2016, 1:02 PM
 */

#include "fileSession.h"
namespace session {

    fileSession::fileSession(fileData fdata) : Session(fdata) {
        std::fstream.open(fdata.main_path);
    }

    fileSession::~fileSession() {
        std::fstream.close();
        
    }
}

