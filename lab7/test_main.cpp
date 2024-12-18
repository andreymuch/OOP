#include "src/func/func.h"
#include "src/Core/NPCFactory.h"
#include <gtest/gtest.h>



TEST(CreateyNPCs, Create50NPCs) {
    std::vector<std::shared_ptr<NPC>> npcs;
    createNPCs(npcs);

    EXPECT_EQ(npcs.size(), 50);
}
TEST(IsPositionOccupiedTest, NoNPCsPresent) {
    std::vector<std::shared_ptr<NPC>> npcs;

    int x = 5;
    int y = 5;

    EXPECT_FALSE(isPositionOccupied(npcs, x, y));
}

TEST(MoveAndFightNPCsTest, OrcSurvives) {
    std::vector<std::shared_ptr<NPC>> npcs;

    // Add one Orc
    npcs.push_back(NPCFactory::createNPC("Orc", "Orc1", 0, 0));

    // Add 35 Bears
    for (int i = 0; i < 35; ++i) {
        npcs.push_back(NPCFactory::createNPC("Bear", "Bear" + std::to_string(i + 1), i, i));
    }

    moveAndFightNPCs(npcs);
    EXPECT_EQ(npcs[0]->getType(), "Orc");
}


TEST(MoveAndFightNPCsTest, MultipleNPCs) {
    std::vector<std::shared_ptr<NPC>> npcs;

    // Add two Orcs
    npcs.push_back(NPCFactory::createNPC("Orc", "Orc1", 0, 0));
    npcs.push_back(NPCFactory::createNPC("Orc", "Orc2", 5, 5));

    // Add one Orc and one Bear
    npcs.push_back(NPCFactory::createNPC("Orc", "Orc3", 20, 20));
    npcs.push_back(NPCFactory::createNPC("Bear", "Bear1", 23, 23));

    moveAndFightNPCs(npcs);
    
    EXPECT_EQ(npcs[0]->getType(), "Orc");
}






int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}