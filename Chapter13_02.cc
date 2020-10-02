/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/01/2020 at 10:43 PM
 * 
 * Chapter13_02.cc
 * Draw a box with rounded corners. Define a class Box, consisting of four lines
 * and four arcs.
 * 
 * Issue: I had much difficulty with the problem, and I found a solution on
 * Stack Exchange.
 * -----------------------------------------------------------------------------
 */

#include "GUI/Simple_window.h"
#include <cmath>
using namespace Graph_lib;
using Simple_Window = Simple_window;

//------------------------------------------------------------------------------
// Box class: Should have four lines (2 for width, height), and the corners
// needed to be rounded. This could be done by subtracting both width and
// height by one, and then
//------------------------------------------------------------------------------

class Box : public Shape {
public:
    Box(Point tl, Point br); // Box from Top left point to Bottom right point
    Box(Point p, int ww, int hh);
    
    void draw_lines() const;
    
private:
    Point upper_left;
    int width;
    int height;

    // Handles roundness of the box.
    int round_width;
    int round_height;
};


Box::Box(Point tl, Point br): upper_left{tl}, width{abs(tl.x - br.x)},
			      height{abs(tl.y - br.y)},
			      round_width{abs(tl.x - br.x) / 4},
			      round_height{abs(tl.y - br.y) / 4}{

    add(tl);

}


Box::Box(Point tl, int ww, int hh): upper_left{tl},
				    width{ww},
				    height{hh},
				    round_width{ww / 4},
				    round_height{hh / 4} { add(tl);}




void Box::draw_lines() const {

    if (color().visibility()){
    // Arcs
    // upper left arc
    fl_arc(point(0).x , point(0).y, width/2, height/2, 90, 180);
    // upper right arc
    fl_arc(point(0).x + width/2, point(0).y, width/2, height/2, 0, 90);
    // down right arc
    fl_arc(point(0).x + width/2, point(0).y + height/2, width/2, height/2,
           0, -90); 
    // down left arc
    fl_arc(point(0).x, point(0).y + height/2, width/2, height/2, 180, 270); 
    // Lines
    // top horizontal
    fl_xyline(point(0).x + round_width, point(0).y,
              point(0).x + width - round_width);
    // right vertical
    fl_yxline(point(0).x + width, point(0).y + round_height,
              point(0).y + height - round_height);
    // bottom horizontal
    fl_xyline(point(0).x + round_width, point(0).y + height,
              point(0).x + width - round_width);
    // left vertical
    fl_yxline(point(0).x, point(0).y + round_height, 
              point(0).y + height - round_height);	
    }
}

int main(void){
    Point tl{0, 0};
    Simple_Window win{tl, 1280, 720, "Chapter13_02"};
    Point p2{400, 400};
    // Rectangle rect1{p2, 200, 200};

    Box box1{p2, 300, 300};

    win.attach(box1);
    // win.attach(rect1);
    win.wait_for_button();

}
