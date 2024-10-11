#include "Task.h"
#include "Trie.h"
#include <sstream>

Task::Task() : current_input_idx_(0), current_node_(0) {}

bool Task::tryMoveRequest_() {
    auto [move_end_node, move_end_index] = trie_.move(input_buffer_, current_input_idx_);
    current_node_ = move_end_node;
    if (move_end_index < input_buffer_.size()) {
        current_input_idx_ = move_end_index;
        return false;
    }
    input_buffer_.clear();
    current_input_idx_ = 0;
    return true;
}

std::string Task::moveRequest_() {
    if (tryMoveRequest_()) {
        return trie_.getBestWord(current_node_);
    }
    return "The request doesn't match any word";
}

void Task::addText(const std::string& text) {
    std::stringstream ss(text);
    std::string word;
    while (ss >> word) {
        trie_.addWord(word);
    }
    if (current_input_idx_ >= input_buffer_.size()) {
        tryMoveRequest_();
    }
}

std::string Task::request(const std::string& str) {
    input_buffer_ = str;
    current_input_idx_ = 0;
    return moveRequest_();
}

std::string Task::appendToRequest(const std::string &str) {
    input_buffer_.append(str);
    return moveRequest_();
}
