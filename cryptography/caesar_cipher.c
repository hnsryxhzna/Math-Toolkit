#include <stdio.h>
#include <string.h>
#include <ctype.h>

void caesar(char *text, int shift, char *result) {
    shift = ((shift % 26) + 26) % 26;
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            result[i] = (text[i] - base + shift) % 26 + base;
        } else {
            result[i] = text[i];
        }
    }
    result[strlen(text)] = '\0';
}

int main() {
    char text[256], result[256];
    int shift;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter shift: ");
    scanf("%d", &shift);

    caesar(text, shift, result);
    printf("Encrypted: %s\n", result);

    caesar(result, -shift, text);
    printf("Decrypted: %s\n", text);

    return 0;
}
