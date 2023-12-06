#ifndef __FILE_
#define __FILE_

#include <common.h>
#include <TextController.h>
#include <KeyController.h>

class File{
    private:
        std::string file_name;
        bool is_file_saved;

    public:
        TextController textController;
        KeyController keyController;

        File(): 
            file_name(""), 
            is_file_saved(false)
        {};
        File(const std::string& file_name):
            file_name(file_name),
            is_file_saved(false)
        {};
        ~File(){};
        const std::string getFileName() const;
        void setFileName(const std::string&);
        void fileSave();
};

#endif // __FILE_