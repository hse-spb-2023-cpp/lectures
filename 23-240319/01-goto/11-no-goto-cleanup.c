#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        printf("Unable to open file\n");
        return 1;
    }

    int n;
    if (fscanf(f, "%d", &n) != 1) {
        printf("Unable to read n\n");
        fclose(f);
        return 1;
    }

    int *arr = malloc(n * sizeof(int));
    if (!arr) {
        printf("Unable to allocate array for %d ints\n", n);
        fclose(f);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(f, "%d", &arr[i]) != 1) {
            printf("Unable to read element %d\n", i + 1);
            free(arr);
            fclose(f);
            return 1;
        }
    }

    // WONTFIX: check printf result. No assert() because it can be removed.
    printf("Result: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d", arr[i]);
        if (i > 0)
            printf(" ");
    }
    printf("\n");

    free(arr);
    fclose(f);
    return 0;
}
