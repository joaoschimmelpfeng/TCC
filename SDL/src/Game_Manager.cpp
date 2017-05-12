#include "Game_Manager.h"
#include "Entity_Object.h"
#include <stdlib.h> 
#include <SDL2/SDL.h>


Game_Manager::Game_Manager(int w,int h)
{
	this->sizex = w;
	this->sizey = h;
	
	entityMatrix = (Entity_Object **) calloc(sizex, sizeof(Entity_Object **));
	int i;
	for (i = 0; i < sizey; ++i)
	{
		entityMatrix[i] = (Entity_Object *) calloc(sizey,sizeof(Entity_Object));
	}

	int x,y;
	for(x = 0; x < sizex; ++x)
		for(y = 0; y < sizey; ++y)
		{
			entityMatrix[x][y] = Entity_Object(x,y);
			entityMatrix[x][y].r = x;
			entityMatrix[x][y].b = y;
			entityMatrix[x][y].g = x+y;
		}

}

Game_Manager::~Game_Manager()
{

}

void Game_Manager::Update()
{

}

void Game_Manager::Render(SDL_Renderer *renderer)
{
	SDL_RenderClear(renderer);
	int x,y;
	for(x = 0; x < sizex; ++x)
		for(y = 0; y < sizey; ++y)
		{
			Entity_Object e = entityMatrix[x][y];
			SDL_SetRenderDrawColor(renderer, e.r, e.g, e.b, 255);
			SDL_RenderDrawPoint(renderer, e.pos_x, e.pos_y);
		}

	SDL_RenderPresent(renderer);
}