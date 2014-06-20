#include <stdio.h>
#include <string.h>
#define len 100

typedef struct node{
    int x,y,count;
}ore;

ore q[len*len];
char s1[3],s2[3];
char g[len][len];
bool vis[len][len];
int sx,sy,ex,ey,front,rear,n;
//int der[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
int der[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
//(sx,sy),(ex,ey)分别为起始点位置
//front和rear分别为队列首地址和队尾地址
//der为knight跳的方向

void bfs(int r,int c){ //用队列实现bfs
    int nx,ny,i;
    front=0; rear=1;
    q[front].x=r; //首地址元素进入列队
    q[front].y=c;
    vis[r][c]=true;

    for(;front<rear;front++){
        for(i=0;i<4;i++){
            nx=q[front].x+der[i][0];
            ny=q[front].y+der[i][1];
            if(nx<0||nx>=n||ny<0||ny>=n||vis[nx][ny]) //边界控制
                continue;
            vis[nx][ny]=true;
            q[rear].x=nx;
            q[rear].y=ny;
            q[rear].count=q[front].count+1;
            //子节点的计数变量为父节点加1
            if(g[nx][ny]=='3')return ;
            rear++;
        }
    }
}

int main(){
    freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF){
        //printf("%d\n",n);
        memset(g,0,sizeof(g));
        for(int i=0;i<n;i++)
            scanf("%s",g[i]);

        int max=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(g[i][j]=='1'){
                    memset(vis,0,sizeof(vis));
                    memset(q,0,sizeof(q));
                    bfs(i,j);
                    if(max<q[rear].count)
                        max=q[rear].count;
                }
        printf("%d\n",max);
    }
    return 0;
}
