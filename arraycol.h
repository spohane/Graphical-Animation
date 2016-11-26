#ifndef _arraycol_
#define _arraycol_
	int map_all[3][10][19] = {{    //installs the map (1-solid block ; 0-free)
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,
        1,0,0,0,0,1,1,1,0,0,0,1,1,1,1,0,1,1,1,
        1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,
        1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,
        1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
        },
        {    
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
        1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,
        1,1,1,1,1,0,1,1,0,0,0,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
        },
        {    
        1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
        1,0,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
        1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,
        1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,
        1,1,1,0,0,0,1,1,0,0,0,0,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
        }};


int map_xy(int q,int w)
{
    if ((q/32<=map_x)&&(w/32<=map_y)&&(w/32>=0)&&(q/32>=0)) return map[(w/32)][(q/32)];
    else return 0;
}
END_OF_FUNCTION(map_xy);

int verline_collision(int nx,int ny,int ny2) //check for collisions in a vertical line
{
    int i;
    for (i=ny;i<=ny2;i++) {if (map_xy(nx,i)) return 1;};
    return 0;
}

int horline_collision(int nx,int nx2,int ny) //check for collisions in a horizontal line
{
    int i;
    for (i=nx;i<=nx2;i++) {if (map_xy(i,ny)) return 1;};
    return 0;
}
    



void install_collision(int nx,int ny,int nw,int nh, int n1, int n2)
{ 
     onfloor=0;
     col_hspeed=n1;
     col_vspeed=n2;
     if (n1>0) {if (verline_collision(nx+nw+n1,ny,ny+nh)) {col_hspeed=(((nx+nw)/32+1)*32)-nx-nw-1;} //if hspeed>0 and there is a block on the right, get close to the block
                                                       else col_hspeed=n1;} //if there is no block, do nothing
     if (n1<0) {if (verline_collision(nx+n1,ny,ny+nh)) col_hspeed=nx/32*32-nx+1; //the same but if the direction is to the left
                                                       else col_hspeed=n1;}
     
     if (n2>0) {if (horline_collision(nx+col_hspeed,nx+col_hspeed+nw,ny+nh+n2)) {col_vspeed=((ny+nh)/32+1)*32-ny-nh-1; //the same  but with going down, and checking if there is a floor
                                                                                onfloor=1;}
                                                                             else col_vspeed=n2;}
     if (n2<0) {if (horline_collision(nx+col_hspeed,nx+col_hspeed+nw,ny+n2)) col_vspeed=ny/32*32-ny+1; //the same but going up
                                                                             else col_vspeed=n2;}
                                                                             
                                                       
                                         
                      
}
#endif  
