#include "Schedule.h"
#include <string>
#include <iostream> 
#include <vector>


// using namespace std; 
// Schedule::Schedule(){ }
// Schedule::Schedule(string name, string channel, int start, int lenght, bool adult): m_name(name), m_channel(channel), m_start(start), m_lenght(lenght), m_adult(adult){} 

Schedule::Schedule(const Schedule &num): m_name(num.m_name), m_channel(num.m_channel), m_start(num.m_start), m_lenght(num.m_lenght), m_adult(num.m_adult){}

Schedule::~Schedule() = default; 

int Schedule::add(string name, string channel, int start, int lenght, bool adult) {

    std::string holder; 

    if(start < 0){
        return -1; 
    }
    
    auto begin = (start * 15);  
    auto ending = lenght * 15;  
    string endtimes, starttimes;



    if(begin % 60 == 0){ 
        begin = begin / 60; 
        starttimes = std::to_string(begin) + ":00"; 

        if(ending < 60){ 
        endtimes =  std::to_string(begin) + ":" + std::to_string(ending); 
        }else if(ending == 60){ 
        auto begin1 = begin  + 1; 
        endtimes = std::to_string(begin1) + ":00" ;
        }else{
        double x = lenght % 4;
        ending = ending / 60;
        auto begin1 = begin + ending;
        if(x == 1){
            endtimes = std::to_string(begin1) + ":15"; 
        }else if(x == 2){
            endtimes = std::to_string(begin1) + ":30";        
        }
        else{
            endtimes = std::to_string(begin1) + ":45";
        }
    }
    }else{
        std::string minutes = std::to_string(begin % 60);
        begin = begin / 60; 
        starttimes = std::to_string(begin) + ":" + minutes;

        int si = stoi(minutes) + ending;  
        int houradd = std::abs(stoi(minutes) - ending);
        if(si < 60){
            endtimes =  std::to_string(begin) + ":" + std::to_string(si);
        }else if(si == 60){ 
            endtimes =  std::to_string(begin + 1) + ":00"; 
        }else{
            if(houradd >= 60){
                houradd = houradd - 60; 
                std::string extraZed; 
                if(houradd == 0){
                    extraZed = "0";
                }
                else{ 
                    extraZed = "";
                }
                endtimes =  std::to_string(begin + 2) + ":" + std::to_string(houradd) + extraZed;
            }
            // endtimes =  std::to_string(begin + 1) + ":" + std::to_string(houradd);
        }

    }//else{ begin %60 == begin + 15,30,45 }

    if(begin < 10){ //front and back 0 added 0:00
        starttimes = "0" + starttimes;
        if((ending/60)+begin < 10){
            endtimes = "0" + endtimes;
        }
    }else if(endtimes > "24:00"){ //no ending past 24:00
        return -1; 
    }

    for(int x =0; x < m_size; x++){
        if(starttimes == m_st[x]){
            if(channel == m_chanvect[x]){
                return -1; 
            }
        }
        if(endtimes > m_st[x]){
            if(channel == m_chanvect[x]){
                return -1; 
            } 
        }
    }
    holder = starttimes +"-"+ endtimes + " " + channel + " " + name; 
    m_timing.push_back(starttimes + "-" + endtimes); 
    m_chanvect.push_back(channel);

    m_st.push_back(starttimes); 
    m_ed.push_back(endtimes); 

    m_trueSize.push_back(static_cast<int>(channel.size()));

    if(adult == true){
        holder += "* \n";
        m_tvname.push_back(name + "* \n");  
    }else{
        holder += "\n";
        m_tvname.push_back(name + "\n");
    }

    if(static_cast<int>(channel.size()) > m_max){
        m_max = channel.size();
    }//Channel size

    m_sdl.push_back(holder);

    m_id++;
    m_ids.push_back(m_id);
//ID needs updating
    m_size++; 

    if(start >= 24 || start < 0){
        return -1; 
    }

    else{ 
        return m_id; 
    }

}

bool Schedule::add(string name, string channel, int start, int lenght){
    bool adult = false; 
    add(name, channel, start, lenght, adult); 
    return true; 
}

int Schedule::add(string, int, int, bool){

    return -1; 
}

int Schedule::size(){
    // std::vector<std::string> x;  
    return m_size;
}

bool Schedule::erase(int id){ 
    if(id < 0){ 
        return false; 
    }else{
        m_sdl.erase(m_sdl.begin()+id);

        m_chanvect.erase(m_chanvect.begin()+id);
        m_timing.erase(m_timing.begin()+id);
        m_tvname.erase(m_tvname.begin()+id);
        m_trueSize.erase(m_trueSize.begin()+id);
        m_ids.erase(m_ids.begin());
        m_st.erase(m_st.begin());
        
        m_id--;
        m_size--;
        return true; 
    }
}

void Schedule::print(){ 

    // for(auto i: m_sdl)
    // std::cout << i;

    for(auto i = 0; i < m_size; i++){
        std::string buff;
        int this_size = m_max - m_chanvect[i].size(); 
        // buff =" **" + std::to_string(this_size) +  "**";
        if(this_size-1 > 0){ 
            for(int z = 0; z < this_size; z++){
                buff += " ";
            }
        }
        
        std::cout << m_timing[i] << " " << m_chanvect[i] << " " << buff << m_tvname[i]; 
    }

}

void Schedule::print(std::ostream &a){ 
    if(a){
        // for(auto i: m_sdl)
        // std::cout << i; 

        for(auto i = 0; i < m_size; i++){
        std::string buff;
        // int this_size = static_cast<int>(m_trueSize[i]);
        int maxx = 0;
        for(int k: m_trueSize){
            if(maxx < k){
                maxx = k; 
            }
        } 
        maxx = maxx - m_trueSize[i];
        for(int d = 0; d < maxx; d++){
            buff += " ";
        }
        
        std::cout << m_timing[i] << " " << m_chanvect[i] << " " << buff << m_tvname[i]; 
    }
    }
    
}

std::ostream &operator<<(std::ostream &os, const Schedule &l){
    auto num = l.m_sdl[1]; 
    return os << num;
}
