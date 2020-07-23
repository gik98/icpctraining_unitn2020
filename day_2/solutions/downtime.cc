#include <iostream>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    priority_queue<pair<double, int>> q;
    int m = 0;
    for(int i = 0; i < N; i++) {
        double t;
        cin >> t;
        q.push({-t, 1});
        q.push({-(t + 1000 - 0.1), 0});
    }

    int current = 0;

    while(!q.empty()) {
        auto x = q.top();
        q.pop();
        if(x.second == 1) current++;
        else current--;

        m = max(m, current);
    }

    double res = (double) m / K;
    cout << ceil(res) << endl;

    return 0;
}