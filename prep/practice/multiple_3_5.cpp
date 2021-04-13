#include <iostream>

int main()
{
    size_t n;
    size_t summ = 0;
    // scanf("%zu", &n);
    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
            summ += i;
    }
    // printf("%zu\n", summ);
    std::cout << summ << '\n';
    return 0;
}