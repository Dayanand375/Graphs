#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct graph {
    int u, v, w;
};

struct graph c, g[20] = {
    {0,1,8}, {0,7,16}, {1,7,22}, {1,2,16}, {2,8,4},
    {7,8,14}, {6,7,2}, {6,8,12}, {5,6,4}, {2,5,8},
    {2,3,14}, {3,5,28}, {3,4,18}, {4,5,20}
};

int n = 14, i, j, k;
int a[9], cost = 0;

int find(int, int);
void union1(int, int);
void sort() {
    for (i = 0; i < n - 1; i++) {
        k = i;
        for (j = i + 1; j < n; j++) {
            if (g[j].w < g[k].w) {
                k = j;
            }
        }
        c = g[k];
        g[k] = g[i];
        g[i] = c;
    }
}

void kruskal() {
    for (i = 0; i < 9; i++) {
        a[i] = i;
    }
    int count = 0;

    for (i = 0; i < n; i++) {
        k = find(a[g[i].u], a[g[i].v]);
        if (k == 0) {
            printf("%d\t%d\n", g[i].u, g[i].v);
            cost = cost + g[i].w;
            union1(a[g[i].u], a[g[i].v]);
            count++;
        }
        if (count == 8) {
            break;
        }
    }
    printf("Total minimum cost=%d\n", cost);
}

int find(int u, int v) {
    if (a[u] == a[v]) {
        return (1);
    } else {
        return (0);
    }
}

void union1(int u, int v) {
    int i;
    for (i = 0; i < 9; i++) {
        if (a[i] == a[u])
            a[i] = a[v];
    }
}

int main() {
    sort();
    kruskal();
}

