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
#include "../base/Session.h"
#include <boost/filesystem.hpp>
using namespace std;
namespace fs = boost::filesystem;

namespace session {

    struct fileData : sData{
        fs::path main_path = ""; /**< Top level directory for file */
        int max_size = 50;     /**< Max file size in bytes */
    };
    
    class fileSession : public Session{
        
        fs::path path = "";
        int max_size = 50;
    protected:
        
        /**
         * @brief Returns new file name to be used for storing data.  
         * Implementation is specific to the instance.
         * @return New file name that should be concatenated with the main path 
         */
        virtual fs::path generate_file_name(){return "";};
        fstream *fileRef;
        
    public:
        inline fstream* get_ref(){return this->fileRef;};
        
        /**
         * @param fdata Implementation of the session struct which stores data
         * for the fileSession.
         * 
         * @brief Simply opens the file of interest
         */
        fileSession(fileData fdata);
        
        void check_file_size();
        
        /**
         * @brief Calling the destructor for the file session will close the 
         * open file.
         */
        virtual ~fileSession();
    private:

    };
}

#endif /* FILESESSION_H */

