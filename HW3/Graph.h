#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <iostream>

using namespace std;

struct EdgeNode {
	int y;
	int weight;
	string name;
	struct EdgeNode* next;
};

class Graph {

private:
	static const int MAXV = 20;
	EdgeNode* edges[MAXV + 1] = {};

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
		edges[i]->name = name;
	}

	/**
	 * Add an edge from i to j with weight d 
	 */
	void link(int i, int j, int d) 
	{
		auto temp = edges[i];
		while (edges[i]->next != nullptr)
		{
			temp = temp->next;
		}

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
		auto temp = edges[i];
		while (edges[i]->next != edges[j])
		{
			temp = temp->next;
		}
		temp->next = temp->next->next;
		delete temp->next;
	}


	/**
	 * Prints a listing of all edges in the graph
	 * Each edge is listed as: name of  source node, name of destination node, distance between the two
	 */
	void dump() 
	{
		auto temp = edges[0];
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
		
	}
	
	/**
	 * Prints all the "dead end" nodes in the network. A node is a “dead end” if it has  an out-degree of zero.  
	 */
	void dend() 
	{
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