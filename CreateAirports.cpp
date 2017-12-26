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
    1. DONE At #APINF32, do the following to create the airport system from inFile. Feel free to modify anything you want.
        DONE A - int i = 0;
        DONE A - Airport *Ap = new Airport*[AirportCount];
        DONE A - While(!EOF)
        DONE P - int temp;
        DONE P - grab AP ID and store in AP[i] and set temp = to it
            DONE A - grab Airport.routeCount from File
            DONE A - grab routeCount for AP[i]
            DONE A - For (number of roads per airport)
            DONE K - grab Road ID and put in AP[i].Roads[j]
            DONE K - grab dist and time
            DONE P - set AP[i].Roads[j].dest to inf;
            DONE P-  set AP[i].Roads[j].source to temp;
            DONE K- i++;
    2. Create the stack functions at #stack98
        - There is a testing section for the stack class at #stest876. Delete when done with testing.
            - DONE A create the skeleton for the class
            - DONE P create push function (don't forget to take care of index and count)
            - DONE K create pop function (don't forget to take care of index and count)
*/

#include <iostream>
#include <fstream>
#include "Airport.h"
#include "Route.h"
#include <vector>
#include <limits>

using namespace std;

//********** Stack to hold the path *********** //
//#stack98
class stack
{
    private:
        int index = -1; // index of the element to be popped (last element)
        vector<int> storage; // stores the elements
        int count = 0; // number of elements in the stack, used for function: notEmpty()
    public:

        // push function stores an element in storage
     void push(int n)
    	{
       		storage.push_back(n);
        	count++;
        	index++;
    	}

        // pop function pops an element from storage
    int pop()
        {
        	count--;
        	index--;
        	return storage[index+1];
		}

        // checks if stack is empty, returns true if not empty
        bool notEmpty()
        {
            if (count > 0)
                return true;
            return false;
        }
        // destructor that deletes storage from memory (hopefully)
        ~stack()
        {
            storage.erase(storage.begin(), storage.end());
        }

}; // end stack

// process an airport
void processAP(int ID, int dep, Airport *AP)
{
	int distance = 0;
	// set distance
	if (ID == dep)
	{
		AP[ID].dv = distance;
	}
	else 
		distance = AP[ID].dv;
	
	// process routes
	for (int i = 0; i < AP[ID].routeCount; i++)
	{
		if (AP[AP[ID].routes[i].dest].known)
			continue;
		if(AP[ID].routes[i].dist + distance <  AP[AP[ID].routes[i].dest].dv)
		{
			AP[AP[ID].routes[i].dest].dv =  AP[ID].routes[i].dist + distance;
			AP[AP[ID].routes[i].dest].pv =  ID;
		}
	}
	AP[ID].known = true;
	
}

// store the path in the stack
void storePath(stack& st,Airport AP[], int ID)
{
	if (AP[ID].dv == 0)
		return;
	else
	{
		st.push(AP[ID].pv);
		storePath(st, AP, AP[ID].pv);
	}
}

// process the path
void Dij(int dest, int dep, stack& st, Airport *AP, int apCount)
{
	// first airport
	processAP(dep, dep, AP);
	
	// other airports
	while (!AP[dest].known)
	{
		int temp = numeric_limits<int>::max(),
			ID = 0;
		
		//set smallest dv to temp
		for (int i = 0; i < apCount; i++)
		{
			if (AP[i].known)
				continue;
			if (temp > AP[i].dv)
			{
				temp = AP[i].dv;
				ID = i;
			}
		}
		processAP(ID, dep, AP);
	}	
}

// to process the choice
void processChoice(Airport AP[], int apCount)
{
	int dest,
		dep;
	stack st;
	
	do {
		cout << "Please Enter Source: ";
		cin >> dep;
		cout << "\nPlease Enter Destination: ";
		cin >> dest;
		if (dep >= apCount || dep < 0 || dest >= apCount || dest < 0 )
		{
			dest = dep;
		}
		if (dep == dest)
			cout << "\nInvalid Input!\n\n";
	} while (dep == dest);
	cout << "\nThe Shortest Path is: ";
	Dij(dest, dep, st, AP, apCount);
	st.push(dest);
	storePath(st, AP, dest);
	while (st.notEmpty())
		cout << st.pop() << " ";
	cout << " which is " << AP[dest].dv << endl;
		
}

int main()
{
/*#stest876 ********** delete once testing the  stack class is done ********** //
    stack st;
    for (int i = 0; i < 45; i += 5)
    {
        st.push(i);
        cout << i << "   ";
    }
        cout << endl << endl;
    while (st.notEmpty())
        cout << st.pop() << "  ";
    cout << endl;
// ********************************************************** */

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

// ****************** BODY *********************** //
    // grab airport and routes counts from file
    inf >> apCount >> routeCount; // #grabFile123

    // set up Airport array's size
    AP = new Airport[apCount];

    // grab airport info #APINF32
    for(int i = 0; i < apCount; i++)
    {
        int temp;
        inf >> AP[i].ID;    //grab AP ID and store in AP[i].ID
        temp = AP[i].ID;

        inf >> AP[i].routeCount;
        AP[i].routes = new Route[routeCount];
        for(int j = 0; j < AP[i].routeCount; j++)
        {
            inf >> AP[i].routes[j].rdID; //grab road id for each road
            inf >> AP[i].routes[j].dist; //grab distance for each road
            inf >> AP[i].routes[j].time; //grab time for each road
            inf >> AP[i].routes[j].dest; //grab destination for each road
            AP[i].routes[j].source = temp; //sets temp value to source
        }
    }

    inf.close();
	
	processChoice(AP, apCount);
    return 0;
} // end of main
