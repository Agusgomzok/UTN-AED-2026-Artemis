# Compilador y Banderas
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LDFLAGS = -lm

# Carpetas y Archivos
SRC_DIR = src
OBJ_DIR = build
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Detección de Sistema Operativo (Windows vs Linux/Mac)
ifeq ($(OS),Windows_NT)
    EXEC = artemis_sim.exe
    MKDIR = if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
    CLEAN = if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR) & if exist $(EXEC) del /f /q $(EXEC)
else
    EXEC = artemis_sim
    MKDIR = mkdir -p $(OBJ_DIR)
    CLEAN = rm -rf $(OBJ_DIR) $(EXEC)
endif

# Regla principal
all: $(EXEC)

# Regla para enlazar el ejecutable
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Regla para compilar los .c en .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar los compilados
clean:
	$(CLEAN)

.PHONY: all clean