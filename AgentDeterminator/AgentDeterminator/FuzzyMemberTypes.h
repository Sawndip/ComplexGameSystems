#pragma once

enum FuzzyMemberType {
	FMT_SHOULDER_LEFT,
	FMT_SHOULDER_RIGHT,
	FMT_TRAPEZOID,
	FMT_TRIANGULAR,
	FMT_GAUSIAN,
	FMT_SINGLETON
};

class FuzzyMemberFunction {

};

class FMF_LeftShoulder : FuzzyMemberFunction {
	
	FMF_LeftShoulder(float a_startValue, float a_endValaue);

private:
	float m_fLeftValue;
	float m_fPeakLeftValue;
};

class FMF_RightShoulder : FuzzyMemberFunction {
	
	FMF_RightShoulder(float a_startValue, float a_endValaue);

private:
	float m_fRightValue;
	float m_fPeakRightValue;
};

class FMF_Triangular : FuzzyMemberFunction {

	FMF_Triangular(float a_minStartValue, float a_maxPeakValue, float a_minEndVlaue);

private:
	float m_fLeftValue;
	float m_fRightValue;
	float m_fPeakValue;
};

class FMF_Trapazoid : FuzzyMemberFunction {

	FMF_Trapazoid(float a_minStartValue, float a_maxStartValue, float a_maxEndValue, float a_minEndVlaue);

private:
	float m_fLeftValue;
	float m_fRightValue;
	float m_fPeakLeftValue;
	float m_fPeakRightValue;
};

class FMF_Gausian : FuzzyMemberFunction {

};

class FMF_Singleton : FuzzyMemberFunction {

};