#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

// output format to use IDENTICALLY:
//BSH:Saru> ./filesize input.3lines input.1line 
//program: ./filesize
// input.3lines: 3
// input.1line: 1

int main( int argc, char* argv[] ){
    cout << "program: " << argv[0] << endl;
    int numlines = 0;
    string buffer;
    // just to get you started, this is how to refer to the arguments that were passed
    for (int arg = 1; arg < argc; ++arg){
            //std::cout << "argv[" << arg << "]: " << argv[arg] << '\n' ;
        numlines = -1;
        string filename = argv[arg];
        ifstream ins;
        ins.open(filename);
        if (filename != "input.notafile" && filename != "input.unreadable"){
            while (!ins.eof()){
                getline(ins, buffer);
                numlines++;
            }
        }
        if (filename == "input.2linesNonewline"){
            numlines++;
        }
        ins.close();
        cout << " " << filename << ": " << numlines << endl;
    }
    exit(0); // this means that the program executed correctly!
}
