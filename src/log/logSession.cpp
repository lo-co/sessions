/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   logSession.cpp
 * Author: mrichardson
 * 
 * Created on August 19, 2016, 1:00 PM
 */

#include "logSession.h"
#include <time.h>


namespace session {

    logSession::logSession(fileData fdata) : fileSession(fdata) {
    }
    
    fs::path logSession::generate_file_name(){
        time_t rawtime;
        struct tm* timeinfo;
        char new_file[80];
        
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        
        strftime(new_file, 80, "%Y%m%d_%H%M%S.log", timeinfo);
        
        return (fs::path)new_file;
        
    }
    
    void logSession::log_error(string err){
        
        
        (*fileRef)<< err;
    }

    logSession::~logSession() {
    }
}

