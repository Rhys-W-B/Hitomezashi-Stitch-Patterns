#include <SDL.h>
#include <SDL_image.h>
#include <RenderWindow.hpp>
#include <iostream>

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h) 
	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

	if (window == NULL) {
		std::cout << "WINDOW FAILES TO INIT. ERROR: " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath) {
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL) {
		std::cout << "failed to load texture. Error: " << SDL_GetError() << std::endl;
	}
	return texture;
}

void RenderWindow::clenaUp() {
	SDL_DestroyWindow(window);
}

void RenderWindow::clear() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture* p_tex) {
	SDL_RenderCopy(renderer, p_tex, NULL, NULL);
}

void RenderWindow::display() {
	SDL_RenderPresent(renderer);
}



