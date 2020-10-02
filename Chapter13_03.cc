/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/01/2020 at 11:09 PM
 * 
 * Chapter13_03.cc
 * Define a class Arrow, which draws a line with an arrowhead.
 * -----------------------------------------------------------------------------
 */

#include "GUI/Simple_window.h"

using namespace Graph_lib;
using Simple_Window = Simple_window;


class Arrow : Line {
    


};

int main(void){
    Point tl{0, 0};
    Simple_Window win{tl, 1280, 720, "Chapter13_03"};


    win.wait_for_button();
}
