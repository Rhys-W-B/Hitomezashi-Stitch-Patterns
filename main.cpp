#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "RenderWindow.hpp"
#include <ctype.h>
#include <string>

const int WINDOW_WIDTH = 2000;
const int WINDOW_HEIGHT = 1200;

RenderWindow window("woo gaming learning yes", WINDOW_WIDTH, WINDOW_HEIGHT);
SDL_Surface* s = SDL_CreateRGBSurface(0, WINDOW_WIDTH, WINDOW_HEIGHT, 255, 0, 0, 255, 0);
SDL_Rect* box;
int gapdistance = 15;

void RenderWindow::HorizontalLine(int x, int y) {
	int x2 = x + gapdistance;
	int y2 = y;
	SDL_RenderDrawLine(renderer, x, y, x2, y2);
}

void RenderWindow::VerticalLine(int x, int y) {
	int x2 = x;
	int y2 = y + gapdistance;
	SDL_RenderDrawLine(renderer, x, y, x2, y2);
}

void RenderWindow::DrawBox(int xval, int yval) {


	SDL_RenderDrawRect(renderer, box);
}

void RenderWindow::pointgrid() {
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	for (int i = 0; i * 50 <= WINDOW_WIDTH; i++) {
		for (int j = 0; j * 50 <= WINDOW_HEIGHT; j++) {
			SDL_RenderDrawPoint(renderer, i * 50, j * 50);
		}
	}
}

void generatepattern() {
	
	for (int i = 0; i * gapdistance <= WINDOW_HEIGHT; i++) {
		int num = (rand() % 10 + 1) % 2;
		for (int j = 0; j * gapdistance <= WINDOW_WIDTH; j++) {
			if (j % 2 == num) {
				window.HorizontalLine(j * gapdistance, i* gapdistance);
				window.DrawBox(i * gapdistance, (i + gapdistance) * gapdistance);
			}
		}
	}

	for (int i = 0; i * gapdistance <= WINDOW_WIDTH; i++) {
		int num = (rand() % 10 + 1) % 2;
		for (int j = 0; j * gapdistance <= WINDOW_HEIGHT; j++) {
			if (j % 2 == num) {
				window.VerticalLine(i * gapdistance, j * gapdistance);
			}
		}
	}


}

void RenderWindow::drawpattern() {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	generatepattern();
}

int main(int argc, char* args[]) {
	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		std::cout << "STD_Init FAILED" << SDL_GetError() << std::endl;
	}

	if (!(IMG_Init(IMG_INIT_PNG))) {
		std::cout << "IMG_Init FAILED" << SDL_GetError() << std::endl;
	}
	srand(time(NULL));
	

	SDL_Texture* mantexture = window.loadTexture("Rendering\\gfx\\Man.png");

	bool gameRunning = true;

	SDL_Event event;

	char yes;
	
	while (gameRunning) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				gameRunning = false;
			}
		}
		
		window.clear();
		//window.pointgrid();
		window.drawpattern();
		window.display();
		std::cin >> yes;
		if (yes == 'x') {
			std::cin >> gapdistance;
		}
		if (yes == 'z') {
			gameRunning = false;
		}
	}
	
	window.clenaUp();
	SDL_Quit();

	return 0;
}