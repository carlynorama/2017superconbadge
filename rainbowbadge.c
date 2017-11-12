// template demonstration application for camera badge
// new apps need to be added to list in applist.h

#include "cambadge.h"
#include "globals.h"

// states used by this application

#define s_start 0
#define s_run 1
#define s_freeze 2

//theme_bgcolor not used in this case
//#define screen_char_width 21
#define theme_bgcolor rgbto16(100,120,168)
#define theme_namecolor butcol
#define theme_taglinecolor whi

//the last color sops up any remainder. For 7 colors it's only about a pixel. 
#define rainbow_numberofcolors 7
const unsigned short rainbowcols[rainbow_numberofcolors] = {
    rgbto16(255,0,0), rgbto16(255,165,0), rgbto16(255,255,0), rgbto16(0,128,0), rgbto16(0,0,255), rgbto16(75,0,130), rgbto16(238,130,238)
};

#define name_handle "name"
#define name_tagline "something to say"


char* rainbowbadge(unsigned int action)
{
  static unsigned int state,colour;
  unsigned int x,y,i;
  
  switch(action) {
     case act_name : return("RAINBOW");
     case act_help : return("Show your colors");
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
         unsigned int barheight = dispheight/rainbow_numberofcolors;
         for( i  = 0; i < rainbow_numberofcolors-1; i = i + 1 ){
             plotblock(0, i*barheight, dispwidth, barheight, rainbowcols[i]);
         }


         return(0);         
    } //switch
 
 if (action!=act_poll) return(0);
 
  // do anything that needs to be faster than tick here.
  
 if(!tick) return(0);
  
 
 switch(state) {
     case s_start :
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
 
 if(butpress & powerbut) return(""); // exit with nonzero value to indicate we want to quit

 return(0);
 
}
 
 
