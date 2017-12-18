#ifndef ROUTE_H
#define ROUTE_H

class Route
{
	public:
		int id; //route id number
		int cost; //cost of route
		int duration; //duration of route
		int dep; //departure location
		int dest; //destination location
		int wt_dep; //weather at departure
		int wt_dest; //weather at destination
		int time; //time
		int plane; //what plane will go through this route
	protected:
};

#endif
