/* 
 * File:   fileSession.cpp
 * Author: mrichardson
 * 
 * Created on August 19, 2016, 1:02 PM
 */

#include "fileSession.h"
namespace session {

    /**/
    fileSession::fileSession(fileData fdata) : Session(fdata), 
            path(fdata.main_path), max_size(fdata.max_size) {
        
        fs::path newpath = path / this->generate_file_name();
        fileRef->open(newpath.string());
    }
    
    void fileSession::check_file_size(){
         
        if (this->fileRef->tellg() >= this->max_size){
            fileRef->close();
            fs::path newpath = path / this->generate_file_name();
            fileRef->open(path.string());
            
        }
    }
    
    fileSession::~fileSession() {
        fileRef->close();
        
    }
    
   
}

