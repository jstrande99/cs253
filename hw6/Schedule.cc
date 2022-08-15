#include "Schedule.h"
#include <exception>
#include <stdexcept>
#include <string>
#include <iostream> 
#include <vector>
#include <set>

using namespace std; 
/*default ctor*/
Schedule::Schedule(){}
/*copy ctor*/ 
Schedule::Schedule(const Schedule &val): m_schedule(val.m_schedule){}
/*dtor*/
Schedule::~Schedule(){}

struct showStruct{
    string t,c,n,a,d,s,e; 
};
struct comparess{
    bool operator()(const showStruct &x, const showStruct &y) const {
        return (x.t != y.t) ? x.t < y.t : x.c < y.c;
    }
};
bool Schedule::makeOrder(){
    set<showStruct, comparess> showSet = {}; 
    for(size_t p=0; p < m_schedule.size(); p++){
        for(size_t inner =0; inner < m_schedule[p].size(); inner++){
            showSet.insert({m_schedule[p][5], m_schedule[p][1], m_schedule[p][0], m_schedule[p][4], m_schedule[p][6], m_schedule[p][2], m_schedule[p][3]});

            m_set.insert({m_schedule[p][5], m_schedule[p][1], m_schedule[p][0], m_schedule[p][4], m_schedule[p][6], m_schedule[p][2], m_schedule[p][3]});

        }
    }
    m_schedule.clear();
    for(auto x: showSet){
        m_schedule.push_back({x.n, x.c, x.s, x.e, x.a, x.t, x.d});

    }
    return 0;
}

/*add a show to schedule*/
Schedule &Schedule::operator+=(const Show& rhs){ 
    vector<string> hold; 
    int flag = 0; 
    if(m_schedule.size() != 0){
        for(size_t x = 0; x < m_schedule.size(); x++){
            if(rhs.channel() == m_schedule[x][1]){
                if(rhs.start() == stoi(m_schedule[x][2]) ){
                    flag = 1;
                    throw runtime_error("Overlapping times while adding show to schedule");
                }
            }
        }
    }else{
        flag = 0; 
    }
    /*if passes error checking, add*/
    if(flag == 0){ 
        hold.push_back(rhs.name());
        hold.push_back(rhs.channel());
        string starter = to_string(rhs.start());
        hold.push_back(starter);
        string ender = to_string(rhs.length());
        hold.push_back(ender);
        if(rhs.adult() == true){
            hold.push_back("*"); 
        }else{
            hold.push_back(" ");
        }
        hold.push_back(rhs.getTimes());
        hold.push_back(to_string(rhs.id()));
        m_size++;
        m_schedule.push_back(hold);
        makeOrder(); 
    }
    return *this;
}
/*remove element at id*/
Schedule &Schedule::operator-=(int ident){
    bool isID = false;
    for(size_t i = 0; i < m_schedule.size(); i++){
        /*if id found, erase*/ 
        if(stoi(m_schedule[i][6]) == ident){ 
            m_schedule.erase(m_schedule.begin()+ i);
            m_size--;
            isID = true; 
        }else{
            isID = false; 
        }
    } 
    /*id not found*/
    if(isID == false){
        throw runtime_error("Invalid ID entered");
    }
    return *this;
}
/*assignment operator*/
Schedule &Schedule::operator=(const Schedule &rhs){
    m_schedule = rhs.m_schedule;
    return *this;
}
/*add schedule to schedule*/
Schedule Schedule::operator+(const Schedule &rhs){
    Schedule newSched(*this); 
    bool flag = false;
    for(size_t i=0; i < newSched.m_schedule.size(); i++){
        for(size_t x=0; x < rhs.m_schedule.size(); x++){
            /*Check over lapping times*/
            if(newSched.m_schedule[i][1] == rhs.m_schedule[x][1] && newSched.m_schedule[i][2] < rhs.m_schedule[x][2] + rhs.m_schedule[x][3]){
                flag = false;
                throw runtime_error("Overlapping times while adding schedule");
            }else{
                flag = true;
            }
        }
    }
    /*if show doesnt overlap, add schedules*/
    if(flag == true){
        newSched.m_schedule.push_back(rhs.m_schedule[0]); 
        newSched.m_size = newSched.m_schedule.size();
    }
    /*return new schedule*/
    return newSched;
}
/*get show at index*/
Schedule Schedule::operator[](size_t rhs){
    Schedule foundSched;
    /*if index doesn't exist*/
    if(m_schedule[rhs].size() == 0){
        string err = "Index out of bounds: " + to_string(rhs) + " Schedule size is: " + to_string(m_schedule.size()); 
        throw range_error(err);
    }
    else{ /*else add element to return*/
        foundSched.m_schedule.push_back(m_schedule[rhs]);
    }
    return foundSched; 
}
/*add schedule to existing schedule*/
Schedule &Schedule::operator+=(const Schedule& rhs){
    /*if schedule is empty, add rhs schedule*/
    if(m_schedule.size() == 0){
        for(size_t x = 0; x < rhs.m_schedule.size(); x++){
            m_schedule.push_back(rhs.m_schedule[x]);
        }
    }else{ 
        for(size_t x = 0; x < rhs.m_schedule.size(); x++){
            bool flag = false; 
            for(size_t i = 0; i < m_schedule.size(); i++){
                /*error checking*/
                if(rhs.m_schedule[x][1] == m_schedule[i][1] && rhs.m_schedule[x][2] < m_schedule[i][2] + m_schedule[i][3] && rhs.m_schedule[x][2] >= m_schedule[i][2]){
                    flag = false; 
                    throw runtime_error("Overlapping shows in schedules");
                }else{
                    flag = true; 
                }
            }
            /*if no error, add rhs to lhs schedule*/
            if(flag == true){
                m_schedule.push_back(rhs.m_schedule[x]);
            }
        }
    }
    return *this; 
}

void Schedule::grups(bool flag){
    grupFlag = flag;
}

Schedule::iterator::iterator(const set<Schedule::shows, Schedule::compares> *mySet, size_t ind) : m_newSet(mySet), m_index(ind) {}

Schedule::iterator::iterator(const Schedule::iterator &rhs) : m_newSet(rhs.m_newSet), m_index(rhs.m_index){}

Schedule::iterator Schedule::begin() const {
    return iterator(&m_set, 0);
}
Schedule::iterator Schedule::end() const { 
    return iterator(&m_set, m_set.size());
}
Schedule::iterator &Schedule::iterator::operator++(){
    ++m_index;
    return *this;
}
Schedule::iterator Schedule::iterator::operator*() const {
    return *this;
}


bool Schedule::iterator::operator==(const Schedule::iterator& rhs) const {
    return (m_index == rhs.m_index);
}
bool Schedule::iterator::operator!=(const Schedule::iterator& rhs) const {
    return !(*this == rhs);
}
/*send to os*/
ostream &operator<<(ostream &os, const Schedule &sched){
    size_t maxChannel = 0;  
    /*find max length of channels in schedule*/
    for(size_t x = 0; x < sched.m_schedule.size(); x++){
        if(sched.m_schedule[x][1].size() > maxChannel){ 
            maxChannel = sched.m_schedule[x][1].size(); 
        }
    }
    for(size_t i = 0; i < sched.m_schedule.size(); i++){
        string buff;
        /*add buffer spaces for formating*/
        if(maxChannel-sched.m_schedule[i][1].size() > 0){
            for(size_t x=0; x < maxChannel-sched.m_schedule[i][1].size()+1; x++){
                buff += " ";
            }
        }
        else{
            buff = " ";
        }
        /*make string for printing*/
        string holder = "";
        /*send to ostream os*/
        if(sched.grupFlag == 0){
            if(sched.m_schedule[i][4] == "*"){
                continue;
            }
            else{ 
                holder = sched.m_schedule[i][5] + " " + sched.m_schedule[i][1] + buff + sched.m_schedule[i][0];
            }
        }
        else{
            holder = sched.m_schedule[i][5] + " " + sched.m_schedule[i][1] + buff + sched.m_schedule[i][0] + " " + sched.m_schedule[i][4];
        }
    os << holder << '\n';
    } 
    return os;
}
