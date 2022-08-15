#include "Schedule.h"
#include <cassert>
#include <string>
 
using namespace std;
 
int main() {
    Schedule s;
    Show a("Secret Agent XN-12325865", "Spy Television", 0, 7);
    const Schedule s2(s);
    const Show b("War War War", "War", 7, 24*4-7, true);
    assert(b.name() == "War War War");
    assert(b.channel() == "War");
    assert(b.start() == 105);
    assert(b.length() == 1335);
    assert(!a.adult());
    assert(b.adult());
    assert(!(a.id() < 0));
    assert(!(b.id() < 0));
    assert(a.id() != b.id());
    s += a;
    s += b;
    cout << s << "---\n";
    assert(s.size() == 2);
    bool caught = false;
    try {
        s -= -16;
    }
    catch (const runtime_error &) {
        caught = true;
    }
    assert(caught);
    assert(s.size() == 2);
    s -= a.id();
    assert(s.size() == 1);
    cout << s << "---\n";
    s -= b.id();
    assert(s.size() == 0);
    cout << s << "---\n";
 
    Schedule love;
    love += Show("Love Isthmus", "LUV", 0, 7, true);
    Schedule war;
    war += Show("Trek Wars: Spock vs. Vader", "SyFi", 0, 7, false);
    Schedule life;
    life = s2;          // will soon be overwritten
    life += a;          // will soon be overwritten
    life = love+war;
    assert(life.size()==2);
    cout << life << "---\n";
    assert(life[0].channel() == "LUV"  || life[1].channel() == "LUV");
    assert(life[0].channel() == "SyFi" || life[1].channel() == "SyFi");
 
    caught=false;
    try {
        cout << life[987].name();
    }
    catch (const range_error &r) {
        caught = true;
        const string message = r.what();
        assert(message.find("987") != string::npos);    // bad index
        assert(message.find("2") != string::npos);      // current size
    }
    assert(caught);
    return 0;
}