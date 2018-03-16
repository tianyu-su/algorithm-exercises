#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;


char mat[31][31][31];
bool vis[31][31][31];
int dir[6][3]={
    {1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}
};
int L,R,C;

struct Node{
    int x,y,z,step;
    Node(int xx,int yy,int zz,int ss){
        x=xx;
        y=yy;
        z=zz;
        step=ss;
    }
};

bool isMap(int x,int y,int z){
    return (x>=0 && x<R && y>=0 && y<C && z>=0 && z<L);
}

int bfs(Node node){
    memset(vis,false,sizeof(vis));
    queue<Node> q;
    vis[node.z][node.x][node.y]=true;
    q.push(node);
    while(!q.empty()){
        node = q.front(); q.pop();

        //exit
        if(mat[node.z][node.x][node.y]=='E')
            return node.step;

        for(int i=0;i<6;i++){
            int nx=node.x+dir[i][0];
            int ny=node.y+dir[i][1];
            int nz=node.z+dir[i][2];
            int nstep=node.step+1;
            if(isMap(nx,ny,nz) && !vis[nz][nx][ny] && mat[nz][nx][ny]!='#'){
                vis[nz][nx][ny]=true;
                q.push(Node(nx,ny,nz,nstep));
            }
        }
    }
    return -1;
}

int main(){
    int start_x,start_y,start_z;
    int end_x,end_y,end_z;
    while(1){
        scanf("%d%d%d",&L,&R,&C);
        bool start_flag=false;
        if(!L) break;
        //input data
        for(int i=0;i<L;i++){
            for(int j=0;j<R;j++){
               scanf("%s",mat[i][j]);
               for(int k=0;!start_flag && k<C;k++){
                    if(mat[i][j][k]=='S'){
                        start_x=j;start_y=k;start_z=i;
                        start_flag=true;break;
                    }
//                    if(mat[i][j][k]=='E'){
//                        end_x=j;end_y=k;end_z=i;
//                    }
               }
            }
        }

        //printf("起始点:(%d,%d,%d)\n",start_x,start_y,start_z);
        //printf("终止点:(%d,%d,%d)\n",end_x,end_y,end_z);

        int ans=bfs(Node(start_x,start_y,start_z,0));
        if(ans==-1)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n",ans);
    }
    return 0;
}
