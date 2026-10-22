CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic
ASAN_FLAGS = -fsanitize=address,undefined -g
DEBUG_FLAGS = -g
LDLIBS = -lm
SRC_DIR = src
BUILD_DIR = build

SRCS = $(SRC_DIR)/01-declaracao-struct.c \
       $(SRC_DIR)/02-inicializacao-struct.c \
       $(SRC_DIR)/03-typedef-atribuicao.c \
       $(SRC_DIR)/04-operadores-acesso.c \
       $(SRC_DIR)/05-structs-aninhadas.c \
       $(SRC_DIR)/06-alinhamento-padding.c \
       $(SRC_DIR)/07-passagem-funcoes.c \
       $(SRC_DIR)/08-arranjo-estruturas.c \
       $(SRC_DIR)/09-cadastro-integrador.c

BINS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%,$(SRCS))
ASAN_BINS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%_asan,$(SRCS))

all: $(BINS)

asan: $(ASAN_BINS)

$(BUILD_DIR)/%_asan: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $< -o $@ $(LDLIBS)

$(BUILD_DIR)/%: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDLIBS)

$(BUILD_DIR):
	mkdir -m 755 -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

test: all
	@echo "=== Executando suite de testes de registros ==="
	@for bin in 01-declaracao-struct 02-inicializacao-struct 03-typedef-atribuicao \
	           04-operadores-acesso 05-structs-aninhadas 06-alinhamento-padding \
	           07-passagem-funcoes 08-arranjo-estruturas; do \
		echo "--- Executando $$bin ---"; \
		./$(BUILD_DIR)/$$bin; \
		echo ""; \
	done
	@echo "--- Executando 09-cadastro-integrador (teste automatizado via pipeline) ---"
	@printf "1\n11202410\nLucas\n3.5\n5\n0\n" | ./$(BUILD_DIR)/09-cadastro-integrador
	@echo ""
	@echo "=== Todos os testes foram executados com sucesso! ==="

.PHONY: all asan clean test
