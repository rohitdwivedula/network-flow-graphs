#ifndef UTILS_H
#define UTILS_H
#include "ford_fulkerson.h"
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief find all reachable nodes from a given node in the graph using depth first search
 * @param graph graph to consider.
 * @param _source (call by reference) location to save the source
 * @param _sink (call by reference) location to save the sink
 */
vector<vector<edge>> user_input(int* _source, int* _sink)
{
	int vertices, edges;
	cin >> vertices >> edges;
	int source, sink;
	cin >> source >> sink;
	vector<vector<edge>> adjacency_matrix;
	// create one row of adjacency matrix
	vector<edge> row;
	for(int i=0;i<vertices;i++){
		struct edge e;
		e.flow = 0;
		e.capacity = 0;
		row.push_back(e);
	}
	for(int i=0;i<vertices;i++){
		adjacency_matrix.push_back(row);
	}
	for(int i=0;i<edges;i++){
		int start, end, capacity;
		cin >> start >> end >> capacity;
		adjacency_matrix[start][end].capacity = capacity;
	}
	*_sink = sink;
	*_source = source;
	return adjacency_matrix;
}

#endif