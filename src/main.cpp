#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "../include/Point.h"

using namespace std;

//Generate all points in 3d space, given the bounds of the system
map<int, Point> generatePoints(int bounds[3]){

    map<int, Point> allPoints;

    for(int i = 0; i <= bounds[0]; i++){

        for(int j = 0; j <= bounds[1]; j++){
            for(int z = 0; z <= bounds[2]; z++){

                Point currPoint = Point(i, j, z);
                allPoints[currPoint.toInt()] = currPoint; 
            }
        }
    }

    return allPoints;
} 

// Determine the position of a missle from all positions it isnt
Point isFromAllIsnt(int bounds[3], Point MISSILE_POS){

    Point retPoint = Point(-1,-1,-1);
    map<int, Point> allMissileIsnt = generatePoints(bounds);

    //Remove the position of the missle from the data
    allMissileIsnt.erase(MISSILE_POS.toInt());
    map<int, Point> allPoints = generatePoints(bounds);

    //Find the key not present in map, return corresponding Point
    for(map<int, Point>::iterator it = allPoints.begin(); it != allPoints.end(); ++it){
        
        if(allMissileIsnt.count(it->first) == 0){
            retPoint = it->second;
            break;
        }
    }
    
    return retPoint;
}


int main(){

    //Bounds of the system, inclusive
    int bounds[3] = {3, 3, 3};

    
    Point MISSILE_POS = Point(1,2,1);
    Point missilePos = isFromAllIsnt(bounds, MISSILE_POS);
    if(MISSILE_POS.compare(missilePos) || MISSILE_POS.toInt() == missilePos.toInt()){
        cout << "Missile Found";
    }
    else{
        cout << "Missile not found";
    }


    return 0;
}