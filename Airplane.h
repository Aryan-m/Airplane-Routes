#ifndef AIRPLANE_H

#define AIRPLANE_H

class Airplane
{
    
public:
    
    //Constructor
    Airplane();
    
    //ID of every airplane
    void airplaneID(){
        string plane1 = "Jetblue";
        string plane2 = "American Airlines";
        string plane3 = "Alaskan Airlines";
        string plane4 = "Ghetto Flights";
        string plane5 = "United Airlines";
    }
    
    //Function which loads up every passenger
    int passengerLoad(int passengers);
    
    //Shows which route the plane will take
    int routeTaken();
    
    //Shows the location of every plane
    string location();
    
    
    //Destructor used to delete any dynamically allocated memory
    ~Airplane();
    
    private:
    
};

#endif