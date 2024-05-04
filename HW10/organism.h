#ifndef ORGANISM_H
#define ORGANISM_H

class World {
    friend class Organism;
    friend class Ant;
    friend class Doodlebug;
    public:
        void initializeWorld();
        void changeWorld_doo(int _x, int _y);
        void changeWorld_ant(int _x, int _y);
        void printWorld();
        char getElement(int x, int y) const { return world[x][y]; }
    private:
        char world[5][5];
};

class Organism {
public:
    virtual void move(World& currWorld) = 0;
    Organism() : x(0), y(0) {} 
    Organism(int _x, int _y) : x(_x), y(_y) {}
    int getX() const { return x; }
    int getY() const { return y; }
protected:
    int x;
    int y;
};

class Ant : public Organism {
public:
    Ant(int _x, int _y) : Organism(_x, _y) {}
    void move(World& currWorld);
};

class Doodlebug : public Organism {
    public:
    Doodlebug(int _x, int _y) : Organism(_x, _y) {}
    void move(World& currWorld);
};

#endif