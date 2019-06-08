#include <iostream>
#include "sc2api/sc2_api.h"
#include "sc2lib/sc2_lib.h"
#include "sc2utils/sc2_manage_process.h"
#include "sc2utils/sc2_arg_parser.h"
#include "absl/strings/str_join.h"

#include "cahbot.h"
#include "LadderInterface.h"

#ifdef DEBUG
int main(int argc, char* argv[])
{
	std::vector<std::string> v = { "foo","bar","baz" };
	std::string s = absl::StrJoin(v, "-");

	std::cout << "Joined string: " << s << "\n";

	CAHBot bot;
	sc2::Coordinator coordinator;
	if (!coordinator.LoadSettings(argc, argv))
	{
		std::cout << "Unable to find or parse settings." << std::endl;
		return 1;
	}
	coordinator.SetStepSize(1);
	coordinator.SetRealtime(false);
	coordinator.SetMultithreaded(true);
	coordinator.SetParticipants({
		CreateParticipant(sc2::Race::Protoss, &bot),
		//sc2::PlayerSetup(sc2::PlayerType::Observer,Util::GetRaceFromString(enemyRaceString)),
		CreateComputer(sc2::Race::Protoss, sc2::Difficulty::VeryEasy)
	});
	// Start the game.
	coordinator.LaunchStarcraft();
	coordinator.StartGame("C:\\Program Files (x86)\\StarCraft II\\Maps\\AutomatonLE.SC2Map");

	// Step forward the game simulation.
	while (coordinator.Update())
	{
	}
}
#else

//*************************************************************************************************
int main(int argc, char* argv[]) 
{

	RunBot(argc, argv, new CAHBot(), sc2::Race::Protoss);

	return 0;
}
#endif