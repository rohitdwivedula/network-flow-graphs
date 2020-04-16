#include <bits/stdc++.h>
using namespace std;

struct edge {
	int flow;
	int capacity;
};

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

int get_bottleneck(vector<vector<edge>> adjacency_matrix, vector<int> path){
	int bottleneck = INT_MAX;
	for(int i=0;i<path.size()-1;i++){
		struct edge current_edge = adjacency_matrix[path[i]][path[i+1]];
		int current_value = current_edge.capacity - current_edge.flow;
		if(current_value < bottleneck) bottleneck = current_value;
	}
	return bottleneck;
}

int get_max_flow(vector<vector<edge>> adjacency_matrix, int s, int t)
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
	while(path.size() > 0){
		// augment flow
		int b = get_bottleneck(adjacency_matrix, path);
		bool forward_edge = true; 
		for(int i=0;i<path.size()-1;i++){
			struct edge current_edge = adjacency_matrix[path[i]][path[i+1]];
			if(current_edge.capacity == 0){
				current_edge = adjacency_matrix[path[i+1]][path[i]];
				forward_edge = false;
			}
			assert(current_edge.capacity != 0);
			if(forward_edge){
				current_edge.flow += b;
				residual_graph[path[i]][path[i+1]] -= b;
				residual_graph[path[i+1]][path[i]] += b;
			}
			else{
				current_edge.flow -= b;
				residual_graph[path[i]][path[i+1]] += b;
				residual_graph[path[i+1]][path[i]] -= b;
			}
			adjacency_matrix[path[i]][path[i+1]] = current_edge;
		}
		// check if there's another path
		path = find_augmenting_path(residual_graph, s, t);
	}

	// calculate total flow and return
	int total_flow = 0;
	for(int i=0; i<adjacency_matrix.size();i++){
		total_flow += adjacency_matrix[i][t].flow;
	}
	return total_flow;
}

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
	int flow = get_max_flow(adjacency_matrix, source, sink);
	auto end = chrono::steady_clock::now();
	cout << "Max flow possible (Ford Fulkerson): " << flow << endl;
	auto calculation_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	cout << "[RESULT] Time taken (seconds): " << (1.00 * calculation_time)/1000 << endl;
	return 0;
}