/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/02/2020 at 10:03 PM
 * 
 * Chapter13_06.cc
 * Write a program that draws a class diagram like the one in §12.6. It will
 * simplify matters if you start by defining a Box class that is a rectangle 
 * with a text label.
 * -----------------------------------------------------------------------------
 */

#include "GUI/Simple_window.h"

using namespace Graph_lib;
using Simple_Window = Simple_window;

class Box : public Rectangle {
public:
    Box(Point p, int w, int h, std::string t)
	: Rectangle(p, w, h), width{w}, height{h}, text{t} { }

private:
    int width;
    int height;
    String text;
};

int main(void){


}
