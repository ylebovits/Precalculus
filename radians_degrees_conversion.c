#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <time.h>

#define PSET_SIZE 100 /* number of problems to generate */

int random_int(int, int);
void generate_radian_and_degree(int *degree, char *radian[]);

int main(void)
{

    srand(time(NULL));

    FILE *questions_file = fopen("angle_measure_practice_sheet_(radians).txt", "w");
    FILE *answers_file = fopen("angle_measure_practice_sheet_(degrees).txt", "w");

    int degrees[PSET_SIZE];
    char radians[PSET_SIZE][10];

    for (int i = 0; i < PSET_SIZE; i++)
    {
        generate_radian_and_degree(&degrees[i], &radians[i]);
    }

    for (int j = 0; j < PSET_SIZE; j++)
    {
        fprintf(questions_file, "%d) %s\n", j+1, radians[j]);
    }

    for (int k = 0; k < PSET_SIZE; k++)
    {
        fprintf(answers_file, "%d) %dº\n", k+1, degrees[k]);
    }

    fclose(questions_file);
    fclose(answers_file);

    return 0;
}

int random_int(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

void generate_radian_and_degree(int *degree, char *radian[])
{
    char rad_holder[10];
    int common_den[] = {1, 2, 3, 4, 6};
    int numerator = random_int(1, 25);
    
    int denominator = common_den[random_int(1, 4)];

    *degree = numerator * 180 / denominator;
    sprintf(rad_holder, "%dπ/%d", numerator, denominator);

    strcpy(&(*radian), rad_holder);
}