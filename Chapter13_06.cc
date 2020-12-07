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
#include <iostream>
using namespace Graph_lib;
using Simple_Window = Simple_window;

class Box : public Rectangle {
public:
    Box(Point p, int w, int h, std::string t, int fs)
		: Rectangle(p, w, h), width{w}, height{h}, font_size{fs},
		  text{t} {
		if (font_size < 1)
			error("Font size is negative.");
		// Now check if the string will fit the box:
		if ((width - t.size() / 2) + t.size() > width)
			error("Text will not fit the width of the box.");

    }

    Box(Point p, int w, int h, std::string t):
		Rectangle(p, w, h), width{w}, height{h}, text{t} { }

    void draw_lines() const;
    void set_label(const string &str){ text = str; }
    string label() const { return text; }

    void set_font_size(int size) { font_size = size; }
    int get_font_size() { return font_size; }
    
private:
    int width;
    int height;
    int font_size{14};
    std::string text;
    Graph_lib::Font fnt{fl_font()};
};

void Box::draw_lines() const {
    Rectangle::draw_lines(); // Call Rectangle's draw_lines
    
    // Now draw a text box, centered vertically
    int ofnt = fl_font();
    int osz = fl_size();
    fl_font(fnt.as_int(), font_size);

    fl_draw(text.c_str(), point(0).x + ((width - text.size()) / 8),
			point(0).y + height / 2);
    fl_font(ofnt, osz);

}

int main(void){
    Point tl{0, 0};
    Simple_Window win{tl, 1280, 720, "Chapter13_06"};
    Point p1{300, 100};
    Point p2{100, 200};
    Box box1{p1, 100, 50, "Shape"};
    box1.set_fill_color(Color::red);
    Box box2{p2, 100, 50, "Axis"};
    box2.set_fill_color(Color::dark_green);
 
    Box box3{Point{250, 200}, 100, 50, "Rectangle"};
    box3.set_fill_color(Color::dark_green);
    
    Box box4{Point{400, 200}, 100, 50, "Text"};
    box4.set_fill_color(Color::dark_green);
    
    Box box5{Point{550, 200}, 100, 50, "Image"};
    box5.set_fill_color(Color::dark_green);    

    Box box6{Point{300, 300}, 100, 50, "THE GAME"};
    box6.set_fill_color(Color::cyan);
    
    win.attach(box1);
    win.attach(box2);
    win.attach(box3);
    win.attach(box4);
    win.attach(box5);
    win.attach(box6);
    win.wait_for_button();
}
