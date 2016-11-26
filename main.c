#include <allegro.h>
#include <math.h>

//timer
volatile int ticks = 0;
void ticker()
{
	ticks++;
}
END_OF_FUNCTION(ticker)
//timer

int main(void) 
{	
	allegro_init();
	install_keyboard();
	install_timer();
	//initialize the timer
	LOCK_VARIABLE(ticks);
	LOCK_FUNCTION(ticker);
	install_int_ex(ticker, MSEC_TO_TIMER(20)); //timer (every 20 mseconds calls the ticker function)
	
	set_color_depth(32);
//	set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, 640, 480, 0, 0); //go to graphic mode
//	set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, 640, 480, 0, 0); //go to graphic mode
	int res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	if (res != 0) {
 		allegro_message(allegro_error);
		exit(-1);
	}


	BITMAP* buffer = create_bitmap(640,480);
	
	int x=32,y=96,hspeed=0,vspeed=0,col_hspeed,col_vspeed, ax,ay,onfloor=0; 
    int a,b;

    int playing=1;	
	set_color_depth(32);
	BITMAP *hero=load_bitmap("hero.bmp",0);
	BITMAP *fence=load_bitmap("fence.bmp",0);
	BITMAP *back=load_bitmap("back.bmp",0);
    BITMAP *bear=load_bitmap("bear.bmp",0);
    BITMAP *gate=load_bitmap("gate.bmp",0);	
	int map_x=18,map_y=9,i,j;
	int map[10][19];
  int level=0;
  
  //level 0 x/y=25,17,13,/33, 1 x/y=581/33
#include "Libs\arraycol.h"

	while(!key[KEY_ESC]){ 
                    while(ticks == 0)
		{
			rest(1);
		}
		
		while(ticks > 0) //it only works if ticks is 1 (so there is a frame every 20 mseconds)
		{
			

for (a=0;a<10 ;a++)
    for (b=0;b<19;b++)
    map[a][b]=map_all[level][a][b];
 
 clear_bitmap(buffer);
hspeed=(key[KEY_LEFT]-key[KEY_RIGHT])*4; //move left-right
vspeed+=1; //gravity

if ((onfloor==1) && (key[KEY_UP])) {vspeed=-14;} //jump if there is floor under you and if up-key is pressed

//collision
install_collision(x,y,30,30,hspeed,vspeed); //checks for collisions with the map (function declared in arraycol.h)
hspeed=col_hspeed;
vspeed=col_vspeed;
x+=hspeed; //move in the x-axis
y+=vspeed; //move in the y-axis
draw_sprite(buffer,back,32,-15);

//if (level==0 && y==33 && (x==25||x==13||x==17))
if ( y==33 && (x==25||x==13||x==17))
 level=1;
 
draw_sprite(buffer,hero,x,y);
draw_sprite(buffer,bear,205,97);




                   

rect(buffer, 16, 330, 130, 420, makecol(255, 255, 255));

textprintf_ex(buffer, font, 30,340, makecol(255, 255, 255),-1, "x: %d",x);           
textprintf_ex(buffer, font, 30,350, makecol(255, 255, 255),-1, "y: %d",y);
textprintf_ex(buffer, font, 30,360, makecol(255, 255, 255),-1, "Level: %d",level+1);    
                    
textprintf_ex(buffer, font, 30,380, makecol(255, 255, 255),-1, "onfloor: %d",onfloor);    

textprintf_ex(buffer, font, 30,390, makecol(255, 255, 255),-1, "hspeed: %d",hspeed);  
textprintf_ex(buffer, font, 30,400, makecol(255, 255, 255),-1, "vspeed: %d",vspeed);                  



textprintf_ex(buffer, font, 300,400, makecol(255, 255, 255),-1, "Shruti Pohane");                    
                                                           
for(j=0;j<=map_y;j++) {for (i=0;i<=map_x;i++)
 {
                      if (map[j][i]>0) draw_sprite(buffer,fence,(i)*32,(j)*32);
                      if (map[j][i]==-1) draw_sprite(buffer,gate,(i)*32,(j)*32);
}}; //draws the map
  
blit(buffer, screen, 0, 0, 0, 0, 640,480);


    ticks=0;}
			 
}
	
	return 0;
}
END_OF_MAIN();





