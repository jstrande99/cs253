#include <iostream>
#include <time.h>
#include <iomanip>

	using namespace std;
	string program;

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

	int main(int , char* argv[]){
		program = argv[0];
		int day = 0; 
		int year = 0; 
		time_t rt; 
		struct tm *ptr; 
		const char *weekday[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		const char *month[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}; 
		//const char *month[] = {"Dec", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov"};

		for(string str; getline(cin, str);){
			if(str.empty()){ 
				cerr << "Blank line detected" << program << "\n";
				exit (1); 
			}
			if(str.find('.') >= str.length()){ 
				cerr << "Entered date is invalid" << program << "\n"; 
				exit (1);
			}
			
			else{
				year = splitY(str);
				day = splitD(str); 
				//cout << "year: " << year << " day: " << day << "\n"; 
			}

			if(year <= 0 || year > 9999){
				cerr << "Entered year not in range" << program << "\n"; 
				exit (1);
			}
			if(day <= 0 || day > 366){ 
				cerr << "Entered day not in range" << program << "\n"; 
				exit (1);
 			}

			time(&rt);
			ptr = localtime(&rt);  
			ptr->tm_year = year - 1900; 

			ptr->tm_mday = day; 
			ptr->tm_mon = 0;   //reset to jan instead of feb

			mktime(ptr);
			cout << weekday[ptr->tm_wday] << " " << setfill('0') << setw(2) << ptr->tm_mday << " " << month[ptr->tm_mon] << " " << setfill('0') << setw(4) << year << "\n";

		}
		return 0;
	}
