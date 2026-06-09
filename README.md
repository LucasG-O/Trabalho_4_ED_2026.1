# Sistema de Autocomplete de Jogos — C++ (Trie)

## Descrição

Sistema de autocomplete para um catálogo de jogos implementado em C++. A aplicação permite buscar rapidamente os títulos a partir de prefixos parciais, oferecendo as seguintes funcionalidades:

- Busca case-insensitive (ignora diferença entre maiúsculas e minúsculas).
- Filtro de caracteres (ignora espaços em branco e mantém números).
- Ordenação manual dos resultados por popularidade decrescente via **Bubble Sort**.
- Desempate por ordem alfabética da chave de busca formatada.
- Retorno limitado a uma quantidade k de sugestões.

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
```

| Arquivo | Responsabilidade |
|---|---|
| `Game.hpp / .cpp` | Modela a entidade do jogo encapsulando seus dados e getters |
| `Trie.hpp / .cpp` | Contém a lógica de mapeamento (0-35 para letras e números) e travessia dos nós |
| `main.cpp` | Trata os inputs do usuário no terminal, instancia a árvore e processa a saída |

---

## Instruções de compilação

### Pré-requisito

Compilador C++ com suporte a C++11 ou superior (g++ ou equivalente).

### Compilar com g++

Abra o terminal no diretório raiz do projeto e execute:

```bash
g++ main.cpp Game.cpp Trie.cpp GamesDatabase.cpp -o app
```

---

## Instruções de execução

Após a compilação, o programa é executado via interface de linha de comando (CLI), exigindo a passagem de dois parâmetros: a quantidade máxima de resultados (`k`) e o prefixo desejado.

```bash
# Linux / macOS
./app <quantidade> <prefixo>

# Windows
app.exe <quantidade> <prefixo>
```

> **Importante:** Se o prefixo da sua busca possuir espaços, você deve obrigatoriamente passá-lo entre aspas no terminal.

---

## Exemplos de Uso

| Tipo de Busca | Comando no Terminal | Saída Esperada |
|---|---|---|
| **Busca Simples** | `./app 3 ha` | `Hades \| Roguelike de acao baseado na mitologia grega \| 95`<br>`Half Life \| FPS classico de ficcao cientifica \| 92`<br>`Halo \| FPS futurista com campanha e multiplayer \| 85` |
| **Busca com Espaços** | `./app 5 "half l"` | `Half Life \| FPS classico de ficcao cientifica \| 92` |
| **Busca Inexistente** | `./app 3 zelda` | `No results found` |

---

## Autores

Projeto desenvolvido para fins acadêmicos na disciplina de Estruturas de Dados.
- Gabriel Bittencourt Dias
- Lucas Gabriel de Oliveira
