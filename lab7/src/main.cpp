#include "Core/NPCFactory.h"
#include "Core/BattleVisitor.h"
#include "Core/FileManager.h"
#include "Core/Logger.h"
#include "Func/func.h"


int main() {
    std::vector<std::shared_ptr<NPC>> npcs;
    createNPCs(npcs);
    moveAndFightNPCs(npcs);
    return 0;
}

