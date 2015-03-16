# libFFM-1.02-cygwin

Lib-FFM is a Kaggle prize winning click through prediction library located at 
http://www.csie.ntu.edu.tw/~r01922136/libffm/

Small tweaks to make Lib FFM compile on Cygwin

Basically there are only two major things preventing libFFM from compiling on Cygwin64
- An implementation of the drand48 family of functions
- Implementations of the stoi() and stof() functions

It is interesting to note that the stoi and stof functions have been broken on Windows for a long time. For example, see this stackoverflow question from *2011*!:
http://stackoverflow.com/questions/8542221/stdstoi-doesnt-exist-in-g-4-6-1-on-mingw

The drand48 implementation is from https://gist.github.com/mortennobel/8665258 which in turn is from the FreeBSD distribution

It also appears that there are minor differences in the location of various functions (atoi and friends)

So the summary of steps from a fresh download of source from http://www.csie.ntu.edu.tw/~r01922136/libffm/

A)	Download the two extra header files drand48.h and stringconv.h to the source directory
B)	Ffm.cpp – Add the line #include “drand48.h”
C)	Ffm-predict.cpp – Add the line #include <cstdlib>
D)	Ffm-train.cpp – Add the lines
- #include <fstream>
- #include <cstdlib>
- #include “stringconv.h”

Tested on Windows x64, Cygwin64 with GCC 4.9.2



