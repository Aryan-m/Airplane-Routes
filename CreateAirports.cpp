/*
    ******************* NOTES *****************
    1. Format of inFile has changed to
        1st line: AirportCount RoutesCount
        rest of Lines: AirportID numberOfRoutes routeID1 miles hour routeID2 miles hour ...

    2. Name of the file is Airports.txt and is in the same directory as the main file. Program will not run otherwise.

    3. Code IDs in the format "#ID" will be put at code portions that need to be refered to later.

    4. To access code IDs just copy them, and search for them in the file.

    5. Code IDs will be put on the same line or at the beginning line of each portion that they refer to.

    6. If you do not know how to grab from a file, refer to Code ID: "#grabFile123"

    7. Make sure to run your files and make sure they compile before uploading them.

    8. In the "To DO" list  make sure to put "DONE" before each line once it has been implemented.

    9. Put "DONE" before each numbered item on the "TO DO" list upon completion.

    10. Learn vectors (no longer necessary as we will not use vectors, but arrays.

    11. Do NOT use teeth during any attempts to get an 'A' or a promotion as it has been proven to not work.

    12. I will be in my office all day today and tomorrow. If you have any questions or want any 'A's, please drop by ;P.

    ******************* TO DO *****************
    1. At #APINF32, do the following to create the airport system from inFile. Feel free to modify anything you want.
        DONE A - int i = 0;
        DONE A - Airport *Ap = new Airport*[AirportCount];
        DONE A - While(!EOF)
            P - int temp;
            P - grab AP ID and store in AP[i] and set temp = to it
            DONE A - grab Airport.routeCount from File
            DONE A - grab routeCount for AP[i]
            DONE A - For (number of roads per airport)
            DONE K - grab Road ID and put in AP[i].Roads[j]
            DONE K - grab dist and time
                P - set AP[i].Roads[j].dest to inf;
                P-  set AP[i].Roads[j].source to temp;
            DONE K- i++;
*/

#include <iostream>
#include <fstream>
#include "Airport.h"
#include "Route.h"

using namespace std;

int main()
{
// ***************** OPEN FILE ************ //
    ifstream inf("./Airports.txt");
    if (!inf) // if file could not be found or DNE
    {
        cout << "       *** File Not Found! ***\n\n"
             << "Note that the name should be Airports.txt \n"
             << "   in the same directory as the main file\n";
        return 0;
    }

// ****************** VARIABLES ****************** //
    int apCount,  // holds the number of airports
        routeCount; // holds the total number of routes
    Airport *AP;  // an array to hold airport objects
    
    int i; // dummy counter


// ****************** BODY *********************** //
    // grab airport and routes counts from file
    inf >> apCount >> routeCount; // #grabFile123

    // set up Airport array's size
    AP = new Airport[apCount];

    // grab airport info #APINF32
    i = 0; // to go through each airport in AP
    while(!inf.eof())
    {
        inf >> AP[i].routeCount;
        AP[i].routes = new Route[routeCount];
        for(int j = 0; j < AP[i].routeCount; j++)
        {
        	inf >> AP[i].routes[j].rdID; //grab road id for each road
        	inf >> AP[i].routes[j].dist; //grab distance for each road
        	inf >> AP[i].routes[j].time; //grab time for each road
        }
       i++;
    }

    inf.close();
    return 0;
} // end of main
