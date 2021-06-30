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

/*struct stack{
    struct Node *top;
};*/

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
    if (q->rear == NULL){
        q->rear = q->front = newnode;
        return;    
    }
    q->rear->next = newnode;
    q->rear = newnode;
}    

void Dequeue(struct Queue *q){ 
    if (q->front ==  NULL)
        return;
    struct Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);       
}

/*void push(struct stack *stack, int data){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = stack->top;
    stack->top = temp;
}

void pop(struct stack *stack){
    struct Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    /*if (stack->top == NULL)
        return;
    else {
        struct Node *temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }  
}

void *reversequeue(struct Queue *q){
    struct stack *stack =  (struct stack*)malloc(sizeof(struct stack));
    int data;
    while(q->front != NULL){
        data = q->front->data;
        push(stack, data);
        Dequeue(q);
    }
    while (stack->top != NULL){
        data = stack->top->data;
        Enqueue(q,data);
        pop(stack);
    }
    return q;
}*/

void reverseQueue(struct Queue *q){
    // Base case
    if (q->front ==  NULL)
        return;
 
    // Dequeue current item (from front) 
    int data = q->front->data;
    Dequeue(q);
 
    // Reverse remaining queue 
    reverseQueue(q);
 
    // Enqueue current item (to rear) 
    Enqueue(q,data);
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
    int visited[v];
    for (int i = 0; i < v; i++) {
        visited[i] = 0;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
    visited[s] = true;
    dist[s] = 0;
    Enqueue(Q,s);
    /* some test case
    for (int i = 0; i < v; i++){
        printf("%d ", dist[i]);
    }*/         
    while(Q->front != NULL){
        int u = Q->front->data;
        // printf("%d ",u); test
        Dequeue(Q);
        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl){
            if (visited[pCrawl->dest] == 0) {
                visited[pCrawl->dest] = 1;
                dist[pCrawl->dest] = dist[u] + 1;
                pred[pCrawl->dest] = u;
                Enqueue(Q,pCrawl->dest);
                if (pCrawl->dest == dest)
                    return true;      
            }
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
    // reversequeue(path);
    reverseQueue(path);
    printf("The shortest path is \n");
    struct Node *ptr = path->front;
    while(ptr != NULL){
        int data = path->front->data;
        Dequeue(path);
        printf("%d ", data);
        ptr = ptr->next;
    }
}

void deletegraph(struct Graph* graph){
    for (int i = 0; i < graph->V; i++) {
        free(graph->array[i].head);
    }
    free(graph);
}

bool range(int v, int start, int end){
    if (start >= 0 && start < v && end >= 0 && end < v)
        return true;
    else
        return false;    
}

int main(){
    // create the graph given in above fugure
    int V = 8;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 7);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 6);
    addEdge(graph, 4, 7);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 7);
 
    // print the adjacency list representation of the above graph
    //printGraph(graph);
    //printshortestpath(graph,2,6,8);
    int choice, v, src, dst, source, destination;
    do {
        printf("Graph based on user input : \n 1) Create Graph \n 2) Add Edge for the graph \n 3) Display Adjacency List \n 4) Shortest Path \n 0) Exit");
        printf("\nEnter any choice between 0-3 : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter number of the vertices of the graph you want to create \n");
                scanf("%d", &v);
                 struct Graph* user_graph = createGraph(v);
                break;
            case 2:
                printf("Enter the source and destination of the edge you want to create (Indices start from 0 to %d) \n", v - 1);
                scanf("%d %d", &src, &dst);
                if (!range(v,src,dst))
                    printf("Either the source or destination not in between 0 and %d\n", v - 1);
                else
                    addEdge(user_graph,src,dst);
                break;
            case 3:
                printf("The Adjacency list of the above graph is :\n");
                printGraph(user_graph);
                break;   
            case 4:
                printf("Enter the source and destination you want to find shortest path from \n");
                scanf("%d %d", &source, &destination);
                printshortestpath(user_graph,source,destination,v);
                printf("\n");
                break;     
        }
    } while (choice != 0);
    return 0;
}






