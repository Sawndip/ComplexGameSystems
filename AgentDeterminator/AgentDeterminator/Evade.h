#pragma once
#include <vector>
#include "Behaviour.h"
#include "FuzzyMemberTypes.h"

class Evade :
	public Behaviour
{
public:
	Evade();
	virtual ~Evade();
	Evade(float a_distanceMin, float distanceMax, float a_healthMin, float a_healthMax, float a_evadeMin, float a_evadeMax);
	Evade(float a_distanceCloseMin, float distanceCloseMax, float a_distanceMiddleMin, float a_distanceMiddleMid, float distanceMiddleMax, float a_distanceFarMin, float distanceFarMax,
		float a_healthLowMin, float healthLowMax, float a_healthOkayMin, float a_healthOkayMid, float healthOkayMax, float a_healthGoodMin, float healthGoodMax,
		float a_evadeLowMin, float evadeLowMax, float a_evadeMediumMin, float a_evadeMediumMid, float evadeMediumMax, float a_evadeHighMin, float evadeHighMax);

	void update(Agent & a_agent);

	// get fuzzy settings
	std::vector<float> distance() { return m_distanceSettings; };
	std::vector<float> health() { return m_healthSettings; };
	std::vector<float> evadeable() { return m_evadeSettings; };
	// set fuzzy settings
	std::vector<float> distance(std::vector<float> a_settings);
	std::vector<float> health(std::vector<float> a_settings);
	std::vector<float> evadeable(std::vector<float> a_settings);
	// destroy agent
	void destroy();

private:
	// distance
	FMF_LeftShoulder	* m_distanceClose = nullptr;
	FMF_Triangular		* m_distanceMiddle = nullptr;
	FMF_RightShoulder	* m_distanceFar = nullptr;
	// health
	FMF_LeftShoulder	* m_healthLow = nullptr;
	FMF_Triangular		* m_healthOkay = nullptr;
	FMF_RightShoulder	* m_healthGood = nullptr;
	// evadeable
	FMF_LeftShoulder	* m_evadeLow = nullptr;
	FMF_Triangular		* m_evadeMedium = nullptr;
	FMF_RightShoulder	* m_evadeHigh = nullptr;
	// fuzzy settings
	std::vector<float> m_distanceSettings;
	std::vector<float> m_healthSettings;
	std::vector<float> m_evadeSettings;
	// fill vectors function
	void initVectors();
};

