#include "Graph.h"
#pragma once
#include "string.h"
#include <string.h>
#include <math.h>
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <queue>
using namespace std;

Graph::Graph(int v)
{
	this->v = v;
	this->graph = new Node * [v];
	for (int i = 0; i < v; i++)
	{
		graph[i] = NULL;
	}
}
//add edge to cross i the cross data
void Graph::addEdge(int i, int data)
{
		Node* head = new Node();
		head->data = data;
		head->next = this->graph[i];
		this->graph[i] = head;
}
void Graph::graph_random_build(int v, double p) {
	double probability_rand;
	/* initialize random seed: */
	srand((unsigned)time(NULL));
	//Node** graph = new Node * [v];
	//graph = init_graph_to_Null(graph, v);
	for (int i = 0; i < v; i++)
	{
		for (int j = i; j < v; j++)
		{
			probability_rand = (float)rand() / RAND_MAX;/* generate probability_rand number between 0 and 1: */
			if ((probability_rand < p) && (i != j))//check the probability 
			{
				addEdge(i, j);
				addEdge(j, i);
			}
		}
		//graph[i] = add_element_first_list(graph[i], i); // the main cross 
	}
}
bool Graph::hasEdge(int i, int j)
{
	Node* p = this->graph[i];
	while (p != NULL)
	{
		if (p->data == j)
		{
			return true;
		}
		p = p->next;
	}
	return false;
}

void Graph::printGraph() {
	int j = 0;
	Node* p;
	for (int i = 0; i < v; i++)
	{
		p = this->graph[i];
		while (p != NULL)
		{
			cout << p->data << " -> ";
			p = p->next;
		}
		cout << "\n ";
	}
}

//BFS -  O(E+V)
int* Graph::BFS(int current_node)
{
	int s; // for each cross

	bool* visited = new bool[this->v];
	int* distance = new int[this->v];
	//init distance and visited
	for (int i = 0; i < this->v; i++)
	{
		visited[i] = false;
		distance[i] = -1;
	}
	queue<int> queue;// Create a queue for BFS
	Node* p;
	
	 // Mark the current node as visited and enqueue it 
	visited[current_node] = true;
	queue.push(current_node);
	//mark the current node 0 distance
	distance[current_node] = 0;
	while (!queue.empty())
	{
		s = queue.front();
		queue.pop();
		p = this->graph[s];// the next cross linked to current_node
		while (p != NULL)//run on s cross neighbors 
		{
			if (!visited[p->data]) //check if visited
			{
				visited[p->data] = true;//mark as visit
				queue.push(p->data); // push to queue
				distance[p->data] = distance[s] + 1;//increase the distance 
			}
			p = p->next;//next neighbor
		}
	}
	return distance;//return the distance arr
}

//O(V * (V+E) )
int Graph::diam()
{
	int diam = 0;
	int* distance_arr;
	int last_vertex; // last maximum
	if (!this->connectivity())
		return -1; // not have diam
	for (int i = 0; i < this->v; i++)
	{
		distance_arr = this->BFS(i);
		last_vertex = max_distance(distance_arr, this->v);
		if (diam < last_vertex)
			diam = last_vertex;
	}
	return diam;
}
int Graph::max_distance(int* distance,int n)
{
	int max = distance[0];
	for (int i = 1; i < n; i++)
	{
		if (max < distance[i])
			max = distance[i];
	}
	return max;
}
bool Graph::is_isolated()
{
	for (int i = 0; i < this->v; i++)
	{
		if (this->graph[i] == NULL)
			return true;
	}
	return false;
}
bool Graph::connectivity()
{

	int* distance_arr;
	//if have cross isolated the graph is not connectivity
	if (this->is_isolated())
		return false;
	distance_arr = BFS(0);
	for (int i = 0; i < this->v; i++)
	{
		if (distance_arr[i] == -1)
			return false;
	}
	return true;
}

