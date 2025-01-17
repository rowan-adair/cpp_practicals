#include "Graph.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;

Graph::Graph(char* fname)
{

	edges = nullptr;

	ifstream fin(fname);
	if (!fin) {
		cout << "Can't open file : " << fname << endl;
		return;
	}

	fin >> num_v;

	char c;
	fin >> c;
	
	if (c == 'd')
		directed = true;
	else if (c == 'u')
		directed = false;

	edges = new double* [num_v];

	for (int i = 0; i < num_v; i++)
	{	
		int num_values = 0;
		
		directed ? num_values = num_v : num_values = i + 1;
		
		edges[i] = new double[num_values];

		for (int j = 0; j < num_values; j++)
			edges[i][j] = 0.0;
	}

	int source, destination;
	
	double weight;

	while (fin >> source >> destination >> weight) {
		
		edges[source][destination] = weight;

		if (!directed && destination > source) {
			edges[destination][source] = weight;
		}
	}
}

Graph::~Graph()
{
	for (int i = 0; i < num_v; i++)
		delete[] edges[i];
	delete[] edges;
}

double Graph::get_edge(int source, int dest) const
{
	return edges[source][dest];
}



