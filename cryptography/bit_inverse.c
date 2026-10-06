#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        return 1;
    }

    FILE *in = fopen(argv[1], "rb");
    FILE *out = fopen(argv[2], "wb");

    if(!in || !out) {
        return 1;
    }

    unsigned char buffer[1024];
    size_t n;
    while ((n = fread(buffer, 1, sizeof(buffer), in)) > 0) {
        for (size_t i = 0; i < n; i++) {
            buffer[i] = ~buffer[i];
        }
        fwrite(buffer, 1, n, out);
    }

    fclose(in);
    fclose(out);

    return 0;
}
