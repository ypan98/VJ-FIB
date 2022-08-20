#include <iostream>
#include <cmath>
#include <glm/gtc/matrix_transform.hpp>
#include "Scene.h"
#include<string>


Scene::Scene()
{
	quad = NULL;
}

Scene::~Scene()
{
	if(quad != NULL)
		delete quad;
	for(int i=0; i<2; i++)
		if(texQuad[i] != NULL)
			delete texQuad[i];
}


void Scene::init()
{
	// +45.f para que pueda alinear con suelo (el imagen fuente tiene borde inferior)
	glm::vec2 geomMussroom[2] = { glm::vec2(0.f, float(CAMERA_HEIGHT) / 2.f - 128.f), glm::vec2(128.f , float(CAMERA_HEIGHT) / 2.f + 45.f) };
	glm::vec2 geomBlock[2] = { glm::vec2(0.f, float(CAMERA_HEIGHT) / 2.f), glm::vec2(float(CAMERA_WIDTH), float(CAMERA_HEIGHT)) };
	glm::vec2 texCoords[2] = { glm::vec2(0.f, 0.f), glm::vec2(1.f, 1.f) };

	initShaders();
	quad = Quad::createQuad(0.f, 0.f, float(CAMERA_WIDTH), float(CAMERA_HEIGHT), simpleProgram);
	texCoords[0] = glm::vec2(0.f, 0.5f); texCoords[1] = glm::vec2(0.5f, 1.f);
	texQuad[0] = TexturedQuad::createTexturedQuad(geomMussroom, texCoords, texProgram);
	texCoords[0] = glm::vec2(0.f, 0.f); texCoords[1] = glm::vec2(4.f * float(CAMERA_WIDTH) / 128.f, 4.f * float(CAMERA_HEIGHT) / 256.f);
	texQuad[1] = TexturedQuad::createTexturedQuad(geomBlock, texCoords, texProgram);
	// Load textures
	texs[0].loadFromFile("images/varied.png", TEXTURE_PIXEL_FORMAT_RGBA);
	texs[1].loadFromFile("images/block.png", TEXTURE_PIXEL_FORMAT_RGBA);
	projection = glm::ortho(0.f, float(CAMERA_WIDTH - 1), float(CAMERA_HEIGHT - 1), 0.f);
	currentTime = 0.0f;
	
	// Select which font you want to use
	if(!text.init("fonts/OpenSans-Regular.ttf"))
	//if(!text.init("fonts/OpenSans-Bold.ttf"))
	//if(!text.init("fonts/DroidSerif.ttf"))
		cout << "Could not load font!!!" << endl;

	count = 0;
	lastDir = 1;
	activated = true;
}

void Scene::update(int deltaTime)
{
	currentTime += deltaTime;
}

void Scene::render()
{
	glm::mat4 modelview;

	simpleProgram.use();
	simpleProgram.setUniformMatrix4f("projection", projection);
	simpleProgram.setUniform4f("color", 0.2f, 0.6f, 0.8f, 1.0f);

	modelview = glm::mat4(1.0f);
	simpleProgram.setUniformMatrix4f("modelview", modelview);
	quad->render();

	// --------------------------------- textured

	texProgram.use();
	texProgram.setUniformMatrix4f("projection", projection);
	texProgram.setUniform4f("color", 1.0f, 1.0f, 1.0f, 1.0f);

	float time = fmod(currentTime / 1000.f, 4.f);

	float dir = 1.f;
	if (time >= 2) {
		dir = -1.f;
		time = time - 2.f;
	}
	if (dir != lastDir) {
		lastDir = dir;
		count++;
	}

	float xvel = (float(CAMERA_WIDTH) - 128.f) / 2.f;

	if (dir > 0.f) modelview = glm::translate(glm::mat4(1.0f), glm::vec3(time * xvel, 0.f, 0.f));
	else modelview = glm::translate(glm::mat4(1.0f), glm::vec3(float(CAMERA_WIDTH) - 128.f - time * xvel, 0.f, 0.f));
	texProgram.setUniformMatrix4f("modelview", modelview);
	texQuad[0]->render(texs[0]);

	modelview = glm::mat4(1.f);
	texProgram.setUniformMatrix4f("modelview", modelview);
	texQuad[1]->render(texs[1]);
	
	text.render("Rebots: " + to_string(count), glm::vec2(10, 40), 32, glm::vec4(1, 1, 1, 1));

	if (activated) {
		glm::vec2 boletPos = glm::vec2(time * xvel + 30, float(CAMERA_HEIGHT) / 2.f - 50);
		if (dir < 0.f) boletPos.x = float(CAMERA_WIDTH) - 128.f - time * xvel + 30;
		text.render("Bolet", boletPos, 32, glm::vec4(0, 0, 0, 1));
	}

	text.render("Press A to activate/deactivate text", glm::vec2(10, CAMERA_HEIGHT - 20), 32, glm::vec4(1, 1, 1, 1));
}

void Scene::initShaders()
{
	Shader vShader, fShader;

	vShader.initFromFile(VERTEX_SHADER, "shaders/simple.vert");
	if(!vShader.isCompiled())
	{
		cout << "Vertex Shader Error" << endl;
		cout << "" << vShader.log() << endl << endl;
	}
	fShader.initFromFile(FRAGMENT_SHADER, "shaders/simple.frag");
	if(!fShader.isCompiled())
	{
		cout << "Fragment Shader Error" << endl;
		cout << "" << fShader.log() << endl << endl;
	}
	simpleProgram.init();
	simpleProgram.addShader(vShader);
	simpleProgram.addShader(fShader);
	simpleProgram.link();
	if(!simpleProgram.isLinked())
	{
		cout << "Shader Linking Error" << endl;
		cout << "" << simpleProgram.log() << endl << endl;
	}
	simpleProgram.bindFragmentOutput("outColor");

	vShader.free();
	fShader.free();
	vShader.initFromFile(VERTEX_SHADER, "shaders/texture.vert");
	if(!vShader.isCompiled())
	{
		cout << "Vertex Shader Error" << endl;
		cout << "" << vShader.log() << endl << endl;
	}
	fShader.initFromFile(FRAGMENT_SHADER, "shaders/texture.frag");
	if(!fShader.isCompiled())
	{
		cout << "Fragment Shader Error" << endl;
		cout << "" << fShader.log() << endl << endl;
	}
	texProgram.init();
	texProgram.addShader(vShader);
	texProgram.addShader(fShader);
	texProgram.link();
	if(!texProgram.isLinked())
	{
		cout << "Shader Linking Error" << endl;
		cout << "" << texProgram.log() << endl << endl;
	}
	texProgram.bindFragmentOutput("outColor");
}

void Scene::switchText()
{
	activated = !activated;
}

