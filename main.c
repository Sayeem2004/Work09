#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct student {
    char name[21];
    int grade;
    double gpa;
};

void print_record(struct student *s) {
    printf("Student %s is in the %2.dth grade and has a gpa of %lf\n",s->name,s->grade,s->gpa);
    return;
}

struct student *create_record(char *name, int grade, double gpa) {
    struct student *s = (struct student *) calloc(1, sizeof(struct student));
    strncpy((char *)&(s->name), name, 20);
    s->grade = grade;
    s->gpa = gpa;
    return s;
}

int comp(const void *a, const void *b) {
    double gpa1 = (*((struct student **)a))->gpa;
    double gpa2 = (*((struct student **)b))->gpa;
    if (gpa1 > gpa2) return -1;
    if (gpa2 > gpa1) return 1;
    return 0;
}

int main() {
    // Creating Random School Records
    int i, n = 20;
    struct student *school[n];
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        char name[4]= {(char)(rand()%26+65), (char)(rand()%26+65), (char)(rand()%26+65), '\0'};
        int grade = rand() % 12 + 1;
        double gpa = (rand() % 1200) / 120.0 + 88;
        school[i] = create_record(name, grade, gpa);
    }

    // Sorting School Records And Printing
    qsort(school, n, sizeof(school[0]), comp);
    printf("List of %d random NYC students in order from best to worst:\n", n);
    for (i = 0; i < n; i++) {
        print_record(school[i]);
    }
}
