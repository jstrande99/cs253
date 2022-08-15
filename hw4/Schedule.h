#ifndef SCHEDULE_H_INCLUDED
#define SCHEDULE_H_INCLUDED

#include <string>
#include <iostream>
#include <vector>

class Show{
   using string  = std::string;

   public:
      Show() = delete; /*delte the default ctor. makes Show s not compile*/
      Show(const string &name, const string &channel, int start, int length, bool adult=false); /*Copy Constructor*/
      Show &operator=(const Show&); /*Assignment operator*/

      /* GETTER / SETTERS */
      string name() const {return m_name;}
      string channel() const {return m_channel;}
      int start() const {return m_start;}
      int length() const {return m_length;}
      bool adult() const {return m_adult;}
      int id() const {return m_id;}
      string getTimes() const {return m_times;}

   private:
      string m_name, m_channel, m_times; 
      int m_start, m_length;
      bool m_adult; 
      int m_id; 
      static inline int m_identity = 100;
};

class Schedule{
   using string = std::string; 
   public:
      Schedule(); /*defualt ctor*/
      Schedule(const Schedule &); /*copy ctor */
      Schedule &operator=(const Schedule&); /*Assignment operator*/
      ~Schedule(); /*dtor*/
      size_t size() const {return m_schedule.size();}
      Schedule operator[](size_t rhs);
      Schedule &operator+=(const Show&);
      Schedule &operator+=(const Schedule&);
      Schedule operator+(const Schedule&);
      Schedule &operator-=(int ident);

      string name() const {return m_schedule[0][0];}
      string channel() const {return m_schedule[0][1];}
      int start() const {return stoi(m_schedule[0][2]);}
      int length() const {return stoi(m_schedule[0][3]);}
      bool adult() const {if(m_schedule[0][4] == "*"){return true;}else{return false;}}

      friend std::ostream &operator<<(std::ostream&, const Schedule&);
	    
   private:
      size_t m_size;
      std::vector<std::vector<string>> m_schedule;  
};

std::ostream &operator<<(std::ostream&, const Schedule&);

#endif /* SCHEDULE_H_INCLUDED */
