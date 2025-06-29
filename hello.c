#ifdef main
#undef main
#endif

#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

int SCREEN_WIDTH = 1920;
int SCREEN_HEIGHT = 1080;

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;


void closeall() {
	//Deallocate surface
//	SDL_FreeSurface( gHelloWorld );
//	gHelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow( window );
	window = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

bool init() {
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		}
		else {
			window = SDL_CreateWindow("SDL Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		}
		if(window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else {
			//Window Surface
			screenSurface = SDL_GetWindowSurface(window);
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			SDL_UpdateWindowSurface(window);
			//hack for window
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
		}	

	return true;
}

int main(int argc, char* args[]) {

	if(!init()) {
		printf("no init");
	}



	closeall();

	return 0;
}



/*
int initSDL() {
		if(SDL_Init(SDL_INIT_VIDEO) < 0) {
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		}
		else {
			window = SDL_CreateWindow("SDL TEST", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		}
		if(window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else {
			//Window Surface
			screenSurface = SDL_GetWindowSurface(window);
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			SDL_UpdateWindowSurface(window);
			//hack for window
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
		}	

	return 0;

}
*/
