#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include"graph.h"
void dijkstra(Graph &g,int src){
    vector<int>dist(g.n+1,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    dist[src]=0;
    pq.push({0,src});
    int step=1;
    cout<<"--Dijksta Starting--"<<endl;
    while (!pq.empty())
    {
        cout<<"Step "<<step++<<endl;
        cout<<"PQ: ";
        auto temp=pq;
        while(!temp.empty()){
            cout<<"("<<temp.top().second<<","<<temp.top().first<<")";
            temp.pop();
        }
        cout<<endl;
        int node=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        cout<<"Process: "<<node<<endl;
        for(auto x:g.adj[node]){
            int v=x.first;
            int wt=x.second;
            if(dist[node]+wt<dist[v]){
                dist[v]=dist[node]+wt;
                pq.push({dist[v],v});
                cout<<"Update: "<<v<<" -> "<<dist[v]<<endl;

            }
            
        }
        cout<<endl;
    }
    cout<<"Final Distance:\n";
    for(int i=1;i<=g.n;i++){
        cout<<i<<" -> "<<dist[i]<<endl;
    }

}
#endif