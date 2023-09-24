#include <iostream>
#include <cctype>
#include <string>

int main(int argc, char **argv)
{
    int i;
    int j;
    std::string str;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        i = 1;
        while (i < argc)
        {
            str = argv[i];
            j = 0;
            while (argv[i][j])
            {
                std::cout << (char)toupper(str[j]);
                j++;
            }
            i++;
        }
    }
    std::cout << std::endl;
    return (0);
}