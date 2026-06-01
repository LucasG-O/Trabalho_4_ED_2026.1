# Trabalho_4_ED_2026.1
# Sistema de Autocomplete de Jogos — C++ (Trie)

## Descrição

Sistema de autocomplete para um catálogo de jogos implementado em C++. A aplicação permite buscar rapidamente os títulos a partir de prefixos parciais, oferecendo as seguintes funcionalidades:

- Busca *case-insensitive* (ignora diferença entre maiúsculas e minúsculas).
- Filtro de caracteres (ignora espaços em branco e mantém números).
- Ordenação manual dos resultados por popularidade decrescente via **Bubble Sort**.
- Desempate por ordem alfabética da chave de busca formatada.
- Retorno limitado a uma quantidade `k` de sugestões.

O projeto foi desenvolvido para a disciplina de Estruturas de Dados, focado na implementação manual de uma árvore de busca de prefixos (**Trie**), controle rígido de vazamento de memória e proibição de bibliotecas de ordenação padrão da STL.

---

## Organização dos arquivos

```text
Trabalho_4_ED_2026.1/
├── Game.hpp              # Declaração da classe Game (title, shortDescription, popularity)
├── Game.cpp              # Implementação dos métodos e construtores de Game
├── Trie.hpp              # Declaração da árvore, do nó da árvore (TrieNode) e métodos auxiliares
├── Trie.cpp              # Implementação do algoritmo de busca, inserção e Bubble Sort
├── GamesDatabase.hpp     # Declaração do array de jogos da base de dados
├── GamesDatabase.cpp     # Base de dados estática fornecida para testes
└── main.cpp              # Interface CLI para recebimento de argumentos e execução
