#ifndef PRIM_H
#define PRIM_H
#include "graph.h"
void prim(Graph &g){
    vector<int>key(g.n+1,INT_MAX);
    vector<bool>mst(g.n+1,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    key[1]=0;
    pq.push({0,1});
    int total=0;
    int step=1;
    while (!pq.empty())
    {
        cout<<"Step "<<step++<<endl;
        cout<<"PQ: ";
        auto temp=pq;
        while (!temp.empty())
        {
            cout<<"("<<temp.top().second<<","<<temp.top().first<<")";
            temp.pop();
        }
        cout<<endl;
        int u=pq.top().second;
        pq.pop();
        if(mst[u])continue;
        mst[u]=true;
        total+=key[u];
        for(auto x:g.adj[u]){
            int v=x.first;
            int wt=x.second;
            if(!mst[v ]&& wt < key[v]){
                key[v]=wt;
                pq.push({key[v],v});
                cout<<"Update: "<<v<<endl;
            }
        }
        cout<<endl;
    }
    cout<<"MST Cost: "<<total<<endl;
}
#endif