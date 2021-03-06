# Maciej Małecki
# smt116@gmail.com

FLAGS = -W -Wall -ggdb -fPIC
ADDITIONAL_FLAGS = -lrt
OUTPUT = app.out
LIB_NAME = smt_lib
OBJS = main.o vector.o matrix.o time.o lib.o
LIB_OBJS = vector.o matrix.o time.o lib.o
LIBS = lib.h ${ls ./headers/ *.h}

default: libs compile clean

compile: $(OBJS) $(LIBS)
	$(CC) $(FLAGS) $(OBJS) -o $(OUTPUT) $(ADDITIONAL_FLAGS)

libs: $(OBJS) $(LIBS)
	ar rcs $(LIB_NAME).a $(LIB_OBJS)

%.o: %.c $(LIBS)
	$(CC) $(FLAGS) -c $<

clean:
	rm -f *~ *.o .*.swp

veryclean: clean
	rm -f *.in *.out $(OUTPUT) $(LIB_NAME)
