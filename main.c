#include <stdio.h>
#include <math.h>

double f(double x) {
    int i = 8;
    double num = -i + x;
    double den = 2.5 * i + 1.0 / (i + x);
    double part1 = num / den;
    double part2 = pow(tanh(x), i + 1);
    return part1 + part2;
}

int main() {
    double x, fx;
    double h = 0.1;
    FILE *fp;

    /* запис у файл */
    fp = fopen("data.txt", "w");
    if (!fp) return 1;

    x = -1.0;
    while (x <= 1.0 + 1e-9) {
        fx = f(x);
        fprintf(fp, "%.10f %.10f\n", x, fx);
        x += h;
    }
    fclose(fp);

    /* читання і пошук f(0) */
    fp = fopen("data.txt", "r");
    if (!fp) return 1;

    while (fscanf(fp, "%lf %lf", &x, &fx) == 2) {
        if (fabs(x) < 1e-9) {
            printf("f(0) = %lf\n", fx);
            break;
        }
    }
    fclose(fp);
    return 0;
}
