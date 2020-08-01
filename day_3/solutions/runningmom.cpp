#include <bits/stdc++.h>
#define MAXN 5050

using namespace std;

int next_id = 0;
vector<string> rev_mapping(MAXN);
unordered_map<string, int> mapping;

vector<vector<int>> adj_map (MAXN);

vector<bool> visited;

bool find_cycle(int u) {
	if (visited[u]) {
		return true;
	}
	visited[u] = true;

	for (int v : adj_map[u]) {
		if (find_cycle(v)) {
			return true;
		}
	}
	visited[u] = false;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int m;
	cin >> m;

	for(int i = 0; i<m; i++) {
		string from, to;
		cin >> from >> to;
		
		int from_id, to_id;
		if (mapping.find(from) == mapping.end()) {
			from_id = next_id++;
			mapping[from] = from_id;
			rev_mapping[from_id] = from;
		} else {
			from_id = mapping[from];
		}

		if (mapping.find(to) == mapping.end()) {
			to_id = next_id++;
			mapping[to] = to_id;
			rev_mapping[to_id] = to;
		} else {
			to_id = mapping[to];
		}

		adj_map[from_id].push_back(to_id);
	}

	string query;
	while (cin >> query) {
		visited.assign(MAXN, false);
		if (find_cycle(mapping[query])) {
			cout << query << " safe" << endl;
		} else {
			cout << query << " trapped" << endl;
		}
	}
}
