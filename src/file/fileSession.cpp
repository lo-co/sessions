/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fileSession.cpp
 * Author: mrichardson
 * 
 * Created on August 19, 2016, 1:02 PM
 */

#include "fileSession.h"
namespace session {

    fileSession::fileSession(fileData fdata) : Session(fdata) {
        fstream.open(fdata.main_path);
    }

    fileSession::~fileSession() {
        fstream.close();
        
    }
}

