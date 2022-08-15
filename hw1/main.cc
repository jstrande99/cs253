#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
	vector<string> censor = {"alpha", "beta", "gamma", "delta"};
	string inStr;
	string words;
	string x;
	vector<string> allW;

	int cenSize = censor.size();
	try{
	while(getline(cin, words)){
		// cout << words << '\n';
		inStr += words + '\n';
	}
	for(int i = 0; i < 4; i++){
		if(inStr.find(censor[i])){
			inStr.replace(inStr.find(censor[i]), censor[i].size(), "CENSORED");
		}
		else{
   
			for(auto j: inStr){
				if(isalpha(j)){
					x = x + j;
				}
				else{
					string sym(1, j);
					allW.push_back(x);
					allW.push_back(sym);
					x = "";
				}
			}
			for(auto g: allW){
				for(int fk = 0; fk < cenSize; fk++){
					if(g == censor[fk]){
						g = "CENSORED";
					}
				}
				cout << g;
			}
		exit(0);
		}
	}
	cout << inStr;
	exit(0);
	}catch(const out_of_range& er){
		// er.what()
		clog << argc << ' ' << argv[0] << ' ' << "Bad command: Please try again" << '\n';
		exit(1);
	}
}

