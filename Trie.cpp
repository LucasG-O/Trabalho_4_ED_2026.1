#include "Trie.hpp"
#include <cctype>

TrieNode::TrieNode() {
    this->isEndOfTitle = false;
    this->game = nullptr;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        this->children[i] = nullptr;
    }
}

TrieNode::~TrieNode() {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (this->children[i] != nullptr) {
            delete this->children[i];
        }
    }
}

Trie::Trie() {
    this->root = new TrieNode();
}

Trie::~Trie() {
    delete this->root;
}

int Trie::getIndex(char c){//funcao auxiliar para retornar o indice
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    } else if (c >= '0' && c <= '9') {
        return 26 + (c- '0');
    }
    return -1; //caracter deve ser ignorado
}


bool Trie::insert(Game* game) {
    TrieNode* currentNode = this->root;
    std::string searchKey = toSearchKey(game->getTitle());

    for (char c : searchKey) {
        int index = getIndex(c);
        
        if(index == -1){
            continue; // ignorar caracteres nao alfanumericos
        }
        if (currentNode->children[index] == nullptr) {
            currentNode->children[index] = new TrieNode();
        }
        currentNode = currentNode->children[index];
    }

    if (currentNode->isEndOfTitle) {
        return false; // jogo ja existe
    }

    currentNode->isEndOfTitle = true;
    currentNode->game = game;
    return true;
}

std::string Trie::toSearchKey(std::string text){

    std::string searchKey = "";

    //percorremos caracter por caracter e adicionamos os que nao sao ' '
    for (int i = 0; i < text.length(); i++){
        char c = text[i];
    
        if (c != ' '){
            searchKey += std::tolower(c);// transformamos em minusculas
        }
    }
    return searchKey;
}

bool Trie::contains(std::string title){
    std:: string titulo = toSearchKey(title);

    TrieNode* cursor = root;

    for (int i = 0; i < titulo.length(); i++){
        char c = titulo[i]; 
        int indice = getIndex(c);

        if(indice == -1){
            continue; // ignorar caracteres nao alfanumericos
        }
        if (cursor->children[indice] == nullptr){return false;} // palavra nao existe no catalogo
        
        cursor = cursor->children[indice]; // proxima letra
    }
    return cursor->isEndOfTitle;
}

void Trie::sortResults(std::vector<Game*>& games){
    int n = games.size();
    bool trocou = false;

    for(int i = 0; i < n-1; i++){
        trocou = false;

        for (int j = 0; j < n-1; j++){
            Game* atual = games[j];
            Game* proximo = games[j+1];

            bool precisaTrocar = false;

            if (atual->getPopularity() < proximo->getPopularity()) {
                precisaTrocar = true;
            }
            else if(atual-> getPopularity() == proximo->getPopularity()){
                // pega as chaves de busca para comparar
                std::string chaveAtual = toSearchKey(atual->getTitle());
                std::string chaveProximo = toSearchKey(proximo->getTitle());

                if (chaveAtual > chaveProximo) {
                    precisaTrocar = true;
                }
            }
            if (precisaTrocar) {
                Game* temp = games[j];
                games[j] = games[j+1];
                games[j+1] = temp;
                
                trocou = true; // marca que houve pelo menos uma troca nesta passada
            }
        }
        // otimizacao: se nao houve nenhuma troca nesta passada, o vetor esta ordenado
        if (!trocou) {
            break;
        }
    }
}

void Trie::collectGames(TrieNode* node, std::vector<Game*>& resultados) {
    if (node == nullptr) {
        return;
    }
    // se o no atual é o fim de uma palavra valida, guarda o jogo no vetor
    if (node->isEndOfTitle) {
        resultados.push_back(node->game);
    }
    // chama a si mesma para olhar todos os 36 caminhos possiveis para baixo
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        collectGames(node->children[i], resultados);
    }
}

std::vector<Game*> Trie::autocomplete(std::string prefix, int k){
    std::vector<Game*> resultados;

    if (k <= 0){
        return resultados;
    }
//formatacao
    std::string searchKey = toSearchKey(prefix);
    TrieNode* cursor = this->root;

    for (int i = 0; i < searchKey.length(); i++){
        char c = searchKey[i];
        int indice = getIndex(c);

        if(indice == -1){
            continue; // ignorar caracteres nao alfanumericos
        }
        // Se o caminho quebrar (nullptr), significa que nenhum jogo começa com esse prefixo
        if (cursor->children[indice] == nullptr) {
            return resultados; // retorna o vetor vazio
        }
        cursor = cursor->children[indice];
    }
    collectGames(cursor, resultados);

    sortResults(resultados);
    if (resultados.size() > k) {
        resultados.resize(k); // mantem apenas os k primeiros resultados
    }
    return resultados;
}