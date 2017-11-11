// template demonstration application for camera badge
// new apps need to be added to list in applist.h

#include "cambadge.h"
#include "globals.h"

// states used by this application

#define s_start 0
#define s_run 1
#define s_freeze 2

//#define screen_char_width 21
#define theme_bgcolor rgbto16(100,120,168)
#define theme_namecolor butcol
#define theme_taglinecolor whi

#define name_handle "name"
#define name_tagline "something to say"


char* rainbowbadge(unsigned int action)
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
         plotblock(0, 0, dispwidth, 20, rgbto16(255,0,0));
         plotblock(0, 20, dispwidth, 20, rgbto16(255,165,0));
         plotblock(0, 40, dispwidth, 20, rgbto16(255,255,0));
         plotblock(0, 60, dispwidth, 20, rgbto16(0,128,0));
         plotblock(0, 80, dispwidth, 20, rgbto16(0,0,255));
         plotblock(0, 100, dispwidth, 20, rgbto16(75,0,130));
         plotblock(0, 120, dispwidth, 20, rgbto16(238,130,238));
         return(0);         
    } //switch
 
 if (action!=act_poll) return(0);
 
  // do anything that needs to be faster than tick here.
  
 if(!tick) return(0);
  
 
 switch(state) {
     case s_start :
       //printf(cls top butcol "EXIT" bot "Clear   Colour Freeze");
       printf(tabx2 taby6 theme_namecolor name_handle);
       printf(tabx2 taby7 theme_taglinecolor name_tagline);
       
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
 
 
