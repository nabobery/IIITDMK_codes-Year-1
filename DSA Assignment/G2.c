#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct AdjListNode{
    int dest;
    struct AdjListNode* next;
};
 
struct AdjList{
    struct AdjListNode *head;
};
 
struct Graph{
    int V;
    struct AdjList* array;
};

struct Node{
	int data;
	struct Node *next;
};

struct Queue{
    struct Node *front;
    struct Node *rear;
};

struct Queue *CreateQueue() {
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    if (q == NULL)
        return NULL;
    q->front = q->rear = NULL;
    return q;
};

void Enqueue(struct Queue *q, int data){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    if (q->rear != NULL)
        q->rear->next = newnode;
    q->rear = newnode;
    if (q->front ==  NULL)
        q->rear = q->front;    
}

int Dequeue(struct Queue *q){
    int data;
    struct Node *temp = NULL;
    if (q->front =  NULL)
        return 0;
    else{
        temp = q->front;
        data = q->front->data;
        q->front = q->front->next;
        free(temp);    
    }
    return data;    
}

struct AdjListNode* newAdjListNode(int dest){
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
 
struct Graph* createGraph(int V){
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList)); 
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 
// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest){
    // Add an edge from src to dest.  A new node is
    // added to the adjacency list of src.  The node
    // is added at the beginning
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
 
    // Since graph is undirected, add an edge from
    // dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
 
// A utility function to print the adjacency list
// representation of graph
void printGraph(struct Graph* graph){
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

bool BFS(struct Graph* graph, int s, int dest, int v, int pred[], int dist[]){
    struct Queue *Q = CreateQueue();
    bool visited[v];
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
    visited[s] = true;
    dist[s] = 0;
    Enqueue(Q,s); // Enqueue or Dequeue problem
    while(Q->front != NULL){
        int u = Q->front->data;
        Dequeue(Q);
        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl != NULL){
            if (visited[pCrawl->dest] == false) {
                visited[pCrawl->dest] = true;
                dist[pCrawl->dest] = dist[u] + 1;
                pred[pCrawl->dest] = u;
                Enqueue(Q,pCrawl->dest);
                if (pCrawl->dest == dest)
                    return true;      
            }
            printf("%d ", pCrawl->dest);
            pCrawl = pCrawl->next;  
        }
        printf("\n");
    }
    return false;
}

void printshortestpath(struct Graph* graph, int s, int dest, int v){
    int pred[v], dist[v];
    if (BFS(graph, s, dest, v, pred, dist) == false) {
        printf("Source and Destination not connected \n");
        return;
    }
    // int path[6];
    struct Queue *path = CreateQueue();
    int crawl = dest;
    Enqueue(path, crawl);
    while (pred[crawl] != -1) {
        Enqueue(path, pred[crawl]);
        crawl = pred[crawl];
    }
    printf("The shortest path is \n");
    while(path->front != NULL){
        int data = Dequeue(path);
        printf("%d ", data);
    }
}

int main(){
    // create the graph given in above fugure
    int V = 6;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 1, 5);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 4);
 
    // print the adjacency list representation of the above graph
    printGraph(graph);
    printshortestpath(graph,0,5,6);
    return 0;
}






