#include <iostream>
#include <cctype>
#include <string>

int main(int argc, char **argv)
{
    int i;
    int j;
    char c;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        i = 1;
        while (i < argc)
        {
            j = 0;
            while (argv[i][j])
            {
                c = toupper(argv[i][j]);
                std::cout << c;
                j++;
            }
            i++;
        }
    }
    std::cout << std::endl;
    return (0);
}