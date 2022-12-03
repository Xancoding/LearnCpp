#include <iostream>

enum class MonsterType {
    ogre,
    dragon,
    orc,
    spider,
    slime,
};

struct Monster {
    MonsterType type{};
    std::string_view name{};
    int hp{};
};

std::ostream& operator<<(std::ostream& out, MonsterType type) {
    using enum MonsterType;
    switch (type) {
        case ogre:    out << "ogre";    break;
        case dragon:  out << "dragon";  break;
        case orc:     out << "orc";     break;
        case spider:  out << "spider";  break;
        case slime:   out << "slime";   break;
        default:      out << "???";     break;
    }
}

void printMonster(Monster monster) {
    std::cout << "This " << monster.type <<
        " is named " << monster.name <<
        " and has " << monster.hp << " health.\n";
}

int main() {
    Monster ogre{MonsterType::ogre, "Torg", 145};
    Monster slime{ MonsterType::slime, "Blurp", 23 };

    printMonster(ogre);
    printMonster(slime);

    return 0;
}