// ************** TO DO *************** //
/*
*/

#ifndef Airport_H
  #define Airport_H

#include <iostream>
#include "Route.h"

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
       Route* routes;  // list of the routes to this airport
       //Airplane *planes; // list of the planes curently in this aiport

      Airport(){}
      ~Airport()
      {
        // free memory
        routes.clear();
        vector<Route>(routes).swap(routes);
      }
}; // Airport class

#endif
