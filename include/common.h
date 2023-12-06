#ifndef __COMMON_H_
#define __COMMON_H_


#define KEYPRESSED 1
#define KEYRELEASED 0

enum class KeyMsg{
    SAVE,
    SAVE_ANOTHER_NAME,


    NONE
};


#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <chrono>
#include "spdlog/spdlog.h"



#endif // __COMMON_H_