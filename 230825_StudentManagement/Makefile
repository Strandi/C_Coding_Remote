# Compiler
CC = gcc

# Compiler-Flags
CFLAGS = -Wall -Wextra

# Dateinamen
SOURCES = main.c student.c file.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = student_manager

# Standardziel ("all")
all: clean $(EXECUTABLE)

# Kompilieren der Quelldateien zu einem ausführbaren Programm
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@
	./$(EXECUTABLE) # Führt das Programm nach der Kompilierung aus

# Erzeugen der Objektdateien aus den Quelldateien
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# "clean"-Ziel zum Löschen der generierten Dateien
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
