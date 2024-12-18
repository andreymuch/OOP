#include "NPC.h"
#include "../Core/Logger.h"


class Bear : public NPC {
private:
    ConsoleLogger consoleLogger;
    FileLogger fileLogger;
public:
    Bear(const std::string& name, int x, int y) : NPC(name, x, y), fileLogger("log.txt") {}
    ~Bear() override = default;

    std::string getType() const {
        return "Bear";
    }

    bool canFight(const NPC& other) const {
        return other.getType() == "Squirrel";
    }
    bool isKillOpponent(NPC& other) {
        if (canFight(other)) {
            std::string info = "Медведь " + name + " атакует " + other.getType() + " " + other.getName() + "!\n";
            fileLogger.notify(info);

            if (other.getType() == "Squirrel") {
                int rollBear = rollDice(*this);
                int rollSquirrel = rollDice(other);

                info = "Медведь " + name + " выбрасывает " + std::to_string(rollBear) + "!\n";
                fileLogger.notify(info);

                info = "Белка " + other.getName() + " выбрасывает " + std::to_string(rollSquirrel) + "!\n";
                fileLogger.notify(info);

                if (rollBear > rollSquirrel) {
                    std::string deathInfo = "Медведь " + name + " убивает белку " + other.getName() + "!\n";
                    fileLogger.notify(deathInfo);
                    return true;
                } else {
                    std::string info = "Белка " + other.getName() + " убегает от медведя " + name + "!\n";
                    moveNPC(other);
                    fileLogger.notify(info);
                    return false;
                }
            }
            
        }
        std::string info = "Медведь " + name + " не может атаковать " + other.getName() + "!\n";
        fileLogger.notify(info);
        return false;
    }


};
