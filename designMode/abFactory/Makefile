CC = g++
TARGET = myprogram
SOURCES = $(wildcard ./*.cc)
OBJECTS = $(SOURCES:.cc=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "Linking..."
	$(CC) $^ -o $@

./%.o: ./%.cc
	@echo "Compiling $<..."
	$(CC) -c $< -o $@

.PHONY: clean
clean:
	rm -rf ./*.o ./myprogram