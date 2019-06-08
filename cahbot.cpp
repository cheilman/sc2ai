#include <iostream>

#include "cahbot.h"
#include "sc2api/sc2_api.h"


CAHBot::CAHBot()
{

}


void CAHBot::OnGameStart()
{

}

void CAHBot::OnStep() {
	Observation();
	// What your bot does every game step
}

void CAHBot::OnUnitDestroyed(const sc2::Unit* unit)
{

}
void CAHBot::OnUnitEnterVision(const sc2::Unit* unit)
{

}

void CAHBot::OnBuildingConstructionComplete(const sc2::Unit* unit)
{

}

void CAHBot::OnUnitCreated(const sc2::Unit* unit)
{

}

void CAHBot::OnUnitIdle(const sc2::Unit* unit)
{

}
