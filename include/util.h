#ifndef UTIL_H
#define UTIL_H


enum Direction {north, south, east, west};

class Location {
public:

    Location(): x(-1), y(-1) {}
    Location(int x_coord, int y_coord): x(x_coord), y(y_coord) {}

    int x;
    int y;
};


#endif // UTIL_H
