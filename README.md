# Chapter 13

This repository contains solutions to some problems from Bjarne Stroustrup's Principles of Programming Using C++ (2014). These solutions were written in Linux, but should work for any UNIX-like system.


## Requirements:

You must install FLTK on your system in order to compile these programs. You can do this in Ubuntu by doing

```bash
sudo apt install libfltk1.3-dev
```


## How to compile

The method to compile the GUI programs took several hours of trial and error to fix. The GUI code provided by Stroustrup had to be edited since I wasn't able to compile it. I've included a compile_fltk.sh file that you can use to compile. For example, for a file Test.cc, you do

```bash
./compile_fltk.sh Test.c
```

However, if you can't compile with compile_fltk, you may need to do the following:

1.  Copy-paste the output from fltk-config

    ```bash
    fltk-config --cxxflags
    ```

2.  Using g++,  Include the fltk-images library by doing -lfltk<sub>images</sub>

3.  (OPTIONAL?) Include the local GUI library by doing -I./GUI

4.  Place the name of your program and then its output file.

5.  Run the entire command using g++
