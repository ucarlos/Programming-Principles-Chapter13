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
    static double angle = (45 * M_PI) / 180;
    return Point{(int)(floor(center(c).x - radius * cos(angle))),
	    (int)(floor(center(c).y - radius * sin(angle)))};
	    
}

Point northeast(const Circle &c){
    auto radius = c.radius();
    static double angle = (45 * M_PI) / 180;    
    return Point{static_cast<int>(center(c).x + radius * cos(angle)),
	    static_cast<int>(center(c).y - radius * sin(angle))};
}

Point southwest(const Circle &c){
    auto radius = c.radius();
    static double angle = (45 * M_PI) / 180;    
    return Point{static_cast<int>(center(c).x - radius * cos(angle)),
	    static_cast<int>(center(c).y + radius * sin(angle))};
}

Point southeast(const Circle &c){
    auto radius = c.radius();
    return Point{static_cast<int>(floor(center(c).x + radius * cos(315))),
	    static_cast<int>(floor(center(c).y  + radius * sin(315)))};
}
//------------------------------------------------------------------------------
// Ellipse functions:
//------------------------------------------------------------------------------
Point north(const Ellipse &c){
    return Point{c.center().x, c.center().y - c.minor()};
}

Point south(const Ellipse &c){
    return Point{c.center().x, c.center().y + c.minor()};
}

Point east(const Ellipse &c){
    return Point{c.center().x + c.major(), c.center().y};
}

Point west(const Ellipse &c){
    return Point{c.center().x - c.major(), c.center().y};
}

Point center(const Ellipse &c){
    return c.center();
}

// Just do it in a simple method
Point northwest(const Ellipse &c){

    return Point(c.center().x - (c.major() / 2), c.center().y - (c.minor() / 2));
}

Point northeast(const Ellipse &c){
    return Point{c.center().x + (c.major() / 2), c.center().y - (c.minor() / 2)};
}

Point southwest(const Ellipse &c){
    return Point{c.center().x - (c.major() / 2), c.center().y + (c.minor() / 2)};
}

Point southeast(const Ellipse &c){
    return Point{c.center().x + (c.major() / 2), c.center().y + (c.minor() / 2)};
}

int main(void){
    Point tl{0, 0};
    Simple_Window win{tl, 1280, 720, "Chapter13_05"};

    Point p1{300, 300};
    Circle cir1{p1, 150};

    Ellipse e1{Point{100, 100}, 100, 50};
    e1.set_color(Color::red);
    // Now display all coordinates:

    Vector_ref<Mark> vec;
    cout << "Circle Coordinates:\n";
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

    cout << "Ellipse Coordinates:\n";

    vec.push_back(new Mark{center(e1), '0'});
    vec.push_back(new Mark{north(e1), '1'});
    vec.push_back(new Mark{south(e1), '2'});
    vec.push_back(new Mark{west(e1), '3'});
    vec.push_back(new Mark{east(e1), '4'});

    cout << "Center: " << center(e1) << endl;
    cout << "Northwest: " << northwest(e1) << endl;
    vec.push_back(new Mark{northwest(e1), '5'});
    
    cout << "Northeast: " << northeast(e1) << endl;
    vec.push_back(new Mark{northeast(e1), '6'});
    
    cout << "Southwest: " << southwest(e1) << endl;
    vec.push_back(new Mark{southwest(e1), '7'});

    cout << "Southeast: " << southeast(e1) << endl;
    vec.push_back(new Mark{southeast(e1), '8'});


    for (int i = 0; i < vec.size(); i++)
	win.attach(vec[i]);
    
    win.attach(cir1);
    win.wait_for_button();

}
