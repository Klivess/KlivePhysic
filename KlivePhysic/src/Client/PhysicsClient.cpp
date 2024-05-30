#include "PhysicsClient.h"
#include <thread>

float PhysicsClient::GetDeltaTimeNanoseconds()
{
    previousTime = stopwatch.elapsed_time().count();
    float dTime = (stopwatch.elapsed_time().count() - previousTime)+1;
    return dTime;
}


PhysicsClient::PhysicsClient()
{
    stopwatch.go();
}

PhysicsClient::~PhysicsClient()
{
}
