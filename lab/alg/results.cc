#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<short> pi = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4};
    string alpha="abcdefghijklmnopqrstuvwxyz", digits="0123456789";
    char cbuf[100] = { };	// contains 100 '\0' chars
    list<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    short powers[] = {1,2,4,8,16,32,64};
    int ibuf[100];		// contains unknown values

    cout << "Exercise 0\n";
    copy(alpha.begin(), alpha.end(), cbuf);
    cout << cbuf << '\n';

    cout << "Exercise 1\n";
    reverse(begin(cbuf), end(cbuf));
    for (auto x: cbuf)
        cout << x;
    cout <<'\n';

    cout << "Exercise 2\n";
    transform(primes.begin(), primes.end(), begin(ibuf), [](int x){ return x+1; });
    for(int x=0; x<10; x++)
        cout << ibuf[x] << ' ';
    cout << '\n';

    cout << "Exercise 3\n";
    if(any_of(primes.begin(), primes.end(),[](int x){ return x % 2 == 0; }))
        cout << "div 2\n";
    if(any_of(primes.begin(), primes.end(),[](int x){ return x % 42 == 0; }))
        cout << "div 42\n";

    cout << "Exercise 4\n";
    auto i = ++find(primes.begin(), primes.end(), 13);
    cout << *i << '\n';

    cout << "Exercise 5\n";
    int j = count(pi.begin(), pi.end(), 3);
    cout << j << '\n';

    cout << "Exercise 6\n";
    cout << count_if(pi.begin(), pi.end(), [](int x){return x<5;}) << '\n';

    cout << "Exercise 7\n";
    auto k = max_element(pi.begin(), pi.end());
    cout << *k << '\n';

    cout << "Exercise 8\n";
    sort(pi.begin(), pi.end());
    for(auto x: pi)
        cout << x << " "; 
    cout << '\n';

    cout << "Exercise 9\n";
    auto z = lower_bound(pi.begin(), pi.end(), 7);
    cout << z - pi.begin() << '\n';

    cout << "Exercise 10\n";
    auto q = set_intersection(pi.begin(),pi.end(),begin(powers),end(powers),ibuf);
    for(auto x = &ibuf[0]; x<q; x++)
        cout << *x << ' ';
    cout << '\n';
}
