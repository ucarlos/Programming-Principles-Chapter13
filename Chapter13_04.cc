/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/02/2020 at 07:34 PM
 * 
 * Chapter13_04.cc
 * Define functions n(), s(), e(), w(), center(), ne(), se(), sw(), and nw().
 * Each takes a Rectangle argument and returns a Point. These functions define
 * "connection points" on and in the rectangle. For eaxmple, nw(r) is the 
 * northwest (top left) corner of a Rectangle called r.
 * -----------------------------------------------------------------------------
 */


#include "./GUI/Simple_window.h"
#include <iostream>
using namespace Graph_lib;
using Simple_Window = Simple_window;

//------------------------------------------------------------------------------
// Rectangle functions
//------------------------------------------------------------------------------

Point north(const Rectangle &r){
    return Point{r.point(0).x + (r.width() / 2), r.point(0).y};
}

Point south(const Rectangle &r){
    return Point{r.point(0).x + (r.width() / 2), r.point(0).y + r.height()};
}

Point east(const Rectangle &r){
    return Point{r.point(0).x + r.width(), r.point(0).y + (r.height() / 2)};
}

Point west(const Rectangle &r){
    return Point{r.point(0).x, r.point(0).y + (r.height() / 2)};
}

Point center(const Rectangle &r){
    return Point{r.point(0).x + (r.width() / 2), r.point(0).y + (r.height() / 2)};
}

Point northwest(const Rectangle &r){
    return r.point(0);
}

Point northeast(const Rectangle &r){
    return Point{r.point(0).x + r.width(), r.point(0).y};
}

Point southwest(const Rectangle &r){
    return Point{r.point(0).x , r.point(0).y + r.height()};
}

Point southeast(const Rectangle &r){
    return Point{r.point(0).x + r.width(), r.point(0).y + r.height()};
}

int main(void){
    Point tl{0, 0};
    Simple_Window win{tl, 1280, 720, "Chapter13_04"};

    // Make a rectangle
    Point p1{100, 100};
    Rectangle rect1{p1, 200, 200};
    cout << "Printing coordinates of Rectangle:\n";
    
    cout << "North: " << north(rect1) << endl
	 << "South: " << south(rect1) << endl
	 << "West: " << west(rect1) << endl
	 << "East: " << east(rect1) << endl
	 << "Northwest: " << northwest(rect1) << endl
	 << "Northeast: " << northeast(rect1) << endl
	 << "Southwest: " << southwest(rect1) << endl
	 << "Southeast: " << southeast(rect1) << endl;
    
    win.attach(rect1);
    win.wait_for_button();
}
