#ifndef KIS_EXAM_TRIE_H
#define KIS_EXAM_TRIE_H

#include <unordered_map>
#include <string>
#include <vector>

class Trie {
private:
    struct Node_ {
    private:
        std::unordered_map<char, size_t> move_;
        size_t ends_count_;
        size_t best_word_count_;
        size_t best_word_idx_;
        std::string containing_word_;

    public:
        Node_();

        bool canMakeMove(char c) const;
        size_t makeMove(char c) const;
        void makeChild(size_t child, char c);
        void addEnd(const std::string& word);
        bool update(size_t update_count, size_t update_idx);

        std::string getContainingWord() const;
        size_t getEndsCount() const;
        size_t getBestWordIdx() const;
    };

    std::vector<Node_> nodes_;
    size_t last_new_node_;

    size_t getNewNodeIdx_();

    bool canMakeMove_(size_t node_idx, char c) const;
    size_t makeMove_(size_t node_idx, char c) const ;
    void makeChild_(size_t parent, size_t child, char c);
    void addEnd_(size_t node, const std::string& word);
    bool nodeUpdate_(size_t node, size_t update);

public:
    Trie();
    explicit Trie(size_t reserve_nodes);

    void addWord(const std::string& word);
    std::pair<size_t, size_t> move(const std::string& word, size_t start_node);
    std::string getBestWord(size_t node);
};

#endif //KIS_EXAM_TRIE_H
