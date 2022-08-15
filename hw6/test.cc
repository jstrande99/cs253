#include "Schedule.h"

#include <cassert>      // assert

#include <string>       // string

#include <iostream>     // cout

 

using namespace std;

 

int main() {

    Schedule s;

    s += Show("Bull", "CBS", 21*4, 4, true);

    s += Show("Young Sheldon", "CBS", 19*4, 2);

    s += Show("How We Roll", "CBS", 20*4+2, 2);

    s += Show("Law & Order: Organized Crime", "NBC", 21*4, 4, true);

    s += Show("United States of Al", "CBS", 19*4+2, 2);

    s += Show("Law & Order", "NBC", 19*4, 4, true);

    s += Show("Ghosts", "CBS", 20*4, 2, false);

    s += Show("Law & Order: SVU", "NBC", 20*4, 4, true);

    

    cout << "Via <<:\n" << s;

    cout << "Via []:\n";

    for (size_t i=0; i<s.size(); i++)

        cout << "   " << s[i].name() << '\n';

    cout << "Via for-each:\n";

    for (const auto v : s)

        cout << "   " << v.name() << '\n';

    // cout << "Via for-each for kids\n";

    // s.grups(false);

    // for (const auto &v : s)

    //     cout << "   " << v.name() << '\n';

 

    // Schedule::iterator it = s.begin();

    // assert((*it).name() == "Young Sheldon");

    // assert((*it++).name() == "Young Sheldon");

    // assert((*++it).name() == "Ghosts");

    // assert(it == it);

    // assert(it != s.begin());

    // assert(s.end() != it);

    // assert(not (it == s.end()));

 

    return 0;

}
