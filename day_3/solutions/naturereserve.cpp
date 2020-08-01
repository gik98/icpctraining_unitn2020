#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;

struct Edge {
	int from, to, cost;
	Edge(){}
	Edge (int from, int to, int cost): from(from), to(to), cost(cost) {}
};

struct EdgeCmp {
	bool operator() (const Edge& lhs, const Edge& rhs) {
		return lhs.cost > rhs.cost;
	}
};

int main() {
	int T;
	cin >> T;

	for (int t = 0; t<T; t++) {
		int N, M, L, S;
		cin >> N >> M >> L >> S;
		
		vector<int> stations;
		vector<vector<Edge>> adj_list(MAXN);

		for (int i = 0; i<S; i++) {
			int s;
			cin >> s;
			stations.push_back(s);
		}

		for (int i = 0; i<M; i++) {
			Edge e;
			cin >> e.from >> e.to >> e.cost;

			adj_list[e.from].push_back(e);
			adj_list[e.to].push_back(Edge(e.to, e.from, e.cost));
		}
		
		/*
		 * Prim's algorithm; initialize search from all stations
		 */
		
		priority_queue<Edge, vector<Edge>, EdgeCmp> pq;
		vector<bool> included(N, false);
		long long int mst = 0;

		for (int station: stations) {
			included[station] = true;
			for (Edge e: adj_list[station]) {
				if (!included[e.to]) {
					pq.push(e);
				}
			}
		}

		while(!pq.empty()) {
			Edge e = pq.top();
			pq.pop();

			if (!included[e.to]) {
				included[e.to] = true;
				mst += L;
				mst += e.cost;
				
				for (Edge f: adj_list[e.to]) {
					if (!included[f.to]) {
						pq.push(f);
					}
				}

			}
		}

		cout << mst << endl;

	}
}
