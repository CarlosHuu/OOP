all: brave_tour
.PHONY: clean
CC = g++
FLAGS = -std=c++17 -g

brave_tour: main.o maze.o block.o player.o wall.o empty.o goal.o obstacle.o portal.o key.o  monster.o exp_potion.o hp_potion.o
	$(CC) $(FLAGS) main.o maze.o block.o player.o wall.o empty.o goal.o obstacle.o portal.o key.o  monster.o exp_potion.o hp_potion.o -o brave_tour

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -c

maze.o: maze.cpp maze.h
	$(CC) $(FLAGS) maze.cpp -c
 
block.o: block.cpp block.h
	$(CC) $(FLAGS) block.cpp -c
 
player.o: player.cpp player.h
	$(CC) $(FLAGS) player.cpp -c

wall.o: wall.cpp wall.h
	$(CC) $(FLAGS) wall.cpp -c
 
empty.o: empty.cpp empty.h
	$(CC) $(FLAGS) empty.cpp -c

goal.o: goal.cpp goal.h
	$(CC) $(FLAGS) goal.cpp -c

obstacle.o: obstacle.cpp obstacle.h
	$(CC) $(FLAGS) obstacle.cpp -c

portal.o: portal.cpp portal.h
	$(CC) $(FLAGS) portal.cpp -c

key.o: key.cpp key.h
	$(CC) $(FLAGS) key.cpp -c

# moveablegoal.o: moveablegoal.cpp moveablegoal.h
# 	$(CC) $(FLAGS) moveablegoal.cpp -c

monster.o: monster.cpp monster.h
	$(CC) $(FLAGS) monster.cpp -c

exp_potion.o: exp_potion.cpp exp_potion.h
	$(CC) $(FLAGS) exp_potion.cpp -c

hp_potion.o: hp_potion.cpp hp_potion.h
	$(CC) $(FLAGS) hp_potion.cpp -c
  
clean:
	rm -rf *.o brave_tour

