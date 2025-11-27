TARGET = bin/socket_test
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

default: $(TARGET)

clean:
	rm -rf $(TARGET)
	rm -rf obj/*.o

$(TARGET): $(OBJ)
	gcc -o $@ $^ -Iinclude

obj/%.o: src/%.c
	gcc -c $< -o $@ -Iinclude
