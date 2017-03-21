#include "EntityController.h"



Space::EntityController::EntityController()
{
}


Space::EntityController::~EntityController()
{
}

void Space::EntityController::update()
{
}

std::vector<Space::Command>& Space::EntityController::getCommandQueueRef()
{
	return commandQueue;
}

void Space::EntityController::clearCommandQueue()
{
	commandQueue.clear();
}
