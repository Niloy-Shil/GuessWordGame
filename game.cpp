#include <SDL2/SDL.h>
#include <iostream>
#include<time.h>
using namespace std;
//global variable___________
SDL_Rect R[11];
int i=0;
int X[10]={1,1,1,1,1,1,1,1,1,1};
int Y[10]={1,1,1,1,1,1,1,1,1,1};
int  x=rand()%600;
int y = rand()%300;

SDL_Rect r{0,0,640,10};
SDL_Rect r2{0,0,10,725};
SDL_Rect r3{0,725,640,10};
SDL_Rect r4{630,0,10,725};
int t=3,A1=-2,A2=-2,t2=2;
SDL_Window* win;
SDL_Renderer* render;
//function................____________
void one(SDL_Rect A,int &a,int &b,int e,int f);
void window();
void color(SDL_Rect* R,int a,int b, int c,int d);
//main start________________
int main()
{
		window();
//rect section__________
SDL_Rect r5{x,y,35,35};
SDL_Rect r6{589,400,35,35};

while(1){
		SDL_SetRenderDrawColor(render,0,0,0,0);
SDL_RenderClear(render);

	SDL_SetRenderDrawColor(render,225,124,0,223);
	SDL_RenderFillRect(render,&r);
SDL_RenderFillRect(render,&r3);

	SDL_SetRenderDrawColor(render,225,10,0,223);
SDL_RenderFillRect(render,&r2);
SDL_RenderFillRect(render,&r4);

SDL_RenderFillRect(render,&r2);
SDL_RenderFillRect(render,&r2);
color(&r5,114,113,114,0);
color(&r6,114,213,114,0);

//increasing,decreasing section_____^
r5.x+=t;
r6.x+=A1;
r6.y+=A2;
r5.y+=t2;
//condition function______
one(r5,t,t2,2,3);
one(r6,A1,A2,1,4);

//new one creating function_________
if(SDL_HasIntersection(&r5,&r6))

{
	t=-t;
	t2=-t2;
	A1=-A1;
	A2=-A2;
	R[i]={r6.x,r6.y,35,35};
	i++;
	if(i>10)
	i=0;
	
}

for (int j= 0;j<=i;j++)
{
	
	
		SDL_SetRenderDrawColor(render,225,0,0,225);
			SDL_RenderFillRect(render,&R[j]);
			R[j].x+=X[j];
		R[j].y+=Y[j];
		
}


for(int j=0;j<=i;j++)
{
		
			one(R[j],X[j],Y[j],1,1);
			
}
//presenting section
	SDL_RenderPresent(render);
	SDL_Delay(10);
}
//destroing section______
	SDL_DestroyWindow(win);
	SDL_Quit();
}

//main function end______



void window()
{
	SDL_Init(SDL_INIT_EVERYTHING);
win	=SDL_CreateWindow ("Hello",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640,480,0);
render	 =SDL_CreateRenderer(win,-1,0);
	SDL_SetRenderDrawColor(render,0,0,0,0);
SDL_RenderClear(render);
	
}
void color(SDL_Rect* R,int a,int b, int c,int d)
{
		SDL_SetRenderDrawColor(render,a,b,c,d);
	SDL_RenderFillRect(render,R);
}
//for moving the box
void one(SDL_Rect A,int &a,int &b,int e,int f)
{
	if(SDL_HasIntersection(&A,&r4))
{
	a=-e;
}
else if(SDL_HasIntersection(&A,&r3))
{
	b=-f;
}
else if(SDL_HasIntersection(&A,&r2))
{
	a=e;
}
else if(SDL_HasIntersection(&A,&r))
{
	b=f;
}}
