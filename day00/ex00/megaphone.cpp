#include <iostream>
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
            while (str[j])
            {
                char c = toupper(str[j]);
                std::cout << c;
                j++;
            }
            i++;
        }
    }
    std::cout << std::endl;
    return (0);
}