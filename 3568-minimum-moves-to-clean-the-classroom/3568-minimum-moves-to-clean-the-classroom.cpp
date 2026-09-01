class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        vector<pair<int,int>> litter;
        int sx, sy;

        unordered_map<int,int> id;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j]=='S'){
                    sx=i;
                    sy=j;
                }else if(classroom[i][j]=='L'){
                    id[i*n+j]=litter.size();
                    litter.push_back({i,j});
                }
            }
        }

        int ALL=(1<<litter.size())-1;

        struct Node{
            int x,y,e,mask,dist;
        };

        queue<Node> q;

        vector<vector<vector<vector<bool>>>> vis(
            m,
            vector<vector<vector<bool>>>(n,
                vector<vector<bool>>(energy+1,
                    vector<bool>(1<<litter.size(),false)))
        );

        vis[sx][sy][energy][0]=true;
        q.push({sx,sy,energy,0,0});

        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};

        while(!q.empty()){
            auto cur=q.front();
            q.pop();

            if(cur.mask==ALL) return cur.dist;

            if(cur.e==0 && classroom[cur.x][cur.y]!='R')
                continue;

            for(int k=0;k<4;k++){
                int nx=cur.x+dx[k];
                int ny=cur.y+dy[k];

                if(nx<0||nx>=m||ny<0||ny>=n) continue;
                if(classroom[nx][ny]=='X') continue;
                if(cur.e==0) continue;

                int ne=cur.e-1;
                int mask=cur.mask;

                if(classroom[nx][ny]=='R')
                    ne=energy;

                if(classroom[nx][ny]=='L'){
                    mask|=1<<id[nx*n+ny];
                }

                if(!vis[nx][ny][ne][mask]){
                    vis[nx][ny][ne][mask]=true;
                    q.push({nx,ny,ne,mask,cur.dist+1});
                }
            }
        }

        return -1;
    }
};