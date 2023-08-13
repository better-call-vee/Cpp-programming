#include <stdio.h>

int main()
{
    char emp[100];
    scanf("%s", emp);

    double salary, sale;
    scanf("%lf %lf", &salary, &sale);

    double bonus = (sale * 15) / 100;
    salary += bonus;

    printf("TOTAL = R$ %.2f\n", salary);

    return 0;
}
