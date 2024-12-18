#include "NPC.h"
#include "../Core/Logger.h"

class Orc : public NPC {
private:
    ConsoleLogger consoleLogger;
    FileLogger fileLogger;
public:
    Orc(const std::string& name, int x, int y) : NPC(name, x, y), fileLogger("log.txt") {}
    ~Orc() override = default;

    std::string getType() const {
        return "Orc";
    }

    bool canFight(const NPC& other) const {
        return other.getType() == "Bear" || other.getType() == "Orc";
    }
    bool isKillOpponent(NPC& other) {
        if (canFight(other)) {
            std::string info = "Орк " + name + " атакует " + other.getType() + " " + other.getName() + "!\n";
            fileLogger.notify(info);

            int rollOrc = rollDice(*this);
            int rollOpponent = rollDice(other);

            std::string rollInfo = "Орк " + name + " выбрасывает " + std::to_string(rollOrc) + "!\n";
            fileLogger.notify(rollInfo);

            rollInfo = other.getType() + " "+ other.getName() + " выбрасывает " + std::to_string(rollOpponent) + "!\n";
            fileLogger.notify(rollInfo);

            if (rollOrc > rollOpponent) {
                std::string deathInfo = "Орк " + name + " убивает " + other.getType() + " " + other.getName() + "!\n";
                fileLogger.notify(deathInfo);
                return true;
            } else {
                std::string escapeInfo = other.getType() + " " + other.getName() + " убегает от орка " + name + "!\n";
                moveNPC(other);
                fileLogger.notify(escapeInfo);
            }
        }
        return false;
    }


};

