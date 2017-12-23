// ************** TO DO *************** //
/*
*/

#ifndef Airport_H
  #define Airport_H

#include <iostream>
#include "Route.h"
#include <limits>
using namespace std;

// this class stores the Airport information
class Airport
{
public:
      bool known; //For D's algorithm
      int   ID, // id for airport
            dV,
            pV,
            planesCount, // how many planes are currently here
            time,  // time or day
            population, // how many people are here
            weather, // how is the weather
            routeCount; // how many roads go out from this airport
       Route* routes;  // list of the routes to this airport
       //Airplane *planes; // list of the planes curently in this aiport

      Airport() : dv(numeric_limits<int>::max()), pv(-1), known(false) {}
      /* same as
      {
        dv = numeric_limits<int>::max();
        pv = -1;
        known = false;
      }
      */
      ~Airport()
      {
        // free memory
        delete routes;
      }
}; // Airport class

#endif
