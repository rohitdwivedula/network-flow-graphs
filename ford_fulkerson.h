/**
 * \file ford_fulkerson.h
 * Defines functions to calculate maximal flow, and residual graphs using Ford Fulkerson algorithm.  
 */
#ifndef FORD_FULKERSON_H
#define FORD_FULKERSON_H
#include <bits/stdc++.h>
using namespace std;

struct edge {
	int flow;
	int capacity;
};

/**
 * @brief find an augmenting path (if it exists) using BFS
 * @param residual_graph the residual graph of the network. 
 * @param start node at which to start the BFS, i.e. source
 * @param end node at which BFS ends, i.e. sink
 * @return a vector containing a list of nodes (the path), or an empty list if no path exists
 */
vector<int> find_augmenting_path(vector<vector<int>> residual_graph, int start, int end){
	vector<bool> discovered(residual_graph.size(), false); 
	discovered[start] = true;
	vector<int> queue;
	queue.push_back(start);
	unordered_map<int, int> parent;
	bool found = false;
	while(queue.size() != 0){
		int v = queue[0];
		queue.erase(queue.begin());
		if (v == end){
			found = true;
			break;
		}
		for(int i=0;i<residual_graph.size();i++){
			if(residual_graph[v][i] != 0 && !discovered[i]){
				queue.push_back(i);
				discovered[i] = true;
				parent[i] = v;
			}
		}
	}

	// calculate path from start to end
	vector<int> path;
	if(found){
		int current_element = end;
		while(current_element != start){
			path.push_back(current_element);
			current_element = parent[current_element];
		}
		path.push_back(start);
		reverse(path.begin(), path.end());
	}
	return path;
}


/**
 * @brief for a given path, find the bottleneck limiting the flow
 * @param adjacency_matrix adjacency matrix of the flow network
 * @param path list of nodes
 * @return integer value, representing the bottleneck value.
 */
int get_bottleneck(vector<vector<int>> residual_graph, vector<int> path){
	int bottleneck = INT_MAX;
	for(int i=0;i<path.size()-1;i++){
		int current_value = residual_graph[path[i]][path[i+1]];
		if(current_value < bottleneck) bottleneck = current_value;
	}
	return bottleneck;
}


/**
 * @brief find the maximal flow rate of a given graph from source to sink
 * @param s source
 * @param t sink
 * @return final residual graph.
 */
vector<vector<int>> ford_fulkerson(vector<vector<edge>> adjacency_matrix, int s, int t, int* max_flow)
{
	vector<vector<int>> residual_graph;
	for(int i = 0; i<adjacency_matrix.size();i++){
		vector<int> row;
		for(int j=0;j<adjacency_matrix.size();j++){
			row.push_back(adjacency_matrix[i][j].capacity);
		}
		residual_graph.push_back(row);
	}

	vector<int> path = find_augmenting_path(residual_graph, s, t);
	*max_flow = 0;
	while(path.size() > 0){
		// augment flow
		int b = get_bottleneck(residual_graph, path);
		for(int i=0;i<path.size()-1;i++){
			residual_graph[path[i]][path[i+1]] -= b;
			residual_graph[path[i+1]][path[i]] += b;
		}
		*max_flow += b;
		// check if there's another path
		path = find_augmenting_path(residual_graph, s, t);
	}
	return residual_graph;
}

#endif