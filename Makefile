# Maciej Małecki
# smt116@gmail.com

# Flagi dla kompilatora
FLAGS = -Wall -ggdb
# Nazwa programu wyjsciowego
OUTPUT = app.out
# Nazwa plikow obiektowych
OBJS = main.o lib.o vector.o matrix.o time.o
# Nazwa plikow naglowkowych
LIBS = lib.h vector.h matrix.h time.h

# Domyslna regola
default: compile clean

# Kompilacja
compile: $(OBJS) $(LIBS)
	$(CC) $(FLAGS) $(OBJS) -o $(OUTPUT)

# Regula (pattern)
%.o: %.c $(LIBS)
	$(CC) $(FLAGS) -c $<

clean:
	rm -f *~ *.o .*.swp

veryclean: clean
	rm -f *.in *.out $(OUTPUT)
