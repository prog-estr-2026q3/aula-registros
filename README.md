# Exemplos de código - registros e estruturas (structs)

Este diretório contém todos os códigos de exemplo apresentados no capítulo 06 (registros e estruturas heterogêneas / `struct`) das notas de aula da disciplina de programação estruturada (MCTA028-15).

---

## Estrutura do projeto

```
.
├── Makefile
├── README.md
├── .gitignore
├── .devcontainer/   # Configuração de ambiente para dev container / GitHub Codespaces
├── src/             # Códigos-fonte (.c) dos exemplos
└── build/           # Executáveis compilados (ignorado pelo git)
```

---

## Como compilar e executar

### 1. Compilar todos os programas

Para compilar todos os programas da coleção:

```bash
make
```

Os binários correspondentes serão gerados no diretório `build/`.

### 2. Executar a suíte de testes rápidos

Para compilar e disparar a execução de todos os programas conceituais e a validação integrada do sistema de cadastro:

```bash
make test
```

### 3. Compilação com AddressSanitizer (ASan)

Para compilar todas as fontes com sanitizadores de memória e comportamento indefinido (`-fsanitize=address,undefined -g`):

```bash
make asan
```

Os executáveis instrumentados receberão o sufixo `_asan` em `build/` (por exemplo, `build/08-arranjo-estruturas_asan`).

### 4. Execução manual de um programa específico

Após compilar com `make`, você pode executar qualquer binário individualmente a partir do diretório raiz do projeto:

```bash
./build/01-declaracao-struct
./build/06-alinhamento-padding
./build/07-passagem-funcoes
./build/08-arranjo-estruturas
./build/09-cadastro-integrador
```

### 5. Limpar os arquivos compilados

Para remover o diretório `build/` e todos os executáveis gerados:

```bash
make clean
```

---

## Descrição dos exemplos em `src/`

- `01-declaracao-struct.c`: Sintaxe de declaração de novos tipos de dados heterogêneos (`struct`), instanciação em memória, inspeção de endereços de campos individuais e comparação de `sizeof` com a soma dos membros.
- `02-inicializacao-struct.c`: Formas de inicialização de estruturas em C (posicional clássica, inicializadores designados do padrão C99, omissão de campos com zeramento implícito e inicialização nula completa `{0}`).
- `03-typedef-atribuicao.c`: Simplificação sintática com `typedef`, semântica de cópia integral bit a bit (*shallow copy*) na atribuição entre estruturas e comprovação de independência dos blocos de memória.
- `04-operadores-acesso.c`: Acesso direto aos campos via operador ponto (`.`), desreferenciação explícita de ponteiro `(*ptr).campo` e sintaxe idiomática com operador seta (`ptr->campo`).
- `05-structs-aninhadas.c`: Composição de tipos abstratos incorporando uma estrutura como campo de outra (`Data` em `Aluno`), acesso encadeado e análise da contiguidade espacial na memória.
- `06-alinhamento-padding.c`: Requisitos de alinhamento por hardware, inserção de bytes de preenchimento (*padding*), medição de *offsets* de campos com a macro `offsetof` (`<stddef.h>`) e otimização por ordenação decrescente de tamanho dos membros.
- `07-passagem-funcoes.c`: Análise dos três paradigmas de comunicação com funções: retorno por valor, passagem por valor (cópia na pilha e isolamento de mutações) e passagem por referência usando ponteiros (`const Tipo *` para leitura eficiente de 8 bytes vs. `Tipo *` mutável para alteração no chamador).
- `08-arranjo-estruturas.c`: Agrupamento contíguo de registros em arranjos unidimensionais, endereçamento físico com saltos regulares de `sizeof(Aluno)`, rotinas de inserção sequencial e remoção com preservação de ordem por deslocamento à esquerda.
- `09-cadastro-integrador.c`: Aplicação integrada de CRUD (criação, busca linear por RA, atualização com validação de domínio de CR, remoção ordenada e listagem completa) gerenciando um arranjo de registros com menu interativo.

---

## Utilização com Docker / Dev Container

Este repositório inclui suporte pronto para desenvolvimento em contêineres:

- **VS Code com extensão Dev Containers:** abra esta pasta e selecione **"Reopen in Container"** quando solicitado. O ambiente Alpine Linux com GCC, Make e Musl-Dev será configurado automaticamente.
- **GitHub Codespaces:** crie um ambiente na nuvem com um clique diretamente a partir da interface do GitHub para compilar e depurar os códigos no navegador.
