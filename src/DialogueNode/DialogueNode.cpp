#include "DialogueNode.h"


DialogueNode::DialogueNode() : npcLine(""), options({}) {}


DialogueNode::DialogueNode(const std::string& line, const std::vector<std::pair<std::string, std::string>>& opts)
    : npcLine(line), options(opts) {}

std::string DialogueNode::getNpcLine() const {
    return npcLine;
}

std::vector<std::pair<std::string, std::string>> DialogueNode::getOptions() const {
    return options;
}