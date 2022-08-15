#include <iostream> 
#include <unistd.h>
#include <time.h> 
#include <stdio.h>
#include <stdlib.h>
#include <iomanip> 
#include <fstream>
#include <cctype>
#include <algorithm>

using namespace std; 
string program; 

string getForm(char *argv){ 
	string x = argv; 
	int size = x.length(); 
	string arg = " ";
	
	char buf[64]; 
	time_t t; 
	struct tm *tmp; 
	t = time (NULL); 
	tmp = localtime(&t);
	
	
	
	for(int i = 0; i < size; i++){ 
		int j = 0; 
		if(x[i] == '%'){ 
			while((x[i + j] != ' ')){
				if(x[i + j] != '\0'){  
					arg += x[i + j];
					j++; 
				} 
				else{
					break;
				}
			}
			arg += " "; 
		}  
	} 
	
	strftime(buf, sizeof(buf), argv, tmp); 
	//cout << buf << '\n'; 

return x; 
}
int splitY(const string input){
		int in = input.length();
		int count = 0;

		for(int i = 0; i < in; i++){
			if(!isdigit(input[i])){
				/*if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')){ 
					cerr << "Unable to process letters" << program << "\n"; 
					exit(1);
				} 
				else{ 
					break;
				} */
				break;
			}
			else {
				count++;	
			}			
			if(input[i]){ 
				if(isspace(input[i])){ 
					cerr << "There is a space detected" << program << "\n"; 
					exit (1);
				}
			}
		}
	string n = input.substr(0, count);
	int y = stoi(n);
	return y; 
}
int splitD(const string input){ 
		int in = input.length();
		int count = 0;

		for(int i = 0; i < in; i++){

			if(!isdigit(input[i])){
				if(input[i] != '.'){ 
					cerr << "The symbol " << input[i] << " is not within bounds" << program << ".\n"; 
					exit (1);
				}
				if(input[i] == '.' && input[i+1] == '.'){
					cerr << "Too many periods found" << program << "\n";
					exit(1);
				}
				else { 
					break;
				}
			}
			else {
				count++;
			}
			if(input[i]){ 
				if(isspace(input[i])){ 
					cerr << "There is a space detected" << program << ".\n"; 
					exit (1);
				}
			}
		}

		string k = input.substr(count + 1);
		int d = stoi(k);
		
		return d;
	}

int main(int argc, char *argv[]){ 
	program = argv[0]; 
	int year = 0; 
	int day = 0; 
	int opt; 
	int index = 0;  
	string form = " ";
	//int fnd = 0; 
	//int ifnd = 0; 
	//int vfnd = 0; 
	string val = " "; 
	string filename = " ";
	time_t rt; 
	struct tm *ptr; 
	const char *weekday[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	const char *month[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}; 
	//const char *month[] = {"Dec", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov"};

	while((opt = getopt(argc, argv, "f:vi")) != -1){ 
		switch(opt){ 
			case 'f':
				index = optind;
				//fnd = 1; 
				form = getForm(optarg); 
				//form = optarg;
				break; 
			case 'i':  
				index++;
				//ifnd = 1; 
				break; 
			case 'v': 
				index++;
				//cout << "*** Processing " << argv[index] << "\n"; 
				filename = argv[optind];
				//vfnd = 1; 
   				break; 
			default:
				cerr << argv[1] << " is not supported " << program << "\n";
				exit(1);  
				break; 
		}
	}
	//printf("F: %d I: %d V: %d\n", fnd, ifnd, vfnd); 
	//transform(val.begin(), val.end(), val.begin(), ::toupper);
	//if(val == "YESTERDAY"){ 
	//	cout << "HEREEEE: " << val << '\n';
	//} 
	/*else if(optind > argc){ 
		cerr << "Expected argument after options " << program << "\n"; 
		exit(1); 
	} */

	if(optind < argc){ 
		ifstream inputFile; 
		inputFile.open(filename);
		if(inputFile.fail()){ 
			cerr << "File has failed to open " << program << '\n';
			exit(1); 
		}
		else if(inputFile){ 
			cout << "*** Processing " << argv[index] << "\n"; 
		} 
	}
	else{ 
		cout << "*** Processing standard input  " << "\n"; 
		for(string str; getline(cin, str);){ 
			transform(str.begin(), str.end(), str.begin(), ::toupper); 
			//cout << str << '\n';
			if(str.empty()){ 
				cerr << "Blank line detected" << program << "\n";
				exit (1); 
			}
			/*if(str.find('.') >= str.length()){ 
				cerr << "Entered date is invalid" << program << "\n"; 
				exit (1);
			}
			else{
				year = splitY(str);
				day = splitD(str);
			}

			if(year <= 0 || year > 9999){
				cerr << "Entered year not in range" << program << "\n"; 
				exit (1);
			}
			if(day <= 0 || day > 366){ 
				cerr << "Entered day not in range" << program << "\n"; 
				exit (1);
 			}*/
 			if(str == "YESTERDAY"){ 
 				//if(fnd == 1){ 
 					//cout << "HEREEEE" << '\n';
 					form = getForm(optarg); 
 				//}
 			}
 			else if(str == "TODAY"){ 
 				//cout << "DONE" << '\n';
 				
 			}
 			time(&rt);
			ptr = localtime(&rt);  
			ptr->tm_year = year - 1900; 

			ptr->tm_mday = day; 
			ptr->tm_mon = 0;   //reset to jan instead of feb

			mktime(ptr);
			cout << weekday[ptr->tm_wday] << " " << setfill('0') << setw(2) << ptr->tm_mday << " " << month[ptr->tm_mon] << " " << setfill('0') << setw(4) << year << "\n";

		}
	}
}
