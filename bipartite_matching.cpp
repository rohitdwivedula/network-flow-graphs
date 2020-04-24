#include <bits/stdc++.h>
using namespace std;

typedef long long li;

/**
 * @brief check if a matching vertex for u is possible
 * @param adj adjacency matrix
 * @param u vertex
 * @param seen has a vertex been seen yet?
 * @return boolean value
 */
bool bpm(vector<vector<bool>> &adj,li u,vector<bool> &seen, vector<li> &matchR){
	li M = adj.size();
	li N = adj[0].size();

	for(li v = 0; v < N; v++){
		if(adj[u][v] && !seen[v]){
			seen[v] = true;

			if(matchR[v] < 0 || bpm(adj,matchR[v],seen,matchR)){
				matchR[v] = u;
				return true;
			}
		}
	}
	return false;
}

/**
 * @brief find the maximal matxhing's size
 * @adj adjacency matrix
 * @return integer represting the maximal matching portion
 */
int maxBPM(vector<vector<bool>> &adj){
	li M = adj.size();
	li N = adj[0].size();
	vector<li> matchR(N,-1);
	li result = 0;
	for(li u = 0;u < M;u++){
		vector<bool> seen(N,false);
		if(bpm(adj,u,seen,matchR))
			result++;
	}
	for (int i = 0; i < N; ++i){
		if(matchR[i] != -1)
			cout<<matchR[i]<<"->"<<i<<endl;
	}
	return result;
}

/**
 * @brief driver code to run the bipartite matching algo
 * @return integer 0 on successful execution
 */
int main(){
	auto total_start = chrono::steady_clock::now();

	li E,V1,V2;
	cin>>E>>V1>>V2;
	
	vector<vector<bool>> adj(V1,vector<bool> (V2,false));
	li aux1,aux2;
	
	for (li i = 0; i < E; ++i){
		cin>>aux1>>aux2;
		adj[aux1-1][aux2-1] = 1;
	}
	
	cout<<"---------MATCHINGS---------"<<endl;
	auto algo_start = chrono::steady_clock::now();
	cout<<maxBPM(adj)<<endl;
	auto total_end = chrono::steady_clock::now();

	auto total_time = chrono::duration_cast<chrono::milliseconds>(total_end - total_start).count();
	auto algo_time = chrono::duration_cast<chrono::milliseconds>(total_end - algo_start).count();
	
	cout<<"TOTAL TIME: "<<(1.00*total_time/1000)<<" seconds"<<endl;
	cout<<"ALGORITHM TIME: "<<(1.00*algo_time/1000)<<" seconds"<<endl;
	return 0;
}