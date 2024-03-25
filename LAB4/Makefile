# Compiler & Linker settings
CC = g++
CFLAGS = -g -Wall

# Valgrind for memory issue
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s --show-leak-kinds=all --track-origins=yes 
OBJS = CNumpy.o Solution_Checker.o Random_Matrix_Generator.o
TARGET = Lab4-1 Lab4-2

all: $(TARGET)

Lab4-1: $(OBJS)
	$(CC) $(CFLAGS) main1.cpp $^ -o $@

Lab4-2: $(OBJS)
	$(CC) $(CFLAGS) main2.cpp $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

check1:
	$(CHECKCC) $(CHECKFLAGS) ./Lab4-1

check2:
	$(CHECKCC) $(CHECKFLAGS) ./Lab4-2

clean:
	rm -rf $(TARGET) $(OBJS) matrix_testcase/Hidden*