#ifndef KIS_EXAM_TASK_H
#define KIS_EXAM_TASK_H

#include <string>
#include "Trie.h"

class Task {
private:
    Trie trie_;
    std::string input_buffer_;
    size_t current_input_idx_;
    size_t current_node_;

    bool tryMoveRequest_();
    std::string moveRequest_();

public:
    Task();
    void addText(const std::string& text);
    std::string request(const std::string& str);
    std::string appendToRequest(const std::string& str);
};

#endif //KIS_EXAM_TASK_H
