#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool contains_covid_marker(const char *rna) {
    const char *markers[] = {
        "ACGUAUGC",
        "AUGCGUAG",
        "UGCUAGCU"
    };
    int num_markers = sizeof(markers) / sizeof(markers[0]);

    for (int i = 0; i < num_markers; i++) {
        if (strstr(rna, markers[i]) != NULL) {
            return true;
        }
    }
    return false;
}

int main() {
    char rna[1000];

    scanf("%s", rna);

    if (contains_covid_marker(rna)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
