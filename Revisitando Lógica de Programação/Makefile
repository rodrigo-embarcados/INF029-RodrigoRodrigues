# Define o compilador
CC = gcc

# Define as flags do compilador
CFLAGS = -Wall -g

# Encontra todos os arquivos .c no diretório atual
SRC = $(wildcard *.c)

# Define o nome do executável a partir do nome de cada arquivo .c
EXECS = $(SRC:.c=)

# Regra padrão para compilar todos os arquivos .c
all: $(EXECS)

# Regra para gerar os executáveis a partir dos arquivos .c
%: %.c
	$(CC) $(CFLAGS) -o $@ $<

# Regra para limpar os executáveis
clean:
	rm -f $(EXECS)

