#pragma once
#include "../Stopwatch/KPStopwatch.h"


class PhysicsClient
{
private:
	long long previousTime;
	KPStopwatch stopwatch;
public:
	//Place options parameters here
	PhysicsClient();
	~PhysicsClient();

	//Information
	float GetDeltaTimeNanoseconds();

	//Object instantiation

};

