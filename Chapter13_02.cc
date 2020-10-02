/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/01/2020 at 10:43 PM
 * 
 * Chapter13_02.cc
 * Draw a box with rounded corners. Define a class Box, consisting of four lines
 * and four arcs.
 * -----------------------------------------------------------------------------
 */

#include "GUI/Simple_window.h"

using namespace Graph_lib;
using Simple_Window = Simple_window;

//------------------------------------------------------------------------------
// Arc class
//------------------------------------------------------------------------------

class Arc : public Shape {
public:
    Arc(Point pp, int radius, int aa): p{pp}, r{radius}, angle{aa} {
	if (angle < 0)
	    error("Cannot have a negative arc length.\n");
	else
	    add(p);
    }

    Point center(){ return {point(0).x, point(0).y}; }
    void set_radius(int rr){
	set_point(0,Point{center().x - r + rr , center().y - r + rr});
	r = rr;
    }
    
    void draw_lines() const;
    
private:
    Point p{};
    int r;
    int angle; //length of arc in degrees [0, 360]
    
};

void Arc::draw_lines() const {
    if (color().visibility())
	fl_arc(point(0).x - r, point(0).y -r, r + r, r + r, 0, angle);
}



//------------------------------------------------------------------------------
// Box class: Should have four lines (2 for width, height), and the corners
// needed to be rounded. This could be done by subtracting both width and
// height by one, and then
//------------------------------------------------------------------------------

struct Box : Shape {
    

};

int main(void){
    Point tl{0, 0};
    Simple_Window win{tl, 1280, 720, "Chapter13_02"};


    win.wait_for_button();

}
