#include <iostream>
#include <math.h>
#include <glm/gtc/matrix_transform.hpp>
#include "Scene.h"
#include <msxml.h>


Scene::Scene()
{
	quad = NULL;
}

Scene::~Scene()
{
	if(quad != NULL)
		delete quad;
}


void Scene::init()
{
	initShaders();
	quad = Quad::createQuad(0.f, 0.f, 128.f, 128.f, program);
	projection = glm::ortho(0.f, float(CAMERA_WIDTH - 1), float(CAMERA_HEIGHT - 1), 0.f);
	currentTime = 0.0f;
}

void Scene::update(int deltaTime)
{
	currentTime += deltaTime;
}

void Scene::render()
{
	glm::mat4 modelview;

	// We can now, using matrices, draw four quads at different screen locations
	// using a single Quad object.
	program.use();
	program.setUniformMatrix4f("projection", projection);
	program.setUniform4f("color", 1.0f, 1.0f, 1.0f, 1.0f);

	float time = fmod(currentTime/1000.f, 2.f);


	float dir = 1.f;
	if (time >= 1) {
		dir = -1.f;
		time = time - 1.f;
	}

	float aux1 = time + 1.f;
	float aux2 = aux1 * aux1;
	float scale = 1.f / aux2;	// scale: 1 -> 1/4,		1/4 -> 1

	float xvel = float(CAMERA_WIDTH) / 2.f - 128.f; 

	if (dir > 0.f) modelview = glm::translate(glm::mat4(1.0f), glm::vec3(time*xvel, 0.f, 0.f));
	else modelview = glm::translate(glm::mat4(1.0f), glm::vec3(192.f - time * xvel, 0.f, 0.f));
	modelview = glm::translate(modelview, glm::vec3(0.f, 64.f, 0.f));
	if (dir > 0.f) modelview = glm::scale(modelview, glm::vec3(scale, scale, 0.f));
	else modelview = glm::scale(modelview, glm::vec3(aux2/4.f, aux2/4.f, 0.f));
	program.setUniformMatrix4f("modelview", modelview);
	quad->render();

	if (dir > 0.f) modelview = glm::translate(glm::mat4(1.0f), glm::vec3(512.f- time * xvel, 0.f, 0.f));
	else modelview = glm::translate(glm::mat4(1.0f), glm::vec3(320.f + time * xvel, 0.f, 0.f));
	modelview = glm::translate(modelview, glm::vec3(0.f, 64.f, 0.f));
	if (dir > 0.f) modelview = glm::scale(modelview, glm::vec3(scale, scale, 0.f));
	else modelview = glm::scale(modelview, glm::vec3(aux2 / 4.f, aux2 / 4.f, 0.f));
	program.setUniformMatrix4f("modelview", modelview);
	quad->render();

	if (dir > 0.f) modelview = glm::translate(glm::mat4(1.0f), glm::vec3(time * xvel, 0.f, 0.f));
	else modelview = glm::translate(glm::mat4(1.0f), glm::vec3(192.f - time * xvel, 0.f, 0.f));
	modelview = glm::translate(modelview, glm::vec3(0.f, 64.f + float(CAMERA_HEIGHT)/2.f, 0.f));
	if (dir > 0.f) modelview = glm::scale(modelview, glm::vec3(scale, scale, 0.f));
	else modelview = glm::scale(modelview, glm::vec3(aux2 / 4.f, aux2 / 4.f, 0.f));
	program.setUniformMatrix4f("modelview", modelview);
	quad->render();

	if (dir > 0.f) modelview = glm::translate(glm::mat4(1.0f), glm::vec3(512.f - time * xvel, 0.f, 0.f));
	else modelview = glm::translate(glm::mat4(1.0f), glm::vec3(320.f + time * xvel, 0.f, 0.f));
	modelview = glm::translate(modelview, glm::vec3(0.f, 64.f + float(CAMERA_HEIGHT) / 2.f, 0.f));
	if (dir > 0.f) modelview = glm::scale(modelview, glm::vec3(scale, scale, 0.f));
	else modelview = glm::scale(modelview, glm::vec3(aux2 / 4.f, aux2 / 4.f, 0.f));
	program.setUniformMatrix4f("modelview", modelview);
	quad->render();
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
	program.init();
	program.addShader(vShader);
	program.addShader(fShader);
	program.link();
	if(!program.isLinked())
	{
		cout << "Shader Linking Error" << endl;
		cout << "" << program.log() << endl << endl;
	}
	program.bindFragmentOutput("outColor");
}

