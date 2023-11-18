/**
 * Group ID - 46
 * Member 1 Name - Darshan Abhay Kumar 
 * Member 1 BITS ID - 
 * Member 2 Name - Debjit Kar
 * Member 2 BITS ID - 2020A7PS0970P
 * Member 3 Name - Kshitij Tandon
 * Member 3 BITS ID - 
*/

// ---------------------------DO NOT MODIFY (Begin)------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Graph {
    int n; // Size of the graph
    int** adj; // Adjacency matrix
    char** station_names; // Array of station names
} Graph;

/**
 * This function has been pre-filled. It reads the input testcase 
 * and creates the Graph structure from it.
*/
Graph* create_graph(char input_file_path[]) {
    FILE* f = fopen(input_file_path, "r");
    Graph* g = (Graph*)malloc(sizeof(Graph));
    // Size of graph
    fscanf(f, "%d", &(g->n));
    // Names of stations
    g->station_names = (char**)malloc(g->n * sizeof(char*));
    for(int i = 0; i < g->n; i++) {
        g->station_names[i] = (char*)malloc(100 * sizeof(char));
        fscanf(f, "%s", g->station_names[i]);
    }
    // Adjacency matrix
    g->adj = (int**)malloc(g->n * sizeof(int*));
    for(int i = 0; i < g->n; i++) {
        g->adj[i] = calloc(g->n, sizeof(int));
    }
    int edges;
    fscanf(f, "%d", &edges);
    for(int i = 0; i < edges; i++) {
        int x, y;
        fscanf(f, "%d%d", &x, &y);
        g->adj[x][y] = 1;
        g->adj[y][x] = 1;
    }
    fclose(f);
    return g;
}
// ---------------------------DO NOT MODIFY (End)------------------------------

/**
 * Q.1 
 * Return the number of junctions.
*/
int find_junctions(Graph* g) {
    int** matrix = g->adj;
    int count = 0;
    for(int i = 0; i < g->n; i++){
        int neighbours = 0;
        for(int j = 0; j < g->n; j++){
            if(matrix[i][j]) neighbours++;
        }
        if(neighbours >= 4) count++;
    }
    return count;
}

/**
 * Q.2
 * Return true if the tour specified in the question is possible for this 
 * graph, else return false.
 * Parameter SAME_STATION - If it is true, then question 2(a) must be solved. 
 * If false, then question 2(b) must be solved.
*/
bool sheldons_tour(Graph* g, bool SAME_STATION) {
    int** matrix = g->adj;
    int odd_count = 0;
    for(int i = 0; i < g->n; i++){
        int vertex_edges = 0;
        for(int j = 0; j < g->n; j++){
            if(matrix[i][j]) vertex_edges++;
        }
        if(vertex_edges%2) odd_count++;
    }
    bool ans = false;
    if(SAME_STATION && (odd_count == 0)) ans = true;
    if(!SAME_STATION && (odd_count == 2)) ans = true;
    return ans;
}

/**
 * Q.3
 * Return closure, an n * n matrix filled with 0s and 1s as required. 
*/
int** warshall(Graph* g) {
    // Do not modify or delete pre-filled code!
    int** closure = (int**)malloc(g->n * sizeof(int*));
    for(int i = 0; i < g->n; i++) {
        closure[i] = calloc(g->n, sizeof(int));
    }

    // Code goes here
    
    return closure; // Do not modify
}

/**
 * Q.3
 * Return the number of impossible pairs.
*/
int find_impossible_pairs(Graph* g) {
    int** closure = warshall(g); // Do not modify
    
}

/**
 * Q.4
 * Return the number of vital train tracks.
*/
int find_vital_train_tracks(Graph* g) {
    
}

/**
 * Q.5
 * Return upgrades, an array of size n.
 * upgrades[i] should be 0 if railway station i gets a restaurant
 * upgrades[i] should be 1 if railway station i gets a maintenance depot
 * If it is not possible to upgrade, then return "-1" in the entire array
*/
int* upgrade_railway_stations(Graph* g) {
    int* upgrades = calloc(g->n, sizeof(int)); // Do not modify
    
    // Code goes here

    return upgrades; // Do not modify
}

/**
 * Q.6
 * Return distance between X and Y
 * city_x is the index of X, city_y is the index of Y
*/
int distance(Graph* g, int city_x, int city_y) {
    
}

/**
 * Q.7
 * Return the index of any one possible railway capital in the network
*/
int railway_capital(Graph* g) {
    
}

/**
 * Helper function for Q.8
*/
bool maharaja_express_tour(Graph* g, int source, int current_city, int previous_city, int* visited) {
    
}

/**
 * Q.8 
 * Return true if it is possible to have a Maharaja Express tour 
 * starting from source city, else return false. 
*/
bool maharaja_express(Graph* g, int source) {
    int* visited = (int*)malloc(g->n * sizeof(int)); 
    for(int i = 0; i < g->n; i++) {
        visited[i] = 0;
    }
    // Hint: Call the helper function and pass the visited array created here.
}

int main(int argc, char *argv[]) {
    // char input_file_path[100] = argv[1]; // Can be modified
    Graph* g = create_graph(argv[1]); // Do not modify
    
    // Code goes here
    // a<i> -> answer of ith question 
    int a1 = find_junctions(g);
    printf("Q1: Number of junctions = %d \n", a1);

    bool a21 = sheldons_tour(g, true);
    bool a22 = sheldons_tour(g, false);

    printf("Q2: Sheldon's tour (ending in same city as start) = %s \n", a21? "Possible":"Impossible");
    printf("Q2: Sheldon's tour (ending in different city as start) = %s \n", a22? "Possible":"Impossible");

    return 0;
}