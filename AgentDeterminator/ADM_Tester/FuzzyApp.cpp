#include "FuzzyApp.h"
#include "Font.h"
#include "Input.h"
#include "glm\glm.hpp"


FuzzyApp::FuzzyApp()
{
}


FuzzyApp::~FuzzyApp()
{
}

bool FuzzyApp::startup()
{
	// renderer
	m_renderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);
	//scene controller
	m_sceneController = new SceneController();
	// agents
	m_buddyAgent = new CompanionAgent("Buddy", glm::vec3(100.0f, 100.0f, 0.0f));
	m_enemyAgent = new EnemyAgent("Enemy", glm::vec3(500.0f, 400.0f, 0.0f));
	m_playerAgent = new PlayerAgent("Hero", glm::vec3(50.0f, 50.0f, 0.0f));
	// add egents to scene controller
	m_sceneController->addAgent(m_buddyAgent);
	m_sceneController->addAgent(m_enemyAgent);
	m_sceneController->addAgent(m_playerAgent);

	return true;
}

void FuzzyApp::shutdown()
{
	delete m_font;
	delete m_renderer;
	delete m_buddyAgent;
	delete m_enemyAgent;
	delete m_playerAgent;
	delete m_sceneController;
}

void FuzzyApp::update(float a_dt)
{
	// update input
	aie::Input* input = aie::Input::getInstance();

	// update agents
	m_sceneController->update(a_dt);


	m_playerAgent->vitals.currentDistance = glm::distance(m_playerAgent->position(), m_enemyAgent->position());
	//m_playerAgent->update(deltaTime);
	
	m_buddyAgent->vitals.currentDistance = glm::distance(m_buddyAgent->position(), m_enemyAgent->position());
	//m_buddyAgent->update(deltaTime);

	m_enemyAgent->vitals.currentDistance = glm::distance(m_enemyAgent->position(), m_buddyAgent->position());
	//m_enemyAgent->update(deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void FuzzyApp::draw()
{
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_renderer->begin();

	// draw your stuff here!
	drawAgents(m_renderer);

	// output some text
	m_renderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_renderer->end();
}

void FuzzyApp::drawAgents(aie::Renderer2D * a_renderer)
{
	glm::vec4 colour = glm::vec4(0.0f);
	glm::vec3 position = glm::vec3(0.0f);
	// draw agents from list
	for (auto agent : m_sceneController->m_agentObjects)
	{
		colour = agent->colour();
		position = agent->position();
		a_renderer->setRenderColour(colour.r, colour.g, colour.b, colour.a);
		a_renderer->drawSprite(nullptr, position.x, position.y, agent->vitals.size, agent->vitals.size);
	}
}
