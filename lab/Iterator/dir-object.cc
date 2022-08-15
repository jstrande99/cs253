#include <iostream>
#include "Directory.h"

using std::cout;

int main() {
    Directory dir(".");
    for (auto name : dir)
	    cout << "Filename: " << name << "\n";

    cout << '\n';
    Directory foo(".", "dir"); //fix 3
    for (auto name : foo)
	    cout << "Filename: " << name << '\n';

}
