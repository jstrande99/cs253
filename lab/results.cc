#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <set>

using namespace std;

int main(){
//q1
	vector<int> userNum;
	int num;
	while(cin >> num){
		if(num != 0){
			userNum.push_back(num);
		}
		else{
			cout << '\n';
			break;
		}
	}
//q2
	for(auto i: userNum){
		cout << i << '\n';
	}
//q3
	ifstream ifile;
	string x;
	string realRead;
	ifile.open("/etc/resolv.conf");

	while(getline(ifile, x)){
		realRead += x;
	}
	ifile.close();

//q4
	multiset<char> myMultiSet;
	int trueSize = (int) realRead.size();
	for(int i = 0; i < trueSize; i++){
		myMultiSet.insert(realRead[i]);
	}
//q5
	set<char> mySet;
	for(auto i : myMultiSet){
		mySet.insert(i);
	}

//q6
	cout << "string: size=" << realRead.size() << " ";
	for(auto i: realRead){
		cout << i;
	}
	cout << '\n' << "set: size=" << mySet.size() << " ";
	for(auto i: mySet){
		cout << i;
	}
	cout << '\n' << "multiset: size=" << myMultiSet.size() << " ";
	for(auto i: myMultiSet){
		cout << i;
	}
	cout << '\n';
//QUESTION 7
//all of the size counts are different because the string contains all the characters,
//the set contains characters in list with no duplicate chars,
//and the multiset is the same as set but allows duplicates or multiples of a givin char
}
