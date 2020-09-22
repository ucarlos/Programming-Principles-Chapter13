# ------------------------------------------------------------------------------
# Created by Ulysses Carlos on 09/15/2020 at 01:16 AM
#
# compile.sh
#
# ------------------------------------------------------------------------------


compile(){
    filename=$(basename -- "$1")
    extension="${filename##*.}"
    filename="${filename%.*}"
    
    fltk_include=$(fltk-config --cxxflags)
    g++ "$fltk_include" -g -O2 -fstack-protector-strong -Wformat -Werror=format-security -fvisibility-inlines-hidden -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT -o "$filename" "$1" GUI/Simple_window.cpp GUI/GUI.cpp GUI/Window.cpp GUI/Graph.cpp -Wl,-Bsymbolic-functions -Wl,-z,relro -Wl,-z,now -Wl,--as-needed -lfltk -lfltk_images -lX11

}

# Check if file exists:
FILE=$1
if test -f "$FILE"; then
    echo "$FILE exists. Running g++"
    compile "$1"
else
    echo "$FILE does not exist. Exiting."
    exit
fi

