#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 17576
bool graph[MAX_VERTICES][MAX_VERTICES] = {0};
bool should_visit[MAX_VERTICES] = {0};
long long combinations[MAX_VERTICES] = {0};

int hash(const char *s) {
    return (s[0] - 'a') + (s[1] - 'a') * 26 + (s[2] - 'a') * 26 * 26;
}

void print_node(int hash) {
    char name[4];
    name[0] = (hash % 26) + 'a';
    name[1] = ((hash / 26) % 26) + 'a';
    name[2] = ((hash / (26 * 26)) % 26) + 'a';
    name[3] = '\0';
    printf("%s ", name);
}

void topologicalSort(int current_vertex, int stack[MAX_VERTICES], int* stack_index) {
    should_visit[current_vertex] = 0;

    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph[current_vertex][i] && should_visit[i]) {
            topologicalSort(i, stack, stack_index);
        }
    }

    stack[(*stack_index)++] = current_vertex;
}

int main() {
    FILE *fp = fopen("adventofcode/day11.txt", "r");
    if (!fp) return 1;

    int fft_hash = hash("fft");
    int dac_hash = hash("dac");
    
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (line[0] == '\n' || line[0] == '\0') continue;

        int src = hash(line);
        
        // if(src == fft_hash) continue; 
        // if(src == dac_hash) continue; 
        
        should_visit[src] = true;

        int i = 5;
        while (line[i] >= 'a' && line[i] <= 'z') {
            int dest = hash(&line[i]);
            graph[src][dest] = 1;
            should_visit[dest] = true;

            i += 3;
            if (line[i] == ' ') {
                i++;
            }
        }
    }

    int stack[MAX_VERTICES];
    int stack_index = 0;

    for (int i = 0; i < MAX_VERTICES; i++) {
        if (should_visit[i]) {
            topologicalSort(i, stack, &stack_index);
        }
    }

    combinations[hash("svr")] = 1;
    
    while (stack_index > 0) {
        int src = stack[--stack_index];
        
        for (int i = 0; i < MAX_VERTICES; i++) {
            if (graph[src][i]) {
                combinations[i] += combinations[src];
            }
        }
        
        print_node(src);
    }
    
    printf("%lld ", combinations[hash("out")]);
}

// total 38307838094275385
// exclude fft 35344601650726481
// exclude dac 32836376398851258
// exclude both 30296367501071226

// use fft = 2963236443548904
// use dac = 5471461695424128
// use one or both 8011470593204160

// use both = 423227545768872

