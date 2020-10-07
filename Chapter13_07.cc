/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 10/07/2020 at 12:20 AM
 * 
 * Chapter13_07.cc
 * Make an RGB color chart (e.g., search the web for “RGB color chart”).
 * -----------------------------------------------------------------------------
 */

#include "GUI/Simple_window.h"
#include <sstream>
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
    Simple_Window win{tl, 1280, 720, "Chapter13_07"};
    Vector_ref<Box> vrec;
    std::stringstream ss;
    
    for (int i = 0; i < 256; i++){
	ss.str(""); ss << i;
	vrec.push_back(new Box{Point{tl.x + (i % 20) * 50, tl.y + (i / 20) * 50},
		50, 50, string{ss.str()}});
	vrec[i].set_fill_color(Color(i));
    }

    for (int i = 0; i < vrec.size(); i++)
	win.attach(vrec[i]);

    
    win.wait_for_button();

}
