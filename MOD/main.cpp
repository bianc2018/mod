#include "mod_manager.h"

int main(int argc, char*argv[])
{
	std::shared_ptr<ModManager> mgr = ModManager::Instance();
	mgr->run();
	return 0;
}