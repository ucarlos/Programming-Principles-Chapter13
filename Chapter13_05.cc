/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/02/2020 at 08:04 PM
 * 
 * Chapter13_05.cc
 * Define the functions from exercise 4 for a Circle and an Ellipse. Place the
 * connection points on or outside the shape but not outside the bounding
 * rectangle.
 * -----------------------------------------------------------------------------
 */

#include "GUI/Simple_window.h"
#include <iostream>
#include <cmath>
using namespace Graph_lib;
using Simple_Window = Simple_window;

//------------------------------------------------------------------------------
// Circle functions:
//------------------------------------------------------------------------------
Point north(const Circle &c){
    return Point{c.point(0).x + c.radius(), c.point(0).y};
}

Point south(const Circle &c){
    auto radius = c.radius();
    return Point{c.point(0).x + radius, c.point(0).y + 2 * radius};
}

Point east(const Circle &c){
    auto radius = c.radius();
    return Point{c.point(0).x + 2 * radius, c.point(0).y + radius};
}

Point west(const Circle &c){
    auto radius = c.radius();
    return Point{c.point(0).x, c.point(0).y + radius};
}

Point center(const Circle &c){
    auto radius = c.radius();
    return Point{c.point(0).x + (radius), c.point(0).y + (radius)};
}

Point northwest(const Circle &c){
    auto radius = c.radius();
    return Point{(int)(floor(center(c).x - radius * cos(45))),
	    (int)(floor(center(c).y - radius * sin(45)))};
	    
}

Point northeast(const Circle &c){
    auto radius = c.radius();
    return Point{static_cast<int>(floor(center(c).x + radius * cos(45))),
	    static_cast<int>(floor(center(c).y - radius * sin(45)))};
}

Point southwest(const Circle &c){
    auto radius = c.radius();
    return Point{static_cast<int>(floor(center(c).x - radius * cos(45))),
	    static_cast<int>(floor(center(c).y + radius * sin(45)))};
}

Point southeast(const Circle &c){
    auto radius = c.radius();
    return Point{static_cast<int>(floor(center(c).x + radius * cos(315))),
	    static_cast<int>(floor(center(c).y  + radius * sin(315)))};
}
//------------------------------------------------------------------------------
// Ellipse functions:
//------------------------------------------------------------------------------
int main(void){
    Point tl{0, 0};
    Simple_Window win{tl, 1280, 720, "Chapter13_05"};

    Point p1{300, 300};
    Circle cir1{p1, 200};

    // Now display all coordinates:

    Vector_ref<Mark> vec;
    vec.push_back(new Mark{center(cir1), '0'});
    vec.push_back(new Mark{north(cir1), '1'});
    vec.push_back(new Mark{south(cir1), '2'});
    vec.push_back(new Mark{west(cir1), '3'});
    vec.push_back(new Mark{east(cir1), '4'});

    cout << "Center: " << center(cir1) << endl;
    cout << "Northwest: " << northwest(cir1) << endl;
    vec.push_back(new Mark{northwest(cir1), '5'});
    
    cout << "Northeast: " << northeast(cir1) << endl;
    vec.push_back(new Mark{northeast(cir1), '6'});
    
    cout << "Southwest: " << southwest(cir1) << endl;
    vec.push_back(new Mark{southwest(cir1), '7'});

    cout << "Southeast: " << southeast(cir1) << endl;
    vec.push_back(new Mark{southeast(cir1), '8'});
    


    for (int i = 0; i < vec.size(); i++)
	win.attach(vec[i]);
    
    win.attach(cir1);
    win.wait_for_button();

}
