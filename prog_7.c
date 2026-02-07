//7. Given a weighted graph, implement Dijkstra’s algorithm to find the shortest path from a source node to all other nodes.
#include<stdio.h>
#include<limits.h>

#define MAX 10
#define INF 999

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];
int n;

void create_graph(){
    int i,j,edges,u,v,w;
    
    printf("enter no of vertices: ");
    scanf("%d",&n);
    
    //initialize with infinity
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            graph[i][j]=(i==j)?0:INF;
    
    printf("enter no of edges: ");
    scanf("%d",&edges);
    
    for(i=0;i<edges;i++){
        printf("enter edge (u v weight): ");
        scanf("%d %d %d",&u,&v,&w);
        graph[u][v]=w;
        graph[v][u]=w; //undirected graph
    }
}

int find_min_dist(){
    int min=INF,min_index,i;
    
    for(i=0;i<n;i++){
        if(!visited[i] && dist[i]<min){
            min=dist[i];
            min_index=i;
        }
    }
    return min_index;
}

void dijkstra(int src){
    int i,j,u;
    
    //initialize distances
    for(i=0;i<n;i++){
        dist[i]=INF;
        visited[i]=0;
    }
    
    dist[src]=0;
    
    for(i=0;i<n-1;i++){
        u=find_min_dist();
        visited[u]=1;
        
        for(j=0;j<n;j++){
            if(!visited[j] && graph[u][j]!=INF && 
               dist[u]!=INF && dist[u]+graph[u][j]<dist[j]){
                dist[j]=dist[u]+graph[u][j];
            }
        }
    }
}

void print_solution(int src){
    int i;
    printf("\nshortest distances from vertex %d:\n",src);
    for(i=0;i<n;i++){
        if(dist[i]==INF)
            printf("vertex %d: unreachable\n",i);
        else
            printf("vertex %d: %d\n",i,dist[i]);
    }
}

int main(){
    int src;
    
    create_graph();
    
    printf("\nenter source vertex: ");
    scanf("%d",&src);
    
    dijkstra(src);
    print_solution(src);
    
    return 0;
}