#include <stdio.h>
#include <stdlib.h>

struct vector {
    int* start;
    int length;
};

typedef struct vector vector;

void append(vector* v, int i)
{
    v->start = realloc(v->start, v->length*sizeof(int)+sizeof(int));
    v->length += 1;
    v->start[v->length - 1] = i;
}

int pop(vector* v)
{
    int i = v->start[v->length - 1];
    v->start = realloc(v->start, v->length*sizeof(int)-sizeof(int));
    v->length -= 1;
    return i;
}

int main(int argc, char* argv[])
{
    vector v = { malloc(0), 0 };
    append(&v, 1238);
    append(&v, 894);
    append(&v, 4582);
    append(&v, 7329);
    append(&v, 9823);
    printf("%d\n", pop(&v));
    printf("%d\n", pop(&v));
    printf("%d\n", pop(&v));
    printf("%d\n", pop(&v));
    printf("%d\n", pop(&v));

    free(v.start);

    return 0;
}