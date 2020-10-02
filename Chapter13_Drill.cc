/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 09/24/2020 at 11:46 PM
 * 
 * Chapter13_Drill.cc
 * 1. Make an 800-by-1000 Simple_window .
 * 
 * 2. Put an 8-by-8 grid on the leftmost 800-by-800 part of that window 
 * (so that each square is 100 by 100).
 * 
 * 3. Make the eight squares on the diagonal starting from the top left 
 * corner red (use Rectangle ).
 *
 * 4. Find a 200-by-200-pixel image (JPEG or GIF) and place three copies of it
 * on the grid (each image covering four squares). If you can’t find an image
 * that is exactly 200 by 200, use set_mask() to pick a 200-by-200 section of
 * a larger image. Don’t obscure the red squares.
 *
 * 5. Add a 100-by-100 image. Have it move around from square to square
 * when you click the “Next” button. Just put wait_for_button() in a loop
 * with some code that picks a new square for your image.
 * -----------------------------------------------------------------------------
 */

#include "./GUI/Simple_window.h"
#include <iostream>
using namespace Graph_lib;
using Simple_Window = Simple_window;

int main(void){
    Point tl{0, 0};
    Simple_Window win{tl, 800, 1000, "Chapter13_Drill"};

    Vector_ref<Rectangle> vec;
    Point temp;

    // Place the 8 x 8 grid:
    for (int row = 0; row < 8; row++){
	for (int col = 0; col < 8; col++){
	    temp.x = tl.x + col * 100;
	    temp.y = tl.y + row * 100;
	    vec.push_back(new Rectangle{temp, 100, 100});
	}
    }

    // Make the left diagonal red:
    for (int i = 0; i < 8; i++){
	vec[8 * i + i].set_color(Color::red);
	vec[8 * i + i].set_fill_color(Color::red);
    }
    // (0, 600)
    // (500, 0)
    // (200, 600)
    string image_path = "./moth.jpg";
    
    Image img1{Point{0, 600}, image_path};

    Image img2{Point{500, 0}, image_path};

    Image img3{Point{400, 200}, image_path};

    Point image4_point{0, 400};
    
    Image image4{image4_point, "./rem_cat.jpg"};
    for (int i = 0; i < 64; i++)
	win.attach(vec[i]);

    win.attach(image4);    
    win.attach(img1);
    win.attach(img2);
    win.attach(img3);

    
    unsigned value{1};
    while (win.wait_for_button()){
	win.set_label("Please Press Ctrl-C to end program.");
	// cerr << "Moving to " << image4_point.x + ((value % 8) * 100)
	//      << ", "
	//      << image4_point.y << "\n";
	if (value++ % 8)
	    image4.move(100,0);      
	else
	    image4.move(-7 * 100, 0);
    }

}
