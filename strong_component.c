//19mcmt04 Biplab Barman
//plese see that there are four dfs related functions 2 for Graph(adjancy matrix) and another 2 for 
//Graph Transpose calculating component and printing in DFS_VISIT_Transpose and DFS_T functions../
//please type-> ./a.out input_test.txt output_strong.txt to run and check in file. 
#include<stdio.h>

int visited[7],time=0,nov,noe,count=0;
FILE *r,*w;
void DFS(int,int[][nov],int[],int[],int[]);   
void DFS_T(int,int[][nov],int[],int[],int[]); 
void DFS_VISIT(int,int[][nov],int,int[],int[],int[]); 

void DFS_VISIT_Transpose(int,int[][nov],int,int[],int[],int[]); 
int max_finish(int[]);
int main(int argc,char *argv[])
{
    int nov,noe;
    
    r = fopen(argv[1],"r");
    w = fopen(argv[2],"w");
    //printf("Enter number of vertices:");
    fscanf(r,"%d",&nov);
    fscanf(r,"%d",&noe);
    
    //read the adjecency matrix
    //printf("\nEnter adjecency matrix of the graph:");
    int left,right;
    int adjMat[nov][nov],parent[nov],arrival[nov],finish[nov];
    for (int i = 0; i < nov; i++)
    {
        visited[i]=0;
        parent[i]=-1;
    }
    
    for (int i = 0; i < nov; i++)
    {
        for (int j = 0; j < nov; j++)
        {
            adjMat[i][j]=0;
        }
        
    }    
    for(int i = 0 ; i < noe; i++)
    {
        fscanf(r,"%d",&left);
        fscanf(r,"%d",&right);
        adjMat[left-1][right-1]=1;
        
    }
    
    //visited is initialized to zero
    for(int i=0;i<nov;i++)
        visited[i]=0;
    //printf("%d ",nov);
    int Transpose[nov][nov];
    for(int i=0;i<nov;i++){
        for(int j=0;j<nov;j++){
            Transpose[i][j]=adjMat[j][i];//transpose
        }
    }
    
    DFS(nov,adjMat,arrival,finish,parent);
    //time=0;
    count=0;
    DFS_T(nov,Transpose,arrival,finish,parent);
    fclose(r);
    return 0;
}

void DFS_T(int nov,int Transpose[][nov],int arrival[],int finish[],int parent[])
{
       time=0;
       for (int i = 0; i < nov; i++)
       {
           visited[i]=0;
       }
       int vertex=max_finish(finish);
       //printf("1.%d\n",vertex);
       for(int j=0;j<nov;j++){
            if(!visited[j]){count++;
            DFS_VISIT_Transpose(nov,Transpose,j,arrival,finish,parent);
            fprintf(w,"\n");
       }
       }
       for(int j=0;j<nov;j++);
            fprintf(w,"Total component=%d",count);
}

     
void DFS(int nov,int G[][nov],int arrival[],int finish[],int parent[])
{
       int j;
       
       for(j=0;j<nov;j++){
            if(!visited[j])
            DFS_VISIT(nov,G,j,arrival,finish,parent);
       }
       for(j=0;j<nov;j++);
            //printf("finish[%d] = %d parent[%d]= %d\n",j,finish[j],j,parent[j]);
}
void DFS_VISIT(int nov,int G[nov][nov],int j,int arrival[],int finish[],int parent[])
{
    //printf("%d ",j+1);
    time=time+1;
    arrival[j]=time;
    visited[j]=1;
    //printf("j1= %d",nov);
    for(int i=0;i<nov;i++)
    {
       if(G[j][i]==1&&!visited[i]){
        parent[i]=j;
	//printf("j = %d",nov);
       // printf("\n->%d",j+1);
       DFS_VISIT(nov,G,i,arrival,finish,parent);
        
       
       }
    }
    
    finish[j]=++time;
    
    //printf("\n");
}
void DFS_VISIT_Transpose(int nov,int G[nov][nov],int j,int arrival[],int finish[],int parent[])
{
    fprintf(w,"%d ",j+1);
    time=time+1;
    arrival[j]=time;
    visited[j]=1;
    //printf("j1= %d",nov);
    for(int i=0;i<nov;i++)
    {
       if(G[j][i]==1&&!visited[i]){
        parent[i]=j;
	//printf("j = %d",nov);
       // printf("\n->%d",j+1);
       DFS_VISIT_Transpose(nov,G,i,arrival,finish,parent);
        
       
       }
    }
    
    finish[j]=++time;
    
    //printf("\n");
}

int max_finish(int finish[]){
    int k = 0;
    int max = finish[k];

for (int i = 0; i < nov; ++i)
{
    if (finish[i] > max)
    {
        max = (int)finish[i];
        k = i;
    }
}
return k;

}