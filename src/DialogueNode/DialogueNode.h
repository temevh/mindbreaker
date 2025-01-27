#ifndef DIALOGUENODE_H
#define DIALOGUENODE_H

#include <string>
#include <vector>
#include <utility>

class DialogueNode {
public:
    DialogueNode();

    DialogueNode(const std::string& line, const std::vector<std::pair<std::string, std::string>>& opts);

    std::string getNpcLine() const;
    std::vector<std::pair<std::string, std::string>> getOptions() const;

private:
    std::string npcLine; 
    std::vector<std::pair<std::string, std::string>> options; 
};

#endif 