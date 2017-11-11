// template demonstration application for camera badge
// new apps need to be added to list in applist.h

#include "cambadge.h"
#include "globals.h"

// states used by this application

#define s_start 0
#define s_run 1
#define s_freeze 2

#define name_handle "name"
#define name_tagline "something\n   to say"


char* basicbadge(unsigned int action)
{
  static unsigned int state,colour;
  unsigned int x,y,i;
  
  switch(action) {
     case act_name : return("YOURNAMEHERE");
     case act_help : return("A place to put\nyour name");
     case act_init :
         // add any code here that needs to run once at powerup - e.g. hardware detection/initialisation      
            return(0);   
     
     case act_powerdown :
          // add any code here that needs to run before powerdown
         return(0);
         
     case act_start :  
         // called once when app is selected from menu
         state=s_start;
         colour=1;
         return(0);         
    } //switch
 
 if (action!=act_poll) return(0);
 
  // do anything that needs to be faster than tick here.
  
 if(!tick) return(0);
  
 
 switch(state) {
     case s_start :
       //printf(cls top butcol "EXIT" bot "Clear   Colour Freeze");
       printf(tabx2 taby6 butcol name_handle);
       printf(tabx2 taby7 whi name_tagline);
       
       state=s_run;
       
  
     case s_run :         

       if(butpress & but3) state=s_freeze;
       break;
 
     case s_freeze : 
       if(butpress) state=s_run;
       break;
 
 } // switch state
 
 if(butpress & but1) state=s_start;  // clear screen & restart
 if(butpress & but2) if(++colour==8) colour=1;
 
 
     
       
 
 if(butpress & powerbut) return(""); // exit with nonzero value to indicate we want to quit

 return(0);
 
}
 
 
