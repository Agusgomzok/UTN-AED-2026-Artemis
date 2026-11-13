# Compilador y Banderas
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LDFLAGS = -lm

# Carpetas y Archivos
SRC_DIR = src
OBJ_DIR = build
INC_DIR = include
EXEC = artemis_sim

# Fuentes y Objetos
SRCS = $(wildcard$(SRC_DIR)/*.c)
OBJS = $(patsubst$(SRC_DIR)/%.c, $(OBJ_DIR)/\%.o, $(SRCS))

# Regla principal
all: $(EXEC)

# Regla para enlazar el ejecutable
$(EXEC):$(OBJS)
	$(CC)$(OBJS) -o $@ $(LDFLAGS)

# Regla para compilar los .c en .o
$(OBJ_DIR)/\%.o:$(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC)$(CFLAGS) -c $< -o$@

# Regla para limpiar los compilados
clean:
	rm -rf $(OBJ_DIR)$(EXEC)

.PHONY: all clean