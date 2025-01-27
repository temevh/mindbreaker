#ifndef DIALOGUENODE_H
#define DIALOGUENODE_H

#include <string>
#include <vector>
#include <utility> // for std::pair

class DialogueNode {
public:
    // Default constructor
    DialogueNode();

    // Parameterized constructor
    DialogueNode(const std::string& line, const std::vector<std::pair<std::string, std::string>>& opts);

    // Getters
    std::string getNpcLine() const;
    std::vector<std::pair<std::string, std::string>> getOptions() const;

private:
    std::string npcLine; // The NPC's line in this dialogue node
    std::vector<std::pair<std::string, std::string>> options; // Player options and next dialogue IDs
};

#endif // DIALOGUENODE_H