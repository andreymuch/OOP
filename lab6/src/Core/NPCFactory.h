#pragma once
#include <memory>
#include <iostream>
#include <string>
#include "../NPC/NPC.h"
#include "../NPC/Orc.h"
#include "../NPC/Bear.h"
#include "../NPC/Squirrel.h"

class NPCFactory {
public:
     static std::unique_ptr<NPC> createNPC(const std::string& type, const std::string& name, int x, int y) {
        std::unique_ptr<NPC> npc;
        if (type == "Orc") npc = std::make_unique<Orc>(name, x, y);
        else if (type == "Bear") npc = std::make_unique<Bear>(name, x, y);
        else if (type == "Squirrel") npc = std::make_unique<Squirrel>(name, x, y);
        else throw std::invalid_argument("Unknown NPC type: " + type);

        return npc;
    }
};