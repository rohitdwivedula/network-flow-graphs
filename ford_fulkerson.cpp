#include <bits/stdc++.h>
using namespace std;
#include "ford_fulkerson.h"
#include "utils.h"
/**
 * @brief driver code to run ford fulkerson algorithm and get maximal flow
 * @return integer value 0 on successful run. 
 */
int main(){
	int source, sink, total_flow;;
	vector<vector<edge>> adjacency_matrix = user_input(&source, &sink);
	auto start = chrono::steady_clock::now();
	vector<vector<int>> final_residual_graph = ford_fulkerson(adjacency_matrix, source, sink, &total_flow);
	auto end = chrono::steady_clock::now();
	auto calculation_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	cout << "[RESULT] Max flow possible (Ford Fulkerson): " << total_flow << endl;
	cout << "[RESULT] Time taken (seconds): " << (1.00 * calculation_time)/1000 << endl;
	return 0;
}