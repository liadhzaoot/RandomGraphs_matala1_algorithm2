#pragma once
#include "Node.h"
class Graph
{
private:
	Node** graph; // arr of V
	int v; //v - number of cross (int number)
	int p; //p - probability of edge (double between 0 to 1)
public:
	Graph(int v);
	void addEdge(int i, int data);
	void graph_random_build(int v, double p);
	int* BFS(int s);
	int diam();
	int max_distance(int* distance,int n);
	void printGraph();
	bool hasEdge(int i, int j);
	bool is_isolated();
	bool connectivity();

};

