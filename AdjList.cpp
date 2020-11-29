//TEST
#include <bits/stdc++.h>
#define MAX 55
using namespace std;

vector<int> graph[MAX];

int main()
{
    int node, edge, u, v;

    while(cin>>node>>edge){
        if(!node && !edge)
            break;
        for(int i = 0; i < edge; i++){
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i = 1; i <= node; i++){
            cout<<i<<" -> ";
            for(int j  = 0; j < graph[i].size(); j++){
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }

        //task -2
        while(cin>>u>>v){
            if(!u && !v)
                break;
            bool flag = false;
            for(int i = 0; i < graph[u].size(); i++){
                if(graph[u][i] == v){
                    flag = true;
                    break;
                }
            }

            (flag) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
        }

        //task - 3;
        while(cin>>u){
            if(!u)
                break;
            for(int i = 0; i < graph[u].size(); i++){
                cout<<graph[u][i]<<" ";
            }

            cout<<": "<<graph[u].size()<<endl;
        }

        //task - 4
        while(cin>>u>>v){
            if(!u && !v)
                break;
            bool flag = false;
            vector<int> temp;
            for(int i = 0; i < graph[u].size(); i++){
                int t = graph[u][i];
                if(t != v){
                    temp.push_back(t);
                }
            }

            for(int i = 0; i < temp.size(); i++){
                for(int j = 0; j < graph[temp[i]].size(); j++){
                    int k = graph[temp[i]][j];
                    if(k == v){
                        flag = true;
                        break;
                    }
                }
            }
            (flag) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
            temp.clear();
        }

         int cnt = 0;

         for(int i = 1; i <= node; i++){
            for(int j = i + 1; j <= node; j++){
                for(int k = 1; k <= node; k++){
                    int c = 0;
                    for(int l = 0; l < graph[k].size(); l++){
                        if(graph[k][l] == i)
                            c++;
                        if(graph[k][l] == j)
                            c++;
                    }
                    if(c == 2){
                        cnt++;
                        break;
                    }
                }
            }
         }

         (cnt == (node * (node - 1)) / 2) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }

    return 0;
}
