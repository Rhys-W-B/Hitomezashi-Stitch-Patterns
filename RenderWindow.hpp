#pragma once
#include <SDL.h>
#include <SDL_image.h>

class RenderWindow {
public:
	RenderWindow(const char* p_title, int p_w, int p_h);
	SDL_Texture* loadTexture(const char* p_filepath);
	void clenaUp();
	void clear();
	void render(SDL_Texture* p_tex);
	void display();
	void drawpattern();
	void HorizontalLine(int x, int y);
	void VerticalLine(int x, int y);
	void pointgrid();
	void DrawBox(int x, int y);
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};