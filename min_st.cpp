/**
 * \file min_st.cpp
 * Driver code to calculate min-st cut using functions defined in "min_st.h" and "utils.h".  
 */

#include <bits/stdc++.h>
using namespace std;
#include "min_st.h"
#include "utils.h"

/**
 * @brief driver code to run ford fulkerson algorithm, get maximal flow and find the min-st cut.
 * @return integer value 0 on successful run. 
 */
int main(){
	int source, sink;
	vector<vector<edge>> adjacency_matrix = user_input(&source, &sink);
	auto start = chrono::steady_clock::now();
	int max_capacity = min_st_cut(adjacency_matrix, source, sink);
	auto end = chrono::steady_clock::now();
	auto calculation_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	cout << "[RESULT] Max flow capacity (Min-st): " << max_capacity << endl;
	cout << "[RESULT] Time taken (seconds): " << (1.00 * calculation_time)/1000 << endl;
	return 0;
}