#include "../include/Point.h"

Point::Point(){

}

Point::Point(int x, int y){
    _x = x;
    _y = y;
}

Point::Point(int x, int y, int z){
    _x = x;
    _y = y;
    _z = z;
}

//Converts the point to an integer
int Point::toInt(){

    int retInt;

    retInt = _x * 100;
    retInt += _y * 10;
    retInt += _z;

    return retInt;
}

bool Point::compare(Point cmpPoint){

    bool retBool;

    if(cmpPoint._x == _x && cmpPoint._y == _y && cmpPoint._z == _z){

        return true;
    }

    return false;
}