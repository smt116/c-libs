# Maciej Małecki
# smt116@gmail.com

FLAGS = -Wall -ggdb -ansi -fPIC
OUTPUT = app.out
LIB_NAME = smt_lib
OBJS = main.o lib.o vector.o matrix.o time.o
LIB_OBJS = lib.o vector.o matrix.o time.o
LIBS = lib.h vector.h matrix.h time.h

default: libs compile clean

compile: $(OBJS) $(LIBS)
	$(CC) $(FLAGS) $(OBJS) -o $(OUTPUT)

libs: $(OBJS) $(LIBS)
	ar rcs $(LIB_NAME).a $(LIB_OBJS)

%.o: %.c $(LIBS)
	$(CC) $(FLAGS) -c $<

clean:
	rm -f *~ *.o .*.swp

veryclean: clean
	rm -f *.in *.out $(OUTPUT) $(LIB_NAME)
