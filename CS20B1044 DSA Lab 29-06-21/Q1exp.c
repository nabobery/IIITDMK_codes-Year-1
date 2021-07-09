/* Question 1 : Take a random connected directed acyclic graph. Store it using Adjacency Matrix as well as
Adjacency list. Implement the Breadth-first search, Depth-first search and Topological sort
using both the storage structures. */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// A structure to represent an adjacency list node
struct AdjListNode{
    int dest;
    struct AdjListNode* next;
};

// A structure to represent an adjacency list 
struct AdjList{
    struct AdjListNode *head;
};

// A linked list structure for the queue and stack in BFS and DFS
struct Node{
	int data;
	struct Node *next;
};

// A structure for queue used in BFS
struct Queue{
    struct Node *front;
    struct Node *rear;
};

// Queue related functions
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

int Dequeue(struct Queue *q){ 
    int data;
    if (q->front ==  NULL)
        return -1;
    struct Node *temp = q->front;
    data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);   
    return data;    
}

/* A structure for stack used in DFS
struct stack{
    struct Node *top;
};

// Stack related functions
void push(struct stack *stack,int data){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = stack->top;
    stack->top = temp;
}

int pop(struct stack *stack){
    int data;
    struct Node *temp;
    temp = stack->top;
    stack->top = stack->top->next;
    data = temp->data;
    free(temp);
    return data;
}*/

/* A structure to represent graph which has number of vertices and an adjacency list array and adj matrix to store 
adjacent vertices of the vertex */
struct Graph{
    int V;
    struct AdjList* array;
    int **adj_matrix;
    bool *visited;
    int *indegree1;
    int *indegree2;
};

struct AdjListNode* newAdjListNode(int dest){
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList)); 
    graph->adj_matrix = malloc(V * sizeof(int *));
    graph->visited = malloc(V * sizeof(bool));
    graph->indegree1 = malloc(V * sizeof(int));
    graph->indegree2 = malloc(V * sizeof(int));
    for (int i = 0; i < V; ++i){
        graph->adj_matrix[i] = malloc(V * sizeof(int)); 
        graph->visited[i] = false;
        graph->indegree1[i] = 0;
        graph->indegree2[i] = 0;
    }
    // For Adjacency List
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    // For Adjacency Matrix    
    for(int u = 0; u < V; ++u){
        for(int v = 0; v < V; ++v){
            graph->adj_matrix[u][v] = 0;
        } 
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest){
    // Adding only one edge from src to dest as it's directed
    // For Adjacency list 
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    // For Adjacency Matrix
    graph->adj_matrix[src][dest] = 1;
    graph->indegree1[dest] += 1;
    graph->indegree2[dest] += 1;
}

void printAdjlist(struct Graph* graph){
    printf("Adjacency list of the given graph is : \n");
    for (int v = 0; v < graph->V; ++v){
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("Adjacency list of vertex %d : ", v);
        while (pCrawl){
            printf(" %d ", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

void printAdjmatrix(struct Graph* graph){
    printf("Adjacency matrix of the given graph :\n");
    for(int u = 0; u < graph->V; ++u){
        for(int v = 0; v < graph->V; ++v){
            printf(" %d ",graph->adj_matrix[u][v]);
        } 
        printf("\n");
    }
}

void BFS_matrix(struct Graph* graph,int s){
    int V = graph->V;
    bool visited[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL; 
    Enqueue(q,s);
    //printf("Nodes Visited :\n");
    while (q->front != NULL){
        s = Dequeue(q);
        printf(" %d ",s);
        visited[s] = true;
        for (int i = 0; i < V; i++){
            if (!visited[i] && graph->adj_matrix[s][i] == 1){
                visited[i] = true;
                Enqueue(q,i);
            }
        }
    }
    printf("\n");
}

void BFS_list(struct Graph* graph, int s){
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    int V = graph->V;
    bool visited[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    visited[s] = true;
    Enqueue(q,s); 
    //printf("Nodes Visited :\n");
    while (q->front != NULL){
        int u = Dequeue(q);
        printf(" %d ",u);
        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl){
            if (visited[pCrawl->dest] == false){
                visited[pCrawl->dest] = true;
                Enqueue(q,pCrawl->dest);
            }
            pCrawl = pCrawl->next;
        }
    }
    printf("\n");   
}

void DFS_matrix(struct Graph* graph,int s){
    int V = graph->V;
    graph->visited[s] = true;
    printf(" %d ", s);
    for (int i = 0; i < V; i++){
        if(!graph->visited[i] && graph->adj_matrix[s][i] == 1)
            DFS_matrix(graph,i);
    }
}

void DFS_list(struct Graph* graph, int s){
    int V = graph->V;
    struct AdjListNode* pCrawl = graph->array[s].head;
    graph->visited[s] = true;
    printf(" %d ", s);
    while (pCrawl){
        int u = pCrawl->dest;
        if (graph->visited[u] == false)
            DFS_list(graph,u);
        pCrawl = pCrawl->next;    
    }
}

void initialize(struct Graph* graph){
    for(int i = 0; i < graph->V; i++){
        graph->visited[i] = false;
    }    
}

void Topology_sort_matrix(struct Graph* graph){
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL; 
    int counter = 0;
    int topologicalorder[graph->V];
    for (int i = 0; i < graph->V; i++){
        if(graph->indegree1[i] == 0)
            Enqueue(q,i); 
    }
    while(q->front != NULL){
        int u = Dequeue(q);
        printf(" %d ", u);
        topologicalorder[u] = ++counter;
        for (int i = 0; i < graph->V; i++){
            if (graph->adj_matrix[u][i] == 1 && --graph->indegree1[i] == 0)
                Enqueue(q,i);
        }
    }
    printf("\n");   
    if (counter != graph->V)
        printf("Graph has a cycle so topology sort not possible\n");
}

void Topology_sort_list(struct Graph* graph){
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL; 
    int counter = 0;
    int topologicalorder[graph->V];
    for (int i = 0; i < graph->V; i++){
        if(graph->indegree2[i] == 0)
            Enqueue(q,i); 
    }
    while(q->front != NULL){
        int u = Dequeue(q);
        printf(" %d ", u);
        topologicalorder[u] = ++counter;
        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl){
            int w = pCrawl->dest;
            if (--graph->indegree2[w] == 0)
                Enqueue(q,pCrawl->dest);
            pCrawl = pCrawl->next;
        }
    }
    printf("\n");
    /*for (int i = 0; i < graph->V; i++)
        printf("Position : %d, Vertex : %d \n", topologicalorder[i], i);*/
    if (counter != graph->V)
        printf("Graph has a cycle so topology sort not possible\n");
}

void deletegraph(struct Graph* graph){
    for (int i = 0; i < graph->V; i++) {
        free(graph->array[i].head);
    }
    for (int i = 0; i < graph->V; i++)
        free(graph->adj_matrix[i]);
    free(graph->adj_matrix);  
    free(graph->visited);
    free(graph->indegree1);
    free(graph->indegree2);  
    free(graph);
}

void main(){
    int V = 5;
    struct Graph* graph = createGraph(V);
    struct Graph* test = createGraph(6);
    addEdge(test, 5, 2);
    addEdge(test, 5, 0);
    addEdge(test, 4, 0);
    addEdge(test, 4, 1);
    addEdge(test, 2, 3);
    addEdge(test, 3, 1);
    //printf("%d\n", V);
    /*addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printAdjlist(graph);
    printAdjmatrix(graph);
    printf("The BFS traversal using adjacency matrix from vertex 0 is \n");
    BFS_matrix(graph,0);
    printf("The BFS traversal using adjacency list from vertex 0 is \n");
    BFS_list(graph,0);
    printf("The DFS traversal using adjacency matrix from vertex 0 is \n");
    DFS_matrix(graph,0);
    initialize(graph);
    printf("\nThe DFS traversal using adjacency list from vertex 0 is \n");
    DFS_list(graph,0);
    printf("\n"); */
    /* Testing Indegree
    for(int i = 0; i < V; i++)
        printf(" %d ", graph->indegree[i]);
    */    
    Topology_sort_matrix(test);
    Topology_sort_list(test);
    deletegraph(graph);
}