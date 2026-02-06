//5. How can we implement the undirected graph using adjacency matrix? Write a function that implement the BFS and DFS technique to traverse through the graph. Demonstrate the use of your program with example graph.

#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int n;

void create_graph(){
    int i,j,edges,u,v;
    printf("enter no of vertices: ");
    scanf("%d",&n);
    
    //initialize matrix
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            adj[i][j]=0;
    
    printf("enter no of edges: ");
    scanf("%d",&edges);
    
    for(i=0;i<edges;i++){
        printf("enter edge (u v): ");
        scanf("%d %d",&u,&v);
        adj[u][v]=1;
        adj[v][u]=1; //undirected graph
    }
}

void display_matrix(){
    int i,j;
    printf("\nadjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%d ",adj[i][j]);
        printf("\n");
    }
}

void dfs(int start){
    int i;
    visited[start]=1;
    printf("%d ",start);
    
    for(i=0;i<n;i++){
        if(adj[start][i]==1 && visited[i]==0)
            dfs(i);
    }
}

void bfs(int start){
    int queue[MAX],front=0,rear=0;
    int i,current;
    
    for(i=0;i<n;i++)
        visited[i]=0;
    
    visited[start]=1;
    queue[rear++]=start;
    
    while(front<rear){
        current=queue[front++];
        printf("%d ",current);
        
        for(i=0;i<n;i++){
            if(adj[current][i]==1 && visited[i]==0){
                visited[i]=1;
                queue[rear++]=i;
            }
        }
    }
}

int main(){
    int choice,start,i;
    
    create_graph();
    display_matrix();
    
    while(1){
        printf("\n1.DFS 2.BFS 3.exit\n");
        printf("choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                printf("enter starting vertex for DFS: ");
                scanf("%d",&start);
                for(i=0;i<n;i++)
                    visited[i]=0;
                printf("DFS traversal: ");
                dfs(start);
                printf("\n");
                break;
            case 2:
                printf("enter starting vertex for BFS: ");
                scanf("%d",&start);
                printf("BFS traversal: ");
                bfs(start);
                printf("\n");
                break;
            case 3:
                exit(0);
            default:
                printf("invalid choice\n");
        }
    }
    return 0;
}