#ifndef __CURSOR_PROCESSOR_
#define __CURSOR_PROCESSOR_

#include <common.h>

class CursorProcessor{
    private:
        uint64_t cursor_index;
    public:
        CursorProcessor(): cursor_index(0){};
        ~CursorProcessor(){};
        uint64_t getCursorIndex();
        void drawCursor();
        void drawCursorArea();
}

#endif // __CURSOR_PROCESSOR_