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
...........
...........
...........
...........
...........
...........
...........
	
blit(buffer, screen, 0, 0, 0, 0, 640,480);


    ticks=0;}
			 
}
	
	return 0;
}
END_OF_MAIN();





