#include <stdio.h>         /*Included the necessary libraries*/
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>



 char maze[8][6][4];
 char nbr_rows;
 char nbr_cols;
 char size_cell;


 int contour[35][63] = {
	{1,1,1,1,1,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,1,1,1,1,1}, 
	{1,1,1,1,1,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,1,1,1,1,1},
	{4,4,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,5,4,4}, 
	{4,4,5,4,4,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,5,4,4},
	{4,4,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,5,4,4}, 
	{5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5},	
	{4,4,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,5,4,4}, 
	{4,4,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,5,4,4},
	{4,4,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,5,4,4}, 
	{5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5},
	{4,4,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,5,4,4}, 
	{4,4,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,5,4,4},
	{4,4,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,5,4,4}, 
	{5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5},
	{4,4,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,5,4,4}, 
	{4,4,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,5,4,4},
	{4,4,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,5,4,4}, 
	{5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5},
	{4,4,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,5,4,4}, 
	{4,4,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,5,4,4},
	{4,4,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,5,4,4}, 
	{5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5},
	{4,4,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,5,4,4}, 
	{4,4,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,5,4,4},	
	{4,4,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,5,4,4}, 
	{5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5},
	{4,4,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,5,4,4}, 
	{4,4,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,5,4,4},
	{4,4,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,5,4,4}, 
	{5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5},
	{4,4,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,5,4,4}, 
	{4,4,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,4,4,5,4,4},
	{4,4,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,5,4,4}, 
	{1,1,1,1,1,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,1,1,1,1,1},
	{1,1,1,1,1,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,1,1,1,1,1} };

 struct location
{
    int y; 
    int x; 
};


struct location initial;                  
struct location ending;
struct location position;



 void get_maze(char* filename){
 	char c;
 	nbr_rows=8;
 	nbr_cols=6;
 	size_cell=4;

 	FILE* file= fopen(filename, "r");
 	c=getc(file);

 	// on ignore la première ligne 
 	while(c!= '\n'){
 		c=getc(file);
 	}

 	//Desormais on se trouve dans la seconde ligne et on remplit le tableau
 	for (int i=0; i<nbr_rows;i++) {
 		for (int j=0; j<nbr_cols;j++) {
 			for (int k =0; k<size_cell;k++) {
 				c=getc(file);
 				maze[i][j][k]=c;
 			}
 			if (j== 5){
 				c=getc(file);
 				break;}
 			}
 		}
 }


void printContour(WINDOW *mazeArea){
	int l;
	int c;

	for(l=0;l<35;l++)
	{
		//printf("%s\n", "here1");


		for(c=0;c<63;c++)
		{
			//printf("%s\n", "here2");

			if (contour[l][c] ==1){
				//printf("%s\n", "here3");
				mvwaddch(mazeArea, l, c, ACS_DIAMOND);
			}
			
			if (contour[l][c] ==2){
				mvwaddch(mazeArea, l, c, ACS_BLOCK );
			}
			
			if (contour[l][c] ==3){
				mvwaddch(mazeArea, l, c, ACS_S7);
			
			}

			if (contour[l][c] ==4){
				mvwaddch(mazeArea, l, c, ACS_VLINE);
			
			}
			if (contour[l][c] ==5){
				mvwaddch(mazeArea, l, c, ACS_DEGREE);
			
			}

			if(contour[l][c]== 6){
				mvwaddch(mazeArea,l,c, ACS_DIAMOND);
			}
			if(contour[l][c]== 7){
				mvwaddch(mazeArea,l,c, ACS_DARROW);
			}

	    }
    }

}

void printMaze(WINDOW *mazeArea) /* Function to print the maze*/
{
	int l;
	int c;



	for(l=0;l<8;l++){

		for(c=0;c<6;c++)
		{

			if (maze[l][c][0]=='M'){

				mvwaddch(mazeArea, (4*(l+1)-1)-2, 9*(c+1), ACS_LEQUAL  );
				mvwaddch(mazeArea, (4*(l+1)-1)-2, 9*(c+1)-1, ACS_LEQUAL  );
				mvwaddch(mazeArea, (4*(l+1)-1)-2, 9*(c+1)-2, ACS_LEQUAL  );
				mvwaddch(mazeArea, (4*(l+1)-1)-2, 9*(c+1)-3, ACS_LEQUAL  );
				mvwaddch(mazeArea, (4*(l+1)-1)-2, 9*(c+1)-4, ACS_LEQUAL  );
				mvwaddch(mazeArea, (4*(l+1)-1)-2, 9*(c+1)+1, ACS_LEQUAL  );
				mvwaddch(mazeArea, (4*(l+1)-1)-2, 9*(c+1)+2, ACS_LEQUAL  );
				mvwaddch(mazeArea, (4*(l+1)-1)-2, 9*(c+1)+3, ACS_LEQUAL  );
			}
			
			if (maze[l][c][1]=='M'){
				if (c==5){	
				mvwaddch(mazeArea, (4*(l+1)-1), 9*(c+1)+4, ACS_VLINE  );
				mvwaddch(mazeArea, (4*(l+1)-1)-1, 9*(c+1)+4, ACS_VLINE  );
				mvwaddch(mazeArea, (4*(l+1)-1)+1, 9*(c+1)+4, ACS_VLINE  );

				}

				else{
				mvwaddch(mazeArea, (4*(l+1)-1), 9*(c+1)+4, ACS_VLINE  );
				mvwaddch(mazeArea, (4*(l+1)-1)-1, 9*(c+1)+4, ACS_VLINE  );
				mvwaddch(mazeArea, (4*(l+1)-1)+1, 9*(c+1)+4, ACS_VLINE  );
			}

			}
			
			if (maze[l][c][2]=='M'){
				mvwaddch(mazeArea, (4*(l+1)-1)+2, 9*(c+1), ACS_LEQUAL  );
				mvwaddch(mazeArea, (4*(l+1)-1)+2, 9*(c+1)-1, ACS_LEQUAL  );
				mvwaddch(mazeArea, (4*(l+1)-1)+2, 9*(c+1)-2, ACS_LEQUAL  );
				mvwaddch(mazeArea, (4*(l+1)-1)+2, 9*(c+1)-3, ACS_LEQUAL  );
				mvwaddch(mazeArea, (4*(l+1)-1)+2, 9*(c+1)-4, ACS_LEQUAL  );
				mvwaddch(mazeArea, (4*(l+1)-1)+2, 9*(c+1)+1, ACS_LEQUAL  );
				mvwaddch(mazeArea, (4*(l+1)-1)+2, 9*(c+1)+2, ACS_LEQUAL  );
				mvwaddch(mazeArea, (4*(l+1)-1)+2, 9*(c+1)+3, ACS_LEQUAL  );	
				if (l==7){
				mvwaddch(mazeArea, (4*(l+1)-1)+2, 9*(c+1), ACS_GEQUAL  );
				mvwaddch(mazeArea, (4*(l+1)-1)+2, 9*(c+1)-1, ACS_GEQUAL  );
				mvwaddch(mazeArea, (4*(l+1)-1)+2, 9*(c+1)-2, ACS_GEQUAL  );
				mvwaddch(mazeArea, (4*(l+1)-1)+2, 9*(c+1)-3, ACS_GEQUAL  );
				mvwaddch(mazeArea, (4*(l+1)-1)+2, 9*(c+1)-4, ACS_GEQUAL  );
				mvwaddch(mazeArea, (4*(l+1)-1)+2, 9*(c+1)+1, ACS_GEQUAL  );
				mvwaddch(mazeArea, (4*(l+1)-1)+2, 9*(c+1)+2, ACS_GEQUAL  );
				mvwaddch(mazeArea, (4*(l+1)-1)+2, 9*(c+1)+3, ACS_GEQUAL  );

				}		
			}

			if (maze[l][c][3]=='M'){

				if (c==0){

				mvwaddch(mazeArea, (4*(l+1)-1), 9*(c+1)-5, ACS_VLINE  );
				mvwaddch(mazeArea, (4*(l+1)-1)-1, 9*(c+1)-5, ACS_VLINE  );
				mvwaddch(mazeArea, (4*(l+1)-1)+1, 9*(c+1)-5, ACS_VLINE  );	
				}

				else{
				mvwaddch(mazeArea, (4*(l+1)-1), 9*(c+1)-5, ACS_VLINE  );
				mvwaddch(mazeArea, (4*(l+1)-1)-1, 9*(c+1)-5, ACS_VLINE  );
				mvwaddch(mazeArea, (4*(l+1)-1)+1, 9*(c+1)-5, ACS_VLINE  );	
				}	
			}
		

	    }
    }

}



void printEnd(WINDOW *gameArea){

	int l;
	int c;

	for(l=0;l<35;l++)
	{
		//printf("%s\n", "here1");


		for(c=0;c<63;c++)
		{
			//printf("%s\n", "here2");

			if (contour[l][c] ==1){
				//printf("%s\n", "here3");
				mvwaddch(gameArea, l, c, ACS_DIAMOND);
			}
			
			if (contour[l][c] ==2){
				mvwaddch(gameArea, l, c, ACS_BLOCK );
			}
			
			if (contour[l][c] ==3){
				mvwaddch(gameArea, l, c, ACS_S7);
			
			}

			if (contour[l][c] ==4){
				mvwaddch(gameArea, l, c, ACS_VLINE);
			
			}
			if (contour[l][c] ==5){
				mvwaddch(gameArea, l, c, ACS_DEGREE);
			
			}

			else{
				printf("%c\n", " " );

			}

	    }
    }




}

int main(){

	get_maze("dedale.txt");

	WINDOW *gameArea;

	int quitInt = 0;
	initial.x = 9;
	initial.y = 3;
	position.x=0;
	position.y=0;
    initscr ();
    noecho (); 
    cbreak ();
    gameArea = newwin(35,63, 2, 25); 
    keypad(gameArea, TRUE);
    ending.x = 53;
    ending.y = 32;

    printContour(gameArea);
    printMaze(gameArea); 
    wmove(gameArea, initial.y,initial.x);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    wbkgd(gameArea, COLOR_PAIR(1));
    refresh (); 

    do 
    {
        int direction = wgetch (gameArea); 

        
        if(direction == 'i') 
        {
			if (maze[position.y][position.x][0] == '-')
			{

				position.y=position.y-1;
				initial.y=initial.y - 4;
				mvwaddch(gameArea, initial.y, initial.x , ACS_BULLET  );

			}

        }  
        else if(direction == 'k')
        {
			if (maze[position.y][position.x][2] == '-')
			{
				position.y=position.y+1;
				initial.y= initial.y +4;
				mvwaddch(gameArea, initial.y, initial.x , ACS_BULLET  );

			}
	    }
	    else if(direction == 'j')
	    {
			if (maze[position.y][position.x][3] == '-')
			{
				position.x=position.x -1;
				initial.x=initial.x - 9;
				mvwaddch(gameArea, initial.y, initial.x , ACS_BULLET  );


			}
	    }
	    else if(direction == 'l')
	    {
			if (maze[position.y][position.x][1] == '-')
			{
				position.x=position.x +1;
				initial.x= initial.x +9;
				mvwaddch(gameArea, initial.y, initial.x , ACS_BULLET  );

			}
	    }    
        else if(direction == 'q')
        {
			quitInt = 1;
	    }

    	wmove(gameArea, initial.y, initial.x);
	    wrefresh(gameArea);
    
    }while(((initial.x != 54) || (initial.y != 31))&& quitInt != 1);

    printEnd(gameArea);

    printf("%s\n", "GAME OVER");

    //endwin();


	return (0);
}
