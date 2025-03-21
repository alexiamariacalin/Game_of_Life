#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print_gen(char **gen, int N, int M, int K, FILE *fout)
{
    // fprintf (fout, "A %d-a generatie:\n", K);
    for (int i = 0; i < N; i++)
    {
        fputs(gen[i], fout);
        fputs("\n", fout);
    }
    fputs("\n", fout);
}
void read_data(int *T, int *N, int *M, int *K, char ***gen, FILE *fin)
{
    fscanf(fin, "%d %d %d %d", T, N, M, K);
    (*gen) = (char **)malloc(sizeof(char *) * (*N));
    char buf[2];
    for (int i = 0; i < *N; i++)
    {
        fgets(buf, 2, fin);
        (*gen)[i] = (char *)malloc(sizeof(char) * (*M));
        fread((*gen)[i], sizeof((*gen)[0][0]), *M, fin);
    }
}
int main()
{
    int T, M, N, K;
    char **gen;

    FILE *fin = fopen("in/test.in", "rt");
    FILE *fout = fopen("out/test.out", "wt");

    read_data(&T, &N, &M, &K, &gen, fin);
    print_gen(gen, N, M, K, fout);

    return 0;
}