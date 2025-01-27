#include "DialogueNode.h"

// Default constructor
DialogueNode::DialogueNode() : npcLine(""), options({}) {}

// Parameterized constructor
DialogueNode::DialogueNode(const std::string& line, const std::vector<std::pair<std::string, std::string>>& opts)
    : npcLine(line), options(opts) {}

// Getter for NPC line
std::string DialogueNode::getNpcLine() const {
    return npcLine;
}

// Getter for player options
std::vector<std::pair<std::string, std::string>> DialogueNode::getOptions() const {
    return options;
}