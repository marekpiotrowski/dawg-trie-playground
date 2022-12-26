#ifndef DAWG_H
#define DAWG_H

#include <string>
#include <vector>
#include <memory>

// struct DAWGNode {
//     DAWGNode* parent;
//     unsigned char flags;
//     char c;

//     void setEndOfList() { flags = flags | 0x01; };
//     void setEndOfWord() { flags = flags | 0x02; };
//     bool isEndOfWord() const { return flags & 0x01 == 0x01; };
//     bool isEndOfList() const { return flags & 0x02 == 0x02; };
// };

// class DAWG {
//     DAWG(const std::vector<std::string>& words);

//     void search(const std::string& s, std::vector<std::string>& suggestions) const;
// };

constexpr size_t ALL_CHARACTERS_COUNT = 26;

struct TrieNode {
    char c;
    bool isEndOfWord{false};
    std::array<std::shared_ptr<TrieNode>, ALL_CHARACTERS_COUNT> children{nullptr};
};

std::string completeWord(const std::string& w);

void insertWord(const std::string& w);

void printNode(const TrieNode* n);

TrieNode* getRoot();

#endif // DAWG_H
