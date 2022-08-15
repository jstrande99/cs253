#include "Schedule.h"
#include <exception>
#include <string>
#include <iostream> 
#include <vector>

using namespace std;

Show::Show(const string &name, const string &channel, int start, int length, bool adult): m_name(name), m_channel(channel), m_start(start), m_length(length), m_adult(adult), m_id(m_identity++){
    string starttime, endtime;
    int endSt, mins, hours, endmins, endhours;
    /*Error check*/
    if(start < 0 || (start*15)/60 >= 24){
        throw runtime_error("Invalid start time provided ");
    }
    if(channel == "" || name == ""){
        throw runtime_error("Missing name or channel");
    }
    else{ 
        /*Time calculations*/
        start = start * 15;
        mins = start % 60; 
        hours = start / 60; 
        endSt = start + (length * 15); 
        endmins = endSt % 60; 
        endhours = endSt / 60;

        if(endhours > 24){
            throw overflow_error("Invalid end time provided"); 
        }
        else{ /*change the format of the show time*/
            string sminHolder, eminHolder; 
            /*Correcting format of the minutes*/
            if(mins == 0){ 
                sminHolder += "00"; 
            }else{
                sminHolder += to_string(mins); 
            }
            if(endmins == 0){
                eminHolder += "00";
            }else{
                eminHolder += to_string(endmins);
            }
            /* Correcting format of the hours*/
            if(hours < 10){ 
                starttime = "0" + to_string(hours); 
            }else{
                starttime = to_string(hours);
            }
            if(endhours < 10){
                endtime = "0" + to_string(endhours);
            }else{
                endtime = to_string(endhours);
            }
            starttime += ":" + sminHolder; 
            endtime += ":" + eminHolder;
        }
    }
 

    /*Update running varibles*/
    m_start = start; 
    m_channel = channel;
    m_name = name; 
    m_length = length * 15;
    m_adult = adult;
    m_times = starttime + "-" + endtime; 

}
