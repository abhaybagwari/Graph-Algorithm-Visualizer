#ifndef BFS_H
#define BFS_H
#include"graph.h"
void printqueue(queue<int>q){
    cout<<"Queue: ";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
void bfs(Graph &g ,int start){
    vector<bool> visited(g.n+1,false);
    queue<int>q;
    vector<int>order;
    int step=1;
    q.push(start);
    visited[start]=true;
    cout<<"\n--BFS Travesal--\n";
    while(!q.empty()){
        cout<<"Step "<<step++<<endl;
        printqueue(q);
        int node=q.front();
        q.pop();
        cout<<"Visit: "<<node<<endl;
        order.push_back(node);
        for(auto x:g.adj[node]){
            if(!visited[x.first]){
                visited[x.first]=true;
                q.push(x.first);
                cout<<"Push: "<<x.first<<endl;
            }
        }
        cout<<endl;
    }
    cout<<"Final BFS Order: ";
    for(int i=0;i<order.size();i++){
        cout<<order[i];
        if(i!=order.size()-1)cout<< "->";
    }
    cout<<endl;
}
#endif