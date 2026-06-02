#include <iostream>
#include <string>
#include <vector>
#include "Trie.hpp"
#include "Game.hpp"
#include "GamesDatabase.hpp"

int main(int argc, char* argv[]) {
    
    // verifica a quantidade de argumentos passados via terminal
    if (argc != 3) {
        std::cerr << "Erro: Numero incorreto de argumentos.\n";
        std::cerr << "Uso: ./app <quantidade> <prefixo>\n";
        return 1;
    }

    // armazena os parametros recebidos
    int k = std::stoi(argv[1]);
    std::string prefix = argv[2];

    Trie trie;

    // percorre o array 'games' do arquivo GamesDatabase.hpp e insere na Trie
    for (int i = 0; i < numberOfGames; i++) {
        trie.insert(&games[i]);
    }
    // executa a busca
    std::vector<Game*> resultados = trie.autocomplete(prefix, k);

    if (resultados.empty()) {
        std::cout << "No results found\n";
    } else {
        for (Game* game : resultados) {
            std::cout << game->getTitle() << " | " 
                      << game->getShortDescription() << " | " 
                      << game->getPopularity() << "\n";
        }
    }
    return 0;
}