#include <SDL2/SDL.h>
using namespace std;
int main(int argc, char *argv[])
{
        SDL_Init(SDL_INIT_EVERYTHING );
        Sint32 x;
        Sint32 y;
        int A;
        int Y=2;
        int Z=2;
        SDL_Window *window = NULL;
    SDL_Renderer *render = NULL;
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Pogo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 720, 1280, 0);
    
    
    SDL_Rect r1{500,1200,80,50};
    SDL_Rect r2{150,1200,80,50};
    SDL_Rect r3{720/2,930,70,10};
    SDL_Rect B1{0,950,760,10};
    SDL_Rect B2{0,0,760,10};
    SDL_Rect B3{0,0,10,950};
    SDL_Rect B4{710,0,10,950};
      SDL_Rect r{200,200,15,15};
     bool t=false;

    render =SDL_CreateRenderer(window,-1,0);
    bool run = true;
    SDL_Event e;
    while (run)
    {
        A=0;
     
        while(SDL_PollEvent(&e))
        {
            if(e.type== SDL_QUIT)
            {
                run=false;
            }
           if (e.type==SDL_MOUSEMOTION)
            {
                SDL_GetMouseState(&x,&y);
              //  if((x>=580 && x<=680) && (y>=1200 && y<=1250))
              if(x>500 && (y>=1180 && y<=1260) )
        A= 8 ;
      //  else if((x>=80&& x<=170) && (y>=1200&& y<=1250))
          else if(x<230 && (y>=1180&& y<=1260))
         A=-8;
            }
        }
           SDL_SetRenderDrawColor(render,0,0,0,0);
           
        SDL_RenderClear(render);
        SDL_SetRenderDrawColor(render,225,125,0,125);
      
        
  //      SDL_RenderDrawRect(render,&r);
        SDL_RenderFillRect(render,&r1);
        SDL_RenderFillRect(render,&r2);
        SDL_SetRenderDrawColor(render,225,125,125,125);
        
         r3.x +=A;
         if(r3.x<=10)
         r3.x=10;
         if(r3.x>=640)
         r3.x=640;
        
        SDL_RenderFillRect(render,&r3);
        SDL_SetRenderDrawColor(render,0,225,0,225);
   //     SDL_RenderFillRect(render,&r);
        SDL_RenderFillRect(render,&B1);
           SDL_RenderFillRect(render,&B2);
              SDL_RenderFillRect(render,&B3);
                 SDL_RenderFillRect(render,&B4);
                 
                 SDL_SetRenderDrawColor(render,225,0,0,0);
                      t= SDL_HasIntersection(&r,&r3);
                 r.x+=Y;
                 r.y+=Z;
                 if(r.x>=695)
                 Y=-2;
                 if(r.x<=11)
                 Y=2;
                 if(t==true)
                 Z=-2;
                 if(r.y<=11)
                 Z=2;
                 if(r.y>=935)
                 {
                     SDL_Delay(500);
                 r.y=0;}
                 SDL_Delay(6);
                 SDL_RenderFillRect(render,&r);
        SDL_RenderPresent(render);
      
      
       
    }
    
   
}
