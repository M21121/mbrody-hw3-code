#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <iostream>

using namespace std;

struct EdgeNode {
	int y;
	int weight;
	struct EdgeNode* next;
};

class Graph {

private:
	static const int MAXV = 20;
	EdgeNode* edges[MAXV + 1] = {};
	string name[20] = {};

public:

	Graph() 
	{
	}

	/**
     * Destructor for the graph
     */
	~Graph() {}

	/**
	 * Associates the name with node i
	 */
	void name(int i, string name) 
	{
		this->name[i] = name;
	}

	/**
	 * Add an edge from i to j with weight d 
	 */
	void link(int i, int j, int d) 
	{
		//Makes Sure edges[i] isn't nullptr
		if (edges[i] == nullptr)
		{
			edges[i] = new EdgeNode;
		}

		//Creates a temp pointer to edges[i]
		EdgeNode* temp = edges[i];

		//Finds last edge in line
		while (edges[i]->next != nullptr)
		{
			temp = temp->next;
		}
		
		//Adds new edge to line
		EdgeNode* newEdgeNode = new EdgeNode();
		newEdgeNode->weight = d;
		newEdgeNode->next = nullptr;
		newEdgeNode->y = j;
		temp->next = newEdgeNode;
	}

	/**
	 * Delete edge i, j if one exists
	 */
	void deleteEdge(int i, int j) 
	{
		auto tmp = edges[i];

		// case 1: first edge in the list
		if (tmp->y == j)
		{
			edges[i] = tmp->next;
			delete tmp;
		}
		// case 2: edge is somewhere else in the list
		auto tmp2 = tmp;
		while (tmp != nullptr)
		{
			if (tmp->y == j)
			{
				tmp2->next = tmp->next;
				delete tmp;
				break;
			}
			tmp2 = tmp;
			tmp = tmp->next;
		}
	}


	/**
	 * Prints a listing of all edges in the graph
	 * Each edge is listed as: name of  source node, name of destination node, distance between the two
	 */
	void dump() 
	{
		EdgeNode* temp = edges[0];
		for (EdgeNode* e : edges)
		{
			temp = e;
			while (temp != nullptr)
			{
				cout << temp->y << "->";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	/**
	 * Print the shortest path from s to g
	 */
	void path(int s, int g) 
	{
			int i;					/* counter */
			EdgeNode* p;			/* temporary pointer */
			bool intree[MAXV + 1];	/* is the vertex in the tree yet? */
			int distance[MAXV + 1];	/* cost of adding to tree */
			int v; 					/* current vertex to process */
			int w;					/* candidate next vertex */
			int dist;				/* cheapest cost to enlarge tree */
			int weight = 0;			/* tree weight */

			for (i = 1; i <= 20; i++)
			{
				intree[i] = false;
				distance[i] = INT_MAX;
				parent[i] = -1;
			}

			distance[s] = 0;
			v = i;
			while (!intree[v]) 
			{
				intree[v] = true;
				if (v != i) 
{				{
					printf("edge (%d,%d) in tree \n"
						 ,parent[v],v);
					weight=weight+dist;
				}
				p = edges[v];
				while (p != NULL) 
				{
					w = p->y;
					if (distance[w] > (distance[v] + p->weight)) 
					{
						distance[w] = distance[v] + p -> weight;
						parent[w] = v;
					}
					p = p->next;
				}
				/* CHANGED *//* CHANGED *//* CHANGED */
				dist = INT_MAX;
				for (i = 1; i <= 20; i++) 
				{
					if ((!intree[i]) && (dist > distance[i]))
					{
						dist = distance[i];
						v = i;
					}
				}
			}
				//PRINT STATEMENT HERE??
		}
	}
	
	/**
	 * Prints all the "dead end" nodes in the network. A node is a “dead end” if it has  an out-degree of zero.  
	 */
	void dend() 
	{
		cout << "Dead ends: " << endl;
		for (EdgeNode* e : edges)
		{
			if (e->next == nullptr)
			{
				cout << e->y << endl;
			}
		}
	}

	/**
	 * Prints all the "inaccessible" nodes in the network. A node is “inaccessible” if it has an in-degree of zero. 
	 */
	void inacess() 
	{
		bool found = false;
		auto temp = edges[0];
		for (EdgeNode* e : edges)
		{
			bool found = false;
			for (EdgeNode* f : edges)
			{
				temp = f;
				while (temp != nullptr)
				{
					if (temp == e)
					{
						found = true;
					}
					temp = temp->next;
				}
				if (found)
				{
					break;
				}
				cout << endl;
			}
			if (!found)
			{
				cout << e->y << endl;
			}
		}
	}

	// Note: you may need more instance variables (ivars) here depending on your implementation;

};

#endif