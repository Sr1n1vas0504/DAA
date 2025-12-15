//ch.sc.u4cse24146
// bfs 
#include<stdio.h>
#include<stdlib.h>
int v = 5
int queue[v];
front = rear = -1;
struct node{
	int ver;
	struct node* next;
};

struct Graph{
	struct node* list[10];
};

struct node* createNode(int ver){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->next = NULL;
	newnode->ver = ver;
	return newnode;
}

void enqueue(int ver){
	if(front == -1 && rear==-1){
		front = 0;
		rear = 0;
	}
	queue[rear++]=ver;
}

int dequeue(){
	if(front == rear){
		front = -1;
		rear = -1;
	}
	return queue[front++];
}

int isempty(){
	if(front == -1 && rear==-1){
		return 1;
	}
}

void addEdge(struct Graph* graph,int ver,int des){
	struct node* Newnode1 = createNode(des);
	Newnode1->next = graph->list[ver];
	graph->list[ver]=Newnode1;
	struct node* Newnode2 = createNode(ver);
	Newnode2->next = graph->list[des];
	graph->list[des]=Newnode2;
}

void bfs(struct Graph* graph,int start){
	int visited[v]={0};
	visited[start]=1;
	enqueue(start);
	while(!isempty()){
		int current = dequeue();
		printf("%d",current);
		struct node* temp = graph->list[current];
		while(temp){
			int adj = temp->ver;
			if(!visited[adj]){
				visited[adj]=1;
				enqueue(adj);
			}
			temp=temp->next;
		}
	}
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    bfs(graph, 0);

    return 0;
}


