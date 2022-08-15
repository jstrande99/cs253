#include <iostream>
#include <fstream>
#include <string>
#include <ostream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) { //only two args 
	cerr << "usage: " << argv[0] << " infile outfile\n";
	return 1;
    }
    fstream in(argv[1]); //changed from ifstream to fstream for tellg and seekp
    if (!in) {
	cerr << argv[0] << ": can't open " << argv[1] << '\n';
	return 2;
    }
   
    size_t startPos = in.tellg(); //get starting place 
    if(startPos == -1){ //if starting position is nonexistant 
        return -1;
    }else{
        in.seekp(startPos); //set position for writing
    }

    for (string line; getline(in, line); ) {
        size_t position = in.tellg();  // get line starting place
        if(position == -1){ //if line position is nonexistant
            return -1;
        }else{
	        for (size_t pos=0; (pos=line.find("Trump", pos)) != line.npos; ){
	            in.seekp(pos + startPos); // num of pos past start position 
                in.write("Biden", 5); //write biden size of 5 at seekp writing posistion
                line.replace(pos, 5, "Biden");
            } 
            startPos = position; //make starting position the same as line posisiton
            // cout << startPos << "::" << position << '\n';
        }
    }

    return 0;
}

// Note that line.npos ≡ string::npos.
// It’s a static constant, part of the string class.
// It’s a number that means “Sorry, I couldn’t find that.”
