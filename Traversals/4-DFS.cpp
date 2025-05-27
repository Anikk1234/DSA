#include <bits/stdc++.h>
using namespace std;

        void addedge(vector<vector<int>> &adj,int u, int v, int dir) {
            adj[u].push_back(v); 
            if (dir == 0) {
                adj[v].push_back(u); 
            }
        }
    
        void Display(vector<vector<int>>&adj,int vertices) {
            for (int i = 0; i <vertices; i++) {
                cout << i << " -> ";
                for (int ele : adj[i]) {
                    cout << ele << " ";
                }
                cout << endl;
            }
        }

        void Dfs(vector<vector<int>>& adj,int start){
       stack<int>st;
       vector<bool>visit(adj.size(),false);
         st.push(start);
         visit[start]=true;
         while (!st.empty())
         {
           int p=st.top();
           st.pop();
           cout<<p<<" ";
           for(int x: adj[p]){
            if(!visit[x]){
                st.push(x);
                visit[x]=true;
            }

           }
         }
         

        }
    


int main() {
    vector<vector<int>> adj;

    int n, u, v, m, dir,start;
    cout << "Enter number of vertices: ";
    cin >> n;
    adj.resize(n);


    cout << "Enter the number of edges: ";
    cin >> m;

     
    cout << "Notation for directed graph = 1 or undirected graph = 0: ";
    cin >> dir;


    cout << "Now enter starting and ending vertex:" << endl;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        addedge(adj,u,v, dir);
    }
    cout<<"Graph:"<<endl;
    Display(adj,n); 
    cout<<"Enter starting point for DFS:";
    cin>>start;
    
    if (start < 0 || start >= n) {
        cout << "Invalid starting vertex!" << endl;
        return 1;
    }
    cout<<"DFS:"<<endl;
    Dfs(adj,start);

    return 0;
}
