#include <stdio.h>

int main() {
    FILE *fpointer;
    fpointer = fopen("password.txt", "r");

    char text[4];
    while(fgets(text, sizeof(text), fpointer) != NULL) {
        printf("%s", text);
    }
}