#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;

        int fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }
        }

        if(fresh==0) return 0;

        int time=0;
        int di[4] = {-1,1,0,0}, dj[4] = {0,0,-1,1};
        int nivel = 0;


        while(!q.empty()){

            bool ok=false;
            int sz = q.size();
            //cout << "Nivel atual: " << nivel << endl;

            while(sz--){
                auto [i,j] = q.front();q.pop();


                for(int k=0;k<4;k++){

                    int ni = i + di[k];
                    int nj = j + dj[k];

                    if(ni < 0 || nj < 0 || ni >= grid.size() || nj >= grid[0].size()) 
                        continue;
                    
                    if(grid[ni][nj]==1){
                        grid[ni][nj]=2;
                        q.push({ni,nj});
                        fresh--;
                        ok = true;
                    }

                    // if(!vis[ni][nj]){
                    //     vis[ni][nj] = true;
                    //     q.push({ni,nj});
                    // }

                }
            }

            if(ok) time++;
            // nivel++;

        }

        if(fresh>0) return -1;
        return time;
    }
};