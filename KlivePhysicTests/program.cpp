#pragma once
#include "Client/PhysicsClient.h"
#include "program.h"
#include <iostream>

int main() {
	PhysicsClient client;

	while (true) {
		float time = client.GetDeltaTimeNanoseconds();
		std::cout << time << std::endl;
	}

	std::cout << "Hello!" << std::endl;
}