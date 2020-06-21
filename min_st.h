#ifndef MIN_ST_H
#define MIN_ST_H
#include <bits/stdc++.h>
#include "ford_fulkerson.h"
using namespace std;

/**
 * @brief find all reachable nodes from a given node in the graph using depth first search
 * @param graph graph to consider. 
 * @param visited a set of all the reachable nodes so far
 */
void dfs(vector<vector<int>> graph, int start, unordered_set<int>& visited)
{
	visited.insert(start);
	for(int i=0;i<graph.size();i++){
		if(graph[start][i] != 0 && start != i && !visited.count(i)){
			dfs(graph, i, visited);
		}
	}
}

/**
 * @brief find the min-st cut using the given residual graph. Prints each set, and the list of edges between them
 * @param adjacency matrix of the flow graph. 
 * @param s source
 * @param t sink
 * @return integer, capacity of the minimum cut
 */
int min_st_cut(vector<vector<edge>> adjacency_matrix, int s, int t){
	int max_flow;
	vector<vector<int>> final_residual_graph = ford_fulkerson(adjacency_matrix, s, t, &max_flow);
	unordered_set<int> reachable;
	dfs(final_residual_graph, s, reachable);
	cout <<"============== MIN-ST CUT =============="<<endl;
	cout <<"Set 1 (containing s): ";
	for(int i=0;i<adjacency_matrix.size();i++){
		if(reachable.count(i) > 0){
			cout << i << " ";
		}
	}
	cout <<"\nSet 2 (containing t): ";
	for(int i=0;i<adjacency_matrix.size();i++){
		if(!reachable.count(i)){
			cout << i << " ";
		}
	}
	cout << "\nMin cut edges:\n\n";
	int total = 0;
	for(int i=0;i<adjacency_matrix.size();i++){
		for(int j=0;j<adjacency_matrix.size();j++){
			if(reachable.count(i) && !reachable.count(j) && adjacency_matrix[i][j].capacity != 0){
				cout << i << "->" << j << "(" << adjacency_matrix[i][j].capacity << ")" <<endl;
				total += adjacency_matrix[i][j].capacity;
			}
		}
	}
	return total;
}

#endif