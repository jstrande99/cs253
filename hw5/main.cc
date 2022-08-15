#include <iostream>
#include <unistd.h>
#include <string>
#include <vector> 
#include <fstream>

using namespace std; 

// open files
auto openFile(vector<string> names, string proName, bool nameF){
    string word, holder;
     
    for(auto i: names){ // iterate through multiple filenames
        if(nameF){ //if -v is called display filename
            holder += "Reading " + i + "\n";
        }
        ifstream newFile(i); // open files 
        if(newFile.is_open()){ // if open get contents 
            while(getline(newFile, word)){
                holder += word + "\n"; 
            }
        }else{ // falure to open file
            cerr << proName << ": failed to open \"" << i << "\"\n";
            exit(1);
        }
        newFile.close(); 
    }
    return holder;
}

// iterate through the string and censor the words
auto censorWords(string instr, string cenWord, vector<string> toBeCen, bool cap){
    string finalString, tempStr, hold, holdcap;  
    int cn = 0;
    for(auto c: instr){ // go through string conents 
        if(c != ' ' && c != '\n' && isalpha(c)){ 
            tempStr += c; 
            for(auto v: toBeCen){ // go through words needing to be censored 
                if(cap){ // if -i is called then send all censorship chars to uppercase for checking 
                    for(auto k: v){
                        hold += toupper(k);
                    }
                    for(auto k: tempStr){
                        holdcap += toupper(k);
                    }
                }else{ // if -i isn't called censorship chars stay the same 
                    hold = v; 
                    holdcap = tempStr;
                }
                if(holdcap == hold && !isalpha(instr[cn + 1])){ // if word in string is equal to the word to be censored
                    tempStr = cenWord; 
                }
                holdcap = "";
                hold ="";
            }
        }
        else{
            finalString += tempStr; // add the word to the return string 
            // if(c == ' '){ // keep spaces
            //     finalString += " "; 
            // }else if(c == '\n'){ // keep new line 
            //     finalString += "\n";
            if(!isalpha(c)){
                finalString += c; 
            }
            tempStr = ""; // reset the word string holder
        }
        cn += 1;
    }
    return finalString; 
}

void print(string outstr){
    for(auto j: outstr){
        cout << j; 
    }
}
int main(int argc, char *argv[]){
    if(argc < 2){ // if arguments are less than 2 then fail 
        cerr << argv[0] << ": Invaliad number of required feilds.\n";
        exit(1);
    } 
    vector<string> fname;
    string words, strWords, finalString, s;
    string censorWord = "CENSORED"; 
    vector<string> tbCensored; 
    int x; 
    string proName = argv[0];
    bool r = false; 
    bool caps = false; 
    bool fileN = false; 

    // get options colons require string after 
    while((x = getopt(argc, argv, "r:c:iv")) != -1){
        switch(x){ 
            case 'r':
                s = optarg;
                if(r){ // if r already exists
                    cerr << proName << " failed to run with two instances of -r\n";
                    exit(1);
                }
                censorWord = s; // set censorship
                r = true; // set flag to true
                break;
            case 'c':
                s = optarg; 
                for(auto i: s){ // iterate through to be censored word and check that it is alphabetical
                    if(!isalpha(i)){
                        cerr << proName << " error -c requires alphabetical letters only " << i << " was entered.\n";
                        exit(1);
                    } 
                    for(auto z: tbCensored){ // iterate through already added words to be censored and compare with new input word
                        if(s == z){
                            cerr << proName << " duplicate word to be censored entered: \"" << s << "\" was entered.\n";
                            exit(1);
                        }
                    }
                }
                tbCensored.push_back(s);   // add new word to vector
                break;
            case 'i':
                caps = true; // capital independent true flag 
                break;
            case 'v': 
                fileN = true; // display filename set flag to true
                break;
            default: 
                exit(1);
                break; 
        }
    }
    for(auto j: tbCensored){ //see if words to be censored is the same as the word it will be changed to
        if(censorWord == j){
            cerr << proName << ": Word to be censored \"" << j << "\" matches censoring word \"" << censorWord << "\"\n";
            exit(1);
        }
    }
    if(argv[optind]){ // if argv's next exists (FILE)
        while(argc > optind){ // if index is less than the argument count then add file to vector 
            fname.push_back(argv[optind]);
            optind++; 
        }
        strWords = openFile(fname, proName, fileN); // call openFIle to open the files  
    } 
    else{ // read from standard input
        if(fileN){
            strWords = "Reading Standard Input\n";
        }
        while(getline(cin, words)){ // read line by line 
            strWords += words +'\n';
        }
    }
    finalString = censorWords(strWords, censorWord, tbCensored, caps); // call censorWords for censoring the strings


    print(finalString);

}