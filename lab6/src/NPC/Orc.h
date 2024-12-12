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
    bool acceptFight(NPC& other) {
        if (canFight(other)) {
            std::string info = "Орк " + name + " атакует " + other.getType() + " " + other.getName() + "!\n";
            consoleLogger.notify(info);
            fileLogger.notify(info);

            if (other.getType() == "Bear") {
                std::string deathInfo = "Орк " + name + " убивает медведя " + other.getName() + "!\n";
                consoleLogger.notify(deathInfo);
                fileLogger.notify(deathInfo);
                return true;
            }

            if (other.getType() == "Orc") {
                std::string deathInfo = "Орк " + name + " убивает орка " + other.getName() + "!\n";
                consoleLogger.notify(deathInfo);
                fileLogger.notify(deathInfo);
                return true;
            }
        }
    }
};

