#include"graph.h"
#include"bfs.h"
#include"dfs.h"
#include"dijkstra.h"
#include"prim.h"
int main(){
     cout<<"****--GRPAH TRAVESAL TOOLKIT--****"<<endl;
     int n,m;
     cout<<"Enter nodes and edges:\n";
     cin>>n>>m;
     Graph g(n);
     cout<<"Enter edges(u v w):\n";
     for(int i=0;i<m;i++){
          int u,v,w;
          cin>>u>>v>>w;
          g.addedge(u,v,w);
     }
     g.showadjlist();
     g.showmatrix();
     while(1){
          cout<<"\n1 BFS\n2 DFS\n3 Dijkstra\n4 Prim\n5 Exit "<<endl;
          int ch;
          cin>>ch;
          if(ch==1){
               int s;
               cout<<"Enter start node: ";
               cin>>s;
               bfs(g,s);
          }
          else if(ch==2){
               int s;
               cout<<"Enter start node: ";
               cin>>s;
               dfs(g,s);
          }
          else if(ch==3){
               int s;
               cout<<"Enter source node: ";
               cin>>s;
               dijkstra(g,s);
          }
          else if(ch==4){

               prim(g);
          }
          else if(ch==5){
               break;
          }
          else {
               cout<<"Invalid choice\n";
          }
     }
}