#include <iomanip>	// for right, setw
#include <iostream>
#include <map>
#include <string>

using namespace std;

template <typename T>
class BarGraph {
  public:
    void operator+=(const T &datum) {
        data[datum]++;
    }
    friend ostream& operator<<(ostream &os, BarGraph barG){
	    for (const auto &val : barG.data)
	        os << right << setw(10) << val.first << ' '
		    << string(val.second, '*') << '\n';
            os << '\n';
            return os; 
    }
  private:
    map<T, unsigned> data;
};

template <>
class BarGraph<bool> {
    unsigned false_count = 0, true_count = 0;
  public:
    void operator+=(bool datum) {
	datum ? true_count++ : false_count++;
    }
    friend ostream& operator<<(ostream &os, BarGraph barG){
        os << right << setw(11) << "false " << string(barG.false_count, '*') << "\n"
                << right << setw(11) << "true " << string(barG.true_count,  '*') << "\n\n";
        return os; 
    }
};

template <>
class BarGraph<char>{
    public: 
        void operator+=(string c){
            for(auto i: c){
                if(i != ' '){
                    i = tolower(i);
                    data[(int) i]++; 
                    letter[(int) i] = i;
                } 
                else{
                    data[(int) i]++; 
                    letter[(int) i] = '_'; // DISPLAY SPACE AS '_' 
                }
            }
        }
        void operator+=(char c){
            c = tolower(c);
            data[(int) c]++; 
            letter[(int) c] = c; 
        }
        friend ostream& operator<<(ostream &os, BarGraph barG){
            int count = 0; 
            for(auto val: barG.data){
                if(val > 0){
                    os << right << setw(10) << barG.letter[count] << ' ' << string(val, '*') << '\n';
                }
                count++; 
            }

            os << '\n';
            return os; 
        }
    private:
        unsigned int data[255] = {0};
        unsigned char letter[255] = {'!'};
};

int main() {
    BarGraph<int> alpha;
    alpha += 12;
    alpha += 6;
    alpha += 4;
    alpha += 6;
    cout << alpha;

    BarGraph<double> beta;
    beta += 3.14;
    beta += 2.71828;
    beta += 6.023e23;
    beta += 2.71828;
    cout << beta;

    BarGraph<bool> gamma;
    gamma += false;
    gamma += true;
    gamma += false;
    gamma += true;
    gamma += true;
    cout << gamma;

    BarGraph<char> delta;
    delta += 'G';
    delta += 'e';
    delta += 'o';
    delta += 'f';
    delta += 'f';
    delta += "Colorado";
    cout << delta;

    return 0;
}
