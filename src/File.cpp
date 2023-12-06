#include <File.h>

const std::string File::getFileName() const{
    return this->file_name;
}

void File::setFileName(const std::string& file_name){
    this->file_name = file_name;
}

void File::fileSave(){
    std::ofstream outputFile(this->file_name);

    if(outputFile.is_open()){
        outputFile << this->textController.getInputText();

        outputFile.close();
        this->is_file_saved = true;
        spdlog::info("File Saved.");
    }else{
        spdlog::error("Cannot open file.");
    }
}

