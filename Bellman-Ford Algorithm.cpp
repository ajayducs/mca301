#include<iostream>
using namespace std;

class Graph {
    
    struct Edge {
        
        int source;
        int destination;
        int weight;
    };
    
    int V;
    int E;
    
public:
    
    Edge *edge;
    
    static int index;
    
    Graph(int V, int E) {
        
        this->V = V;
        this->E = E;
        edge = new Edge[E];
    }
    
    void addEdge(int source, int destination, int weight)
    { if(index < E)
    {   edge[++index].source = source;
        edge[index].destination = destination;
        edge[index].weight = weight; }
    }
    
    int getV()
    { return V; }
    
    int getE()
    { return E; }
    
};

int Graph::index = -1;


void printMinDist(int source_distance[], int size) {
    
    for(int i = 0; i < size; i++)
    { cout << source_distance[i] << endl; }
    
    cout << endl;
}


void BellmanFord(Graph *graph, int src = 0) {
    
    int V = graph->getV();
    int E = graph->getE();
    
    int source_distance[V];
    
    for(int i = 0; i < V; i++)
    { source_distance[i] = INT_MAX; }
    
    source_distance[src] = 0;
    
    // Iterates through all the edges and Relaxes them. This process is done |V| - 1 times
    for(int i = 0; i < V - 1; i++)
    {
        for(int j = 0; j < E; j++)
        {
            int source = graph->edge[j].source;
            int dest = graph->edge[j].destination;
            int weight = graph->edge[j].weight;
            
            //Calculates and compares (<) Relaxation value. Ignores if the source value is Infinity/INT_MAX
            if(source_distance[source] != INT_MAX && source_distance[source] + weight < source_distance[dest])
            { source_distance[dest] = source_distance[source] + weight; }
        }
    }
    
    printMinDist(source_distance, V);
    
}



int main() {
    
    int V = 7, E = 10;
    Graph *graph = new Graph(V, E);
    
    // addEdge(source, destination, weight)
    
    graph->addEdge(0, 1, 6);
    graph->addEdge(0, 2, 5);
    graph->addEdge(0, 3, 5);
    
    graph->addEdge(1, 4, -1);
    
    graph->addEdge(2, 1, -2);
    graph->addEdge(2, 4, 1);
    
    graph->addEdge(3, 2, -2);
    graph->addEdge(3, 5, -1);
    
    graph->addEdge(4, 6, 3);
    
    graph->addEdge(5, 6, 3);
    
    BellmanFord(graph);
    
    return 0;
}
