#ifndef SCHEDULE_H_INCLUDED
#define SCHEDULE_H_INCLUDED

#include <string>
#include <iostream>
#include <vector>

class Schedule{
   using string = std::string; 
   // using vector = std::vector; 
   public:
      Schedule() = default;
      Schedule(const Schedule &);
      Schedule(string name, string channel, int start, int lenght, bool adult); 
	   ~Schedule();
      int add(string name, string channel, int start, int lenght, bool adult);
      int add(string, int, int, bool);
      bool add(string name, string channel, int start, int lenght);
      int size();
      // bool erase(auto id);
      bool erase(int id); 
      void print( );
      void print(std::ostream &);

   private:
      string m_name, m_channel; 
      int m_start, m_lenght; 
      bool m_adult; 
      int m_size = 0; 

      std::vector<string> m_sdl;
      std::vector<string> m_timing; 
      std::vector<string> m_chanvect;
      std::vector<string> m_tvname; 
      std::vector<int> m_trueSize;
      std::vector<int> m_ids;
      std::vector<string> m_st; 
      std::vector<string> m_ed; 


      int m_id = 1;
      int m_max = 0;

      
      friend std::ostream &operator<<(std::ostream &, const Schedule &);

};

#endif /* SCHEDULE_H_INCLUDED */
