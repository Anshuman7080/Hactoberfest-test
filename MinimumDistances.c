#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);
    int *a = malloc(t * sizeof(int));
    
    for (int i = 0; i < t; i++) {
        scanf("%d", &a[i]);
    }
    
    int *b = malloc(t * sizeof(int));
    int *last_seen = malloc(10001 * sizeof(int)); // Assuming a[i] ranges from 0 to 10000
    for (int i = 0; i < 10001; i++) {
        last_seen[i] = -1; // Initialize with -1
    }

    for (int i = 0; i < t; i++) {
        if (last_seen[a[i]] != -1) {
            b[last_seen[a[i]]] = i - last_seen[a[i]]; // Calculate distance to previous occurrence
        }
        last_seen[a[i]] = i; // Update last seen index
    }

    int min_distance = 10001; // Arbitrarily large value
    for (int i = 0; i < t; i++) {
        if (b[i] > 0 && b[i] < min_distance) {
            min_distance = b[i];
        }
    }

    if (min_distance == 10001) {
        printf("-1\n");
    } else {
        printf("%d\n", min_distance);
    }

    free(a);
    free(b);
    free(last_seen);
    return 0;
}
