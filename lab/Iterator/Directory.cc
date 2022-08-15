#include "Directory.h"
#include <iostream>

using namespace std;

// The directory iterator pre-fetches the name.  That is, readdir()
// is called when you first create the iterator, and upon ++.
//
// An end() iterator is designated by a null pointer for its DIR *.
// When readdir() fails, we set our pointer to null.

DirectoryIterator::DirectoryIterator(DIR *dp_arg, string match) : dp(dp_arg), toMatching(match) { //fix3
    ++*this;				// get that first entry
}

// Get the next entry in the directory (that we like) and
// put it in the member variable name.

DirectoryIterator &DirectoryIterator::operator++() {	// pre-increment
    while (auto p = readdir(dp)) {	// Read a directory entry.
	name = p->d_name;		// C-string ⇒ C++ string
	if (wanted() == false)//fix2
        continue;		    // Nobody wants that.
	return *this;			// Everything else, I like!
    }
    dp = nullptr;			// readdir failed; don’t try again.
    return *this;
}
//WANTED
bool DirectoryIterator::wanted() const { //fix 2
    if (name == "."){
        return false;
    }
	if (name == ".."){
        return false;
    }
	if(name.find(toMatching) != 0){ //fix3
        return false;
    }

    return true; 
}

string DirectoryIterator::operator*() const {
    return name;			// Fetched in a previous ++.
}

bool DirectoryIterator::operator!=(const DirectoryIterator &rhs) const {
    return dp != rhs.dp;
}



//////////////// Directory methods

Directory::Directory(const char dirname[], const string match) : dp(opendir(dirname)), toMatch(match) { //fix3

    if(!dp){
        throw runtime_error("Could not open directory"); // fix 1
    }
 }

Directory::~Directory() {
    if (dp)				// Only if opendir() succeeded:
	    closedir(dp);			//   should we close it.
}

Directory::iterator Directory::begin() const {
    return iterator(dp, toMatch); //fix3
}

Directory::iterator Directory::end() const {
    return iterator();
}
