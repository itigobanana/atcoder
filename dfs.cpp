#include <bits/stdc++.h>
#include <vector>
using namespace std;

void dfs(int pos){
    visited[pos] = true;
    for (int i=0; i<G[pos].size(); i++){
        int next = G[pos][i];
        if (visited[next] == false) dfs(next);
    }
}

int main() {
    int N,M,a,b;
    vector<int> G[10009];
    bool visited[10009];
    cin >> N >> M;

    for (int i=0; i<M; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    //visitedの1からNにfalse入れて準備する
    for (int i=1; i<=N; i++){
        visited[i] = false;
    }

    //再帰関数で1から端っこまでvisitedの中身を変えてもらう
    dfs(1);

    string Answer = "The graph is connected.";

    for (int i=1; i<=N; i++){
        if(visited[i] == false){
            Answer = "The graph is not connected.";
        }
    }

    cout << Answer << endl;

    return 0;
}