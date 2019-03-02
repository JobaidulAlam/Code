#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int matrix[MAX][MAX];

int main()
{
    int node, edge, u, v;

    while(cin>>node>>edge){
        if(!node && !edge){
            break;
        }

        memset(matrix, 0, sizeof(matrix));      //initializing matrix with 0

        for(int i = 0; i < edge; i++){
            cin>>u>>v;
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }

        //Task - 2
        while(cin>>u>>v){
            if(!u && !v){
                break;
            }

            (matrix[u][v]) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
        }

        //Task - 3
        while(cin>>u){
            if(!u)  break;
            int cnt = 0;
            for(int i= 1; i <= node; i++){
                if(matrix[u][i] == 1){
                    cout<<i<<" ";
                    cnt++;
                }
            }
            cout<<": "<<cnt<<endl;
        }

        //Task - 4
        while(cin>>u>>v){
            if(!u && !v)
                break;
            bool flag = false;
            for(int i = 1; i <= node; i++){
                if(i != v){
                    if(matrix[u][i] && matrix [i][v]){
                        flag = true;
                        break;
                    }
                }
            }

            (flag) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
        }

        //Task - 5
        int cnt = 0;
        for(int i = 1; i <= node; i++){
            for(int j = i + 1; j <= node; j++){
                for(int k = 1; k <= node; k++){
                    if(k != j){
                        if(matrix[i][k] && matrix[k][j]){
                            cnt++;
                            break;
                        }
                    }
                }
            }
        }

        (cnt == (node * (node - 1)) / 2) ? cout<<"YES"<<endl : cout<<"NO"<<endl;

    }

    return 0;
}
