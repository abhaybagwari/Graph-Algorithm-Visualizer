#ifndef GRAPH_H
#define GRAPH_H
#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    int n;
    vector<vector<pair<int,int>>>adj;
    vector<vector<int>>matrix;
    Graph(int n){
        this->n=n;
        adj.resize(n+1);
        matrix.assign(n+1,vector<int>(n+1,0));
    }
    void addedge(int u,int v, int w){
        if(u<1 || v<1 || v>n){
            cout<<"invalid edge:"<<u<<" "<<endl;
            return;
        }
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        matrix[u][v]=w;
        matrix[v][u]=w;
        cout<<"Edge added:"<<u<<" - "<<v<<"(weight "<<w<<")"<<endl;
    }
    void showadjlist(){
        cout<<"\n--ADJACENCY LIST--\n";
        for(int i=1;i<=n;i++){
            cout<<i<<" -> ";
            for(auto x:adj[i]){
                cout<<"("<<x.first<<","<<x.second<<")";
            }
            cout<<endl;
        }
    }
    void showmatrix(){
        cout<<"\n--ADJACENCY MATRIX--\n";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
#endif