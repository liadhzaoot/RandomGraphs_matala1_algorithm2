#pragma once
#include<iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <list>
#include "Node.h"
#include "Graph.h"
#include <queue>
using namespace std;
//Node* add_element_first_list(Node* list, int id)
//{
//	Node* head = new Node();
//	head->next = list;
//	head->data = id;
//	return head;
//}
//Node** init_graph_to_Null(Node** graph, int v)
//{
//	for (int i = 0; i < v; i++)
//	{
//			graph[i] = NULL;
//	}
//	return graph;
//}
////v - number of cross (int number)
////p - probability of edge (double between 0 to 1)
//Node** graph_random_build(int v, double p)
//{
//	double probability_rand;
//	/* initialize random seed: */
//	srand((unsigned)time(NULL));
//	Node** graph = new Node*[v];
//	graph = init_graph_to_Null(graph, v);
//	for (int i = 0; i < v; i++)
//	{ 
//		for (int j = 0; j < v; j++)
//		{
//			probability_rand = (float)rand() / RAND_MAX;/* generate probability_rand number between 0 and 1: */
//			if (probability_rand < p && i != j)//check the probability 
//			{
//				graph[i] = add_element_first_list(graph[i], j);
//			}
//		}
//		graph[i] = add_element_first_list(graph[i], i); // the main cross 
//	}
//	return graph;
//}
//
//void print_graph(Node** graph,int v)
//{
//	int j = 0;
//	Node* p;
//	for (int i = 0; i < v; i++)
//	{
//		p = graph[i];
//		while (p != NULL)
//		{
//			cout << p->data << " -> ";
//			p = p->next;
//		}
//		cout <<"\n ";
//	}
//}
void printArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "d[" << i << "] = " << arr[i] << " \n";
	}
}
void main()
{
	//int v = 3;
	//Node** graph = new Node * [v];
	//graph = graph_random_build(v, 0.5);
	//print_graph(graph, v);

	int v = 3;
	double p = 0.2;
	int* d;
	Graph graph(3);
	graph.graph_random_build(v, p);
	graph.printGraph();
	d = graph.BFS(0);
	printArr(d, v);
	int diam = graph.diam();


	cout << "-------------------------- \n";
	cout << "diam = " << diam<<"\n";
	cout<<"is isolated? "<< graph.is_isolated() << "\n";
	cout << "connectivity?" << graph.connectivity() << "\n";
	//cout << "----------------";
	//queue<int> q;
	//q.push(4);
	//cout << q.front();

}