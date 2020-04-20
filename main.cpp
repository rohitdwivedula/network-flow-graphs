#include <bits/stdc++.h>
using namespace std;
#include "ford_fulkerson.h"

/**
 * @brief driver code to run ford fulkerson algorithm, get maximal flow and find the min-st cut.
 * @return integer value 0 on successful run. 
 */
int main(){
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
	auto start = chrono::steady_clock::now();
	vector<vector<int>> final_residual_graph = ford_fulkerson(adjacency_matrix, source, sink);
	// calculate total flow from final adjacency matrix
	int total_flow = 0;
	for(int i=0; i<adjacency_matrix.size();i++){
		total_flow += adjacency_matrix[i][sink].flow;
	}
	auto end = chrono::steady_clock::now();
	auto calculation_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	cout << "[RESULT] Max flow possible (Ford Fulkerson): " << total_flow << endl;
	cout << "[RESULT] Time taken (seconds): " << (1.00 * calculation_time)/1000 << endl;
	return 0;
}