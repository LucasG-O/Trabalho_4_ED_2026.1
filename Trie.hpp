#include "Game.hpp"
#include <vector>
#include <string>
#define ALPHABET_SIZE 36 // 26 letras + 10 digitos numericos

class TrieNode {

public:

    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfTitle;
    Game* game;

    TrieNode();
    ~TrieNode();
};

class Trie {

private:

    TrieNode* root;

public:

    Trie();
    ~Trie();

    bool insert(Game* game);
    bool contains(std::string title);

    std::vector<Game*> autocomplete(std::string prefix, int k);

    std::string toSearchKey(std::string text);
    void sortResults(std::vector<Game*>& games);

    // Outros métodos auxiliares, se necessário
};