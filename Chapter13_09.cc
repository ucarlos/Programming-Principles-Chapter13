/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/07/2020 at 04:54 PM
 * 
 * Chapter13_09.cc
 * Tile a part of a window with Regular_hexagon s (use at least eight hexagons)
 * -----------------------------------------------------------------------------
 */

#include "GUI/Simple_window.h"
using namespace Graph_lib;
using Simple_Window = Simple_window;

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
    Simple_Window win{Point{0, 0}, 1280, 720, "Chapter13_09"};

    Vector_ref<Regular_Hexagon> vrec;

    for (int i = 0; i < 32; i++){
		vrec.push_back(new Regular_Hexagon{Point{50 + (i % 8) * 100,
					50 + (i / 8) * 100}, 50});
		vrec[i].set_fill_color(Color(i));
		win.attach(vrec[i]);
    }
    
    win.wait_for_button();
}

