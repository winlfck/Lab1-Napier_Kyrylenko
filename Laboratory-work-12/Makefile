# Змінні компілятора та прапорців
CC = gcc
CFLAGS = -Wall -I/usr/include/postgresql
LIBS = -lpq
# Список об'єктних файлів
OBJ = connect_employer.o add_employer.o get_employer.o employer.o
# Цільова програма
TARGET = employer
# Шлях для інсталяції (домашній каталог користувача)
INSTALL_DIR = $(HOME)/bin

# Головна ціль (збірка програми)
$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(LIBS)

# Правило для створення .o файлів з .c
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Очищення (видалення тимчасових файлів)
clean:
	rm -f *.o $(TARGET)

# Інсталяція (копіювання в ~/bin)
install:
	mkdir -p $(INSTALL_DIR)
	cp $(TARGET) $(INSTALL_DIR)
