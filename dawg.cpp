#include <iostream>

#include "dawg.h"

TrieNode dictionary;

std::string completeWord(const std::string& w) {
    for (const auto& c : w) {
        std::cout << c << std::endl;
    }
    return "";
}

void insertWord(const std::string& w) {
    TrieNode* next = &dictionary;
    for (const auto& c : w) {
        auto& current = next->children[c - 'a'];
        if(current == nullptr) {
            // auto idx = c - 'a';
            // std::cout << c << " inserting at idx = " << idx << std::endl;
            current = std::make_shared<TrieNode>();    
            current->c = c;
        }
        next = next->children[c - 'a'].get();
    }
}

void printNode(const TrieNode* n) {
    std::cout << "n->c = " << n->c << ", size: " << n->children.size() << ", children: ";
    for (auto i = 0; i < n->children.size(); i++) {
        if(n->children[i] != nullptr) {
            std::cout << static_cast<char>(i + 'a') << ", ";
        }
    }
    std::cout << std::endl;
}

TrieNode* getRoot() {
    return &dictionary;
}

