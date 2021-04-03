#include <stdio.h>

int main()
{
    size_t n;
    size_t summ=0;
    scanf("%zu", &n);
    for (size_t i = 0; i < n; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
            summ += i;
    }
    printf("%zu\n", summ);
    return 0;
}