#ifndef Game_Manager_H
#define Game_Manager_H

#include <SDL2/SDL.h>
#include "Entity_Object.h" 

class Game_Manager
{
	public:
		Game_Manager(int w,int h);
		Game_Manager();
		Entity_Object **entityMatrix;
		int sizex;
		int sizey;
		void Update();
		void Render(SDL_Renderer *renderer);
};

inline Game_Manager::Game_Manager()
{

}

#endif