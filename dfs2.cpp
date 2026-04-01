#include <bits/stdc++.h>
#include <vector>
using namespace std;

int N,M,a,b;
bool visited[100009];
vector<int> G[100009];
vector<int> path;

void dfs(int now,int n){
    visited[now] = true;
    path.push_back(now);

    if (now == n){
        for (auto& e : path){
            cout << e << " ";
        }
        cout << endl;
    }

    for (int i=0; i<(int)G[now].size(); i++){
        if (visited[G[now][i]] == false){
            int next = G[now][i];
            dfs(next,n);
        }
    }

    path.pop_back();
}

int main() {
    cin >> N >> M;
    for (int i=0; i<M; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1,N);

    return 0;
}