/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/07/2020 at 03:48 PM
 * 
 * Chapter13_08.cc
 * Define a class Regular_hexagon (a regular hexagon is a six-sided polygon
 * with all sides of equal length). Use the center and the distance from the
 * center to a corner point as constructor arguments.
 * -----------------------------------------------------------------------------
 */

#include "GUI/Simple_window.h"
#include <cmath>
using namespace Graph_lib;
using Simple_Window = Simple_window;

// Who should I inherit from? Shape? Polygon?
class Regular_Hexagon : public Shape {
public:
    Regular_Hexagon(Point center, int distance):
	radius{distance} { add(center); }
    
    void draw_lines() const;
    
private:
    int radius{5};
};

void Regular_Hexagon::draw_lines() const {
    static double angle = M_PI / 3;

    double x, y, xx, yy; // Store the next two points for a line
    if (fill_color().visibility()){
	x = radius * cos(angle);
	y = radius * sin(angle);
	
	fl_line(point(0).x + radius, point(0).y,
		point(0).x + x,
		point(0).y + y);
	
	// For the next four lines:

	for (int i = 1; i < 5; i++){
	    xx = radius * cos((i + 1) * angle);
	    yy = radius * sin((i + 1) * angle);
	    
	    fl_line(point(0).x + x, point(0).y + y, point(0).x + xx,
		    point(0).y + yy);

	    // Now update x and y for the next angle
	    x = xx; y = yy;
	}

	fl_line(point(0).x + x, point(0).y + y,
		point(0).x + radius, point(0).y);
    }

    if (color().visibility()){
	x = radius * cos(angle);
	y = radius * sin(angle);
	
	// Draw the first line
	fl_line(point(0).x + radius, point(0).y,
		point(0).x + x,
		point(0).y + y);
	
	// For the next four lines:

	for (int i = 1; i < 5; i++){
	    // Compute coordinates for next angle
	    xx = radius * cos((i + 1) * angle);
	    yy = radius * sin((i + 1) * angle);
	    
	    fl_line(point(0).x + x, point(0).y + y, point(0).x + xx,
		    point(0).y + yy);

	    // Now update x and y for the next angle
	    x = xx; y = yy;
	}

	// Now draw the last line:
	fl_line(point(0).x + x, point(0).y + y,
		point(0).x + radius, point(0).y);	
    }

    
}

int main(void){
    Simple_Window win{Point{0, 0}, 1280, 720, "Chapter13_08"};
    Regular_Hexagon reg{Point{400, 400}, 200};

    win.attach(reg);
    win.wait_for_button();


}
