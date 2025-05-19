#include <stdio.h>
#include <math.h>

int main(void) {

    int n;
    int t = 2;
    int Q;

    printf("Input integer: ");
    scanf("%d", &n);
    Q = n;
    int nowQ = sqrt(Q);

    while (t < nowQ) {
        if (Q % t == 0) {
            printf("%d * ", t);
            Q = Q / t;
            nowQ = sqrt(Q);
        } else {
            t++;
        }
    }

    if (Q == n) {
        printf("n id prime\n");
    } else {
        printf("%d = %d\n", Q, n);
    }

    return 0;
}
