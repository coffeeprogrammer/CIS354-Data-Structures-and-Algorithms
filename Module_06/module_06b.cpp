// Chad Botting
// Module 06 - CIS 354 UMA
// April 26, 2015
#include <iostream>
#include <string>
#include <vector>
#include "WeightedGraph.h"
#include "WeightedEdge.h"
using namespace std;

void travel(WeightedGraph<string> graphOfCities)
{
	cout << "the cities you can travel to or from are \n" ;
	for (int i = 0 ; i < graphOfCities.getSize() ; i++)
		cout << graphOfCities.getVertex(i) << endl;

	string departureCity;
	string destinationCity;
	cout << "Please enter departure city: ";
	getline(cin, departureCity);
	cout << "Please enter the destination city: ";
	getline(cin, destinationCity);

	int cityIndexDeparture =  graphOfCities.getIndex(departureCity);
	int cityIndexDestination = graphOfCities.getIndex(destinationCity);

	if ( cityIndexDeparture != -1 && cityIndexDestination != -1)
	{	
		vector<int> aPath = graphOfCities.getPath(cityIndexDeparture, cityIndexDestination);

		for (int i = 0; i < aPath.size(); i++)
			cout << graphOfCities.getVertex(aPath[i]) << endl;
	}
	else
	{
		cout << "the city you entered does not seem to be on our map!" << endl ;
	}
}


int main()
{
	// Vertices for graph in Figure 24.1
	string vertices[] = {"Seattle", "San Francisco", "Los Angeles",
		"Denver", "Kansas City", "Chicago", "Boston", "New York",
		"Atlanta", "Miami", "Dallas", "Houston"};

	// Edge array for graph in Figure 24.1
	int edges[][3] = {
		{0, 1, 807}, {0, 3, 1331}, {0, 5, 2097},
		{1, 0, 807}, {1, 2, 381}, {1, 3, 1267},
		{2, 1, 381}, {2, 3, 1015}, {2, 4, 1663}, {2, 10, 1435},
		{3, 0, 1331}, {3, 1, 1267}, {3, 2, 1015}, {3, 4, 599}, {3, 5, 1003},
		{4, 2, 1663}, {4, 3, 599}, {4, 5, 533}, {4, 7, 1260}, {4, 8, 864}, {4, 10, 496},
		//{4, 2, 1663}, {4, 3, 1}, {4, 5, 533}, {4, 7, 1}, {4, 8, 864}, {4, 10, 496},
		{5, 0, 2097}, {5, 3, 1003}, {5, 4, 533}, {5, 6, 983}, {5, 7, 787},
		{6, 5, 983}, {6, 7, 214},
		{7, 4, 1260}, {7, 5, 787}, {7, 6, 214}, {7, 8, 888},
		{8, 4, 864}, {8, 7, 888}, {8, 9, 661}, {8, 10, 781}, {8, 11, 810},
		{9, 8, 661}, {9, 11, 1187},
		{10, 2, 1435}, {10, 4, 496}, {10, 8, 781}, {10, 11, 239},
		{11, 8, 810}, {11, 9, 1187}, {11, 10, 239}
	};
	const int NUMBER_OF_EDGES = 46; // 46 edges in Figure 24.1

	// Create a vector for vertices
	vector<string> vectorOfVertices(12);
	copy(vertices, vertices + 12, vectorOfVertices.begin());

	// Create a vector for edges
	vector<WeightedEdge> edgeVector;
	for (int i = 0; i < NUMBER_OF_EDGES; i++)
		edgeVector.push_back(WeightedEdge(edges[i][0],
		edges[i][1], edges[i][2]));

	WeightedGraph<string> graph1(vectorOfVertices, edgeVector);


	travel(graph1);

	return 0;
}
