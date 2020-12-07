/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 09/25/2020 at 07:25 PM
 * 
 * Chapter13_01.cc
 * Define a class Arc, which draws part of an ellipse. Hint: fl_arc().
 * -----------------------------------------------------------------------------
 */

#include "GUI/Simple_window.h"

using namespace Graph_lib;
using Simple_Window = Simple_window;

//------------------------------------------------------------------------------
// Arc class
//------------------------------------------------------------------------------

class Arc : public Shape{
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

int main(void){
    Point tl{0, 0};
    Simple_Window win{tl, 1280, 720, "Chapter13_01"};

    Point p1{300, 300};
    Arc arc1{p1, 100, 90};
    arc1.set_color(Color::red);

    Arc arc2{p1, 200, 180};
    arc2.set_color(Color::blue);

    Arc arc3{p1, 75, 270};
    arc3.set_color(Color::green);

    Arc arc4{p1, 50, 30};
    arc4.set_color(Color::black);
    
    win.attach(arc1);
    win.attach(arc2);
    win.attach(arc3);
    win.attach(arc4);

    win.wait_for_button();

}
