#ifndef POINT_H
#define POINT_H

class Point{

    private:
    int _x;
    int _y;
    int _z;

    public:
    // Constructors for 2d and 3d points
    Point();
    Point(int x, int y);
    Point(int x, int y, int z);
    
    int toInt();
    bool compare(Point cmpPoint);
};

#endif 