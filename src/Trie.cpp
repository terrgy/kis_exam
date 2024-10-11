#include <ranges>

#include "Trie.h"

Trie::Node_::Node_() : ends_count_(0), best_word_count_(0), best_word_idx_(0) {}

bool Trie::Node_::canMakeMove(char c) const {
    return move_.contains(c);
}

size_t Trie::Node_::makeMove(char c) const {
    return move_.at(c);
}

void Trie::Node_::makeChild(size_t child, char c) {
    move_[c] = child;
}

void Trie::Node_::addEnd(const std::string& word) {
    ++ends_count_;
    if (ends_count_ == 1) {
        containing_word_ = word;
    }
}

bool Trie::Node_::update(size_t update_count, size_t update_idx) {
    if (update_count <= best_word_count_) {
        return false;
    }
    best_word_count_ = update_count;
    best_word_idx_ = update_idx;
    return true;
}

std::string Trie::Node_::getContainingWord() const {
    return containing_word_;
}

size_t Trie::Node_::getEndsCount() const {
    return ends_count_;
}

size_t Trie::Node_::getBestWordIdx() const {
    return best_word_idx_;
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
    return nodes_[node].update(nodes_[update].getEndsCount(), update);
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

std::pair<size_t, size_t> Trie::move(const std::string& word, size_t start_idx, size_t start_node) {
    if (start_node >= last_new_node_) {
        throw std::runtime_error("Bad start_node parameter");
    }

    size_t curr_node = start_node;
    size_t read_count = 0;

    for (size_t i = start_idx; i < word.size(); ++i) {
        if (!canMakeMove_(curr_node, word[i])) {
            return {curr_node, read_count};
        }
        curr_node = makeMove_(curr_node, word[i]);
        ++read_count;
    }
    return {curr_node, read_count};
}

std::string Trie::getBestWord(size_t node) {
    if (node >= last_new_node_) {
        throw std::runtime_error("Bad node parameter");
    }

    size_t best_word_idx = nodes_[node].getBestWordIdx();
    return nodes_[best_word_idx].getContainingWord();
}