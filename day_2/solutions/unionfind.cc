#include <iostream>
#include <vector>
using namespace std;
struct UnionFind {
    vector<int> C;
    UnionFind(int n) : C(n) { for (int i = 0; i < n; i++) C[i] = i; }
    int find(int x) { return (C[x] == x) ? x : C[x] = find(C[x]); }
    void merge(int x, int y) { C[find(x)] = find(y); }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q;
    cin>>N>>Q;
    UnionFind uf(N);
    for(int i=0;i<Q;i++) {
        char command;
        int a, b;
        cin>>command>>a>>b;
        if(command == '?') {
            bool res = (uf.find(a) == uf.find(b));
            if(res) cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        } else {
            uf.merge(a,b);
        }
    }
    return 0;
}
