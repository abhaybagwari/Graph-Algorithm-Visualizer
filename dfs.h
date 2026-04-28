#ifndef DFS_H
#define DFS_H
#include"graph.h"
void printstack(stack<int>s){
    cout<<"Stack: ";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
void dfs(Graph &g,int start){
    vector<bool>visited(g.n+1,false);
    stack<int>s;
    vector<int>order;
    int step=1;
    s.push(start);
    cout<<"\n--DFS Traversal--\n";
    while(!s.empty()){
        cout<<"Step "<<step++<<endl;
        printstack(s);
        int node=s.top();
        s.pop();
        if(visited[node]) continue;

        visited[node]=true;
        cout<<"Visit: "<<node<<endl;
        order.push_back(node);
        for(auto it=g.adj[node].rbegin();it!=g.adj[node].rend();it++){
            if(!visited[it->first]){
                s.push(it->first);
                cout<<"Push: "<<it->first<<endl;
            }
        }
        cout<<endl;
    }
    cout<<"final DFS Order: ";
    for(int i=0;i<order.size();i++){
        cout<<order[i];
        if(i!=order.size()-1) cout<<" -> ";
    }
    cout<<endl;
}

#endif