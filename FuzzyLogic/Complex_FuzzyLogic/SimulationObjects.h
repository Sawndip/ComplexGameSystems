#pragma once

#include "glm/glm.hpp"
#include <vector>
#include "Renderer2D.h"

class SpriteBatch;

enum WorldObjectType
{
	SIMPLE_AI,
	WATER,
	FOOD,
	CAVE,
};

using namespace std;
class WorldObject
{
public:
	vector<WorldObject*>* worldObjects;
	virtual void update(float delta) =0;
	virtual void draw(aie::Renderer2D* spriteBatch);
	float radius;
	glm::vec4 colour;
	glm::vec2 position;
	WorldObjectType type;
};

class BaseResource:public WorldObject
{
	public:
	float amount;

	BaseResource(glm::vec2 position,glm::vec4 colour,float radius);
	void virtual update(float delta){};
};


class Water:public BaseResource
{
	public:
	Water(glm::vec2 position);
};

class Food:public BaseResource
{
	public:
	Food(glm::vec2 position);
};

class Cave:public BaseResource
{
	public:
	Cave(glm::vec2 position);
};

class BaseAgent:public WorldObject
{
public:
	BaseAgent(glm::vec2 position, glm::vec4 colour, float radius);
	float findNearestResource(WorldObjectType type);
	glm::vec2 findResourceVector(WorldObjectType type);
	float tiredness;
	float food;
	float water;
};

class Agent : public BaseAgent
{
public:
	float maxSpeed;
	virtual void update(float delta);
	virtual void draw(aie::Renderer2D* spriteBatch);
	void drawBar(aie::Renderer2D* spriteBatch, float value,int index);
	Agent(glm::vec2 position);
	float checkEatingDesirable();
	float checkSleepDesirable();
	float checkDrinkingDesirable();
	glm::vec2 gotoFood(float desirability,float delta);
	glm::vec2 gotoCave(float desirability,float delta);
	glm::vec2 gotoWater(float desirability,float delta);
};

class WorldController
{
public:
	vector<WorldObject*> worldObjects;
	void update(float delta);
	void draw(aie::Renderer2D* spriteBatch);
	void addObject(WorldObject* newObject);
};