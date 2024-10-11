#include "Trie.h"

#include <ranges>

bool Trie::Node_::canMakeMove(char c) const {
    return move.contains(c);
}

size_t Trie::Node_::makeMove(char c) const {
    return move.at(c);
}

void Trie::Node_::makeChild(size_t child, char c) {
    move[c] = child;
}

void Trie::Node_::addEnd(const std::string& word) {
    ++ends_count;
    if (ends_count == 1) {
        containing_word = word;
    }
}

bool Trie::Node_::update(size_t update_count, size_t update_idx) {
    if (update_count <= ends_count) {
        return false;
    }
    best_word_count = update_count;
    best_word_idx = update_idx;
    return true;
}

Trie::Trie() : nodes_(1), last_new_node_(1) {}

Trie::Trie(size_t reserve_nodes) : nodes_(1 + reserve_nodes), last_new_node_(1) {}

size_t Trie::getNewNodeIdx_() {
    if (last_new_node_ == nodes_.size()) {
        nodes_.emplace_back();
    }
    return last_new_node_++;
}

void Trie::makeChild_(size_t parent, size_t child, char c) {
    nodes_[parent].makeChild(child, c);
}

bool Trie::canMakeMove_(size_t node_idx, char c) const {
    return nodes_[node_idx].canMakeMove(c);
}

size_t Trie::makeMove_(size_t node_idx, char c) const {
    return nodes_[node_idx].makeMove(c);
}

void Trie::addEnd_(size_t node, const std::string& word) {
    nodes_[node].addEnd(word);
}

bool Trie::nodeUpdate_(size_t node, size_t update) {
    return nodes_[node].update(nodes_[update].ends_count, update);
}

void Trie::addWord(const std::string& word) {
    size_t curr_node = 0;
    std::vector<size_t> back_propagation;
    back_propagation.reserve(word.size() + 1);
    back_propagation.push_back(curr_node);

    for (char c : word) {
        if (!canMakeMove_(curr_node, c)) {
            makeChild_(curr_node, getNewNodeIdx_(), c);
        }
        curr_node = makeMove_(curr_node, c);
        back_propagation.push_back(curr_node);
    }

    addEnd_(curr_node, word);

    for (size_t it : std::ranges::reverse_view(back_propagation)) {
        if (!nodeUpdate_(it, curr_node)) {
            break;
        }
    }
}