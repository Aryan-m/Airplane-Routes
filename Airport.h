// ************** TO DO *************** //
/*
    1. add an array to store routes
    2. add an array to store planes
    3. delete all arrays in destructor
    4. initialize arrays in constructor
*/

#ifndef Airport_H
  #define Airport_H

#include <iostream>

using namespace std;

// this class stores the Airport information
class Airport
{
public:
      int   ID, // id for airport
            x,  // x coordinate
            y,  // y coordinate
            planesCount, // how many planes are currently here
            time,  // time or day
            population, // how many people are here
            weather, // how is the weather
            routeCount; // how many roads go out from this airport

      Airport(){}
      ~Airport(){}
}; // Airport class

#endif

