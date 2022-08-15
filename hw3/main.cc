#include <iostream>
#include <string>
#include <vector>
#include <fstream>

   using namespace std;
/*converts the censored words into CENSORED*/
auto censor(vector<string> inwords, vector<string> wrongWords){ 
	vector<string> returnCensor; 

	for(auto i: inwords){ /*words in*/
		int check = 0; 
		string newI, endI; 
		for(auto j: wrongWords){ /*bad words in*/
			if(i == j){
				i = "CENSORED"; 
				check = 1; /*set flag*/
			}
			if(check == 0){
				for(auto z: i){ /*get letters of words*/
					if(isalpha(z)){ /*if alpha and to string*/
						newI.push_back(z);
					}
					else{
						endI.push_back(z);
					}
				}

				if(newI == j){
						newI = "CENSORED";
						newI += endI;
						i = newI; /*update returning value*/
						check = 1;
				}
				newI = "";
				endI = "";
			}
		}
		returnCensor.push_back(i);
	}	
	return returnCensor; 
}

/*converts the files after - into string vectors*/
auto maker(vector<string> infiles, string hmd){
	string words, inStr; 
	vector<string> returnWords; 

	for(auto i: infiles){ /*iterate through files after "-" */
		ifstream ifile(i); 
		if(ifile.is_open()){ /*true if file opens correctly */
			while(getline(ifile, words)){ /*read lines */
				words.push_back('\n');
				for(auto x: words){
					if(x != ' ' && x != '\n'){
						inStr += x; 
					}
					else{
						returnWords.push_back(inStr); /*add word*/
						if(x == ' '){
							returnWords.push_back(" "); /*keep space*/
						}else if(x == '\n'){
							returnWords.push_back("\n"); /*keep newln*/
						}
						inStr="";
					}
				}
			}
		}
		else{ /*file failed to open*/
			cerr << hmd << "::failed to open file:: " << i <<'\n';
			exit(1);
		}
		ifile.close();
	}
	return returnWords; 
}

/*prints the vector strings*/
void printCensored(vector<string> outwords){
	for(auto out: outwords){
		cout << out; 
	}
}
/*manages calling other functions*/
int main(int argc, char *argv[]){
	string words;
	vector<string> badWords, fileReader, finalCensor; 
	int dash = 0;

	if(argc < 2){ /*Check aruments greater than 1*/
		cerr << "Wrong amont of arguments provided (" << argc << ") in program: " << argv[0] << '\n';
		exit(1); 
	}

	for(int x =1; x< argc; x++){ /*go through all args*/
		string holder = argv[x];
		string argWords = "";  
		if(dash == 0){
			argWords = argv[x];
		}
		if(holder == "-"){ /*after dash*/
			dash = 1; 
			vector<string> fnames;
			string home = argv[0]; 
			if(argv[x+1]){ /*does arg past dash exist*/
				for(int endArg = x+1; endArg<argc; endArg++){ /*get all file names*/
					fnames.push_back(argv[endArg]); 
				}
				fileReader = maker(fnames, home);
			}
			else{
				while(getline(cin, words)){ /*get the standard input*/
					string inss; 
					for(auto j: words){

						if(j != ' ' && isalpha(j)){ /*combine words*/
							inss += j;
						}
						else{ 
							if(inss != ""){
								fileReader.push_back(inss);
							}
							inss = j;
							fileReader.push_back(inss);
							inss = "";
						}

					}
				}
				fileReader.push_back("\n");
			}
			/*get censored lines */
			finalCensor = censor(fileReader, badWords);
		}
		else{
			for(auto bd: badWords){
				if(argWords == bd){ /*if word already exists*/
					cerr << argv[0] << "::Multiple uses of " << argWords << '\n'; 
					exit(1);
				}
			} 
			if(argWords != ""){ /*see if argument word exists if so: add censor word to badword vector*/
				for(auto bad: argWords){ /*Check each char in string*/
					if(!isalpha(bad)){ /*Not alphabetical*/
						cerr << argv[0] << "::Invalid character used for censoring: " << bad << " in " << argWords << '\n';
						exit(1);
					}
				}
				badWords.push_back(argWords);
			}

		}
	}

	/*print final censored list*/
	printCensored(finalCensor); 
	return 0;
}
