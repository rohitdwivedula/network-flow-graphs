/**
 * \file bipartite_matching.cpp
 * Driver code to solve the bipartite matching problem.  
 */
#include <bits/stdc++.h>
#include "ford_fulkerson.h"
#include "utils.h"
using namespace std;

int main(){
	//Take user input
	int v1;
	vector<vector<edge>> adj = user_input_2(&v1);
	int vertices = adj.size()-2;
	//Start clock
	auto algo_start = chrono::steady_clock::now();

	//Get residual graph
	int total_flow;
	vector<vector<int>> res = ford_fulkerson(adj,0,vertices+1,&total_flow);
	int m = 0;
	for(int i=1;i<res.size()-1;i++){
		for(int j=1;j<res.size()-1;j++){
			if(adj[i][j].capacity-res[i][j] > 0 && i!=j){
				cout<<"( "<<i<<" -> "<<j-v1<<" )"<<endl;
				m++;
			}
		}
	}

	//Print results
	cout<<"[RESULT] TOTAL NUMBER OF MATCHINGS: "<<m<<endl;
	auto total_end = chrono::steady_clock::now();
	auto algo_time = chrono::duration_cast<chrono::milliseconds>(total_end - algo_start).count();
	cout<<"[RESULT] ALGORITHM TIME: "<<(1.00*algo_time/1000)<<" seconds"<<endl;
	return 0;
}