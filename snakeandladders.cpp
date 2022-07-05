#include <bits/stdc++.h>
using namespace std;
int snakesAndLadders(vector<vector<int>>& board) {
          int n=board.size();
        queue<pair<int,int>>q;
        q.push(make_pair(n-1,0));
        int distance[n][n];
        int visited[n][n];
        int used[n][n];
        for(int i=0;i<n;i++)for(int j=0;j<n;j++){visited[i][j]=0;distance[i][j]=100000000;used[i][j]=0;}
        int dv=1;
        distance[n-1][0]=0;
        while(!q.empty())
        {
            pair<int,int>vertex=q.front();
            q.pop();
            int u=vertex.first;
            int v=vertex.second;
            if(!visited[u][v]){
            visited[u][v]=1;
            if(!used[u][v]&&board[u][v]!=-1)
            {
                
                int i1=board[u][v]/n;
                int i2=board[u][v]%n;
                if(i2==0){i1--;i2=n;}
                if(i1%2)i2=n-i2+1;
                i1=n-i1-1;
                i2--;
                q.push(make_pair(i1,i2));
                used[i1][i2]=1;
                distance[i1][i2]=min(distance[i1][i2],distance[u][v]+1);               
            }
            else
            {
            for(int i=1;i<=6;i++)
            {
                if(v+i*dv>=n||v+i*dv<0){
                    if(u==0)break;
                    if(!visited[u-1][v]){q.push(make_pair(u-1,v));used[u-1][v]=0;
                    distance[u-1][v]=min(distance[u-1][v],distance[u][v]+1);}
                    dv=-dv;                    
                }
                else {
                    if(!visited[u][v+i*dv]){q.push(make_pair(u,v+i*dv));used[u][v+i*dv]=0;
                    distance[u][v+i*dv]=min(distance[u][v+i*dv],distance[u][v]+1);}
                }
            }
            }
            } 
            
        }
        if(n%2)return distance[0][n-1];
        else return distance[0][0];     
}
int main()
{
  vector<vector<int>>board;
  int n;
  cin>>n;//size of board
  for(int i=0;i<n;i++)
  {
    vector<int>a;
    for(int j=0;j<n;j++)
    {
      int x;
      cin>>x; //-1 if there is no snake or ladder otherwise respective number where to the cell where ladder or snake takes us to.
      a.push_back(x);
    } 
    board.push_back(a);

  }
  int ans=snakesAndLadders(board);//minimum number of moves to reach destination square using dice of 6 faces 
  cout<<ans<<endl;
}
