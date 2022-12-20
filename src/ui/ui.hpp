#ifndef UI_H
#define UI_H
#include <globals.hpp>

/*
UI Class
Draws the sidebar and handles mode switching.
*/

class UI{  
    private:      
        int programMode; 
    public:
        UI()
        {
            programMode = FLY;
        }
        void sidebar();
        inline int get_mode(){return programMode;}
};

#endif