#include <GL/glut.h>
#include "Game.h"

#include <iostream>


void Game::init()
{
	bPlay = true;
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
}

bool Game::update(int deltaTime)
{
	return bPlay;
}

void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Game::keyPressed(int key)
{
	if(key == 27) // Escape code
		bPlay = false;
	else if (key == '1')
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	else if (key == '2')
		glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
	else if (key == '3')
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void Game::keyReleased(int key)
{
}

void Game::mouseMove(int x, int y)
{
}

void Game::mousePress(int button)
{
}

void Game::mouseRelease(int button)
{
}



