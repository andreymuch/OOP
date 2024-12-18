#include "NPC.h"
#include "../Core/Logger.h"

class Squirrel : public NPC {
private:
    ConsoleLogger consoleLogger;
    FileLogger fileLogger;
public:
    Squirrel(const std::string& name, int x, int y) : NPC(name, x, y), fileLogger("log.txt") {}
    ~Squirrel() override = default;

    std::string getType() const {
        return "Squirrel";
    }

    bool canFight(const NPC& other) const {
        return true;
    }
    bool acceptFight(NPC& other) {
        if (canFight(other)) {
            std::string info = "Белка " + name + " не хочет атаковать " + other.getType() + " " + other.getName() + "!\n";
            consoleLogger.notify(info);
            fileLogger.notify(info);
            return false;
        }
    }
};
