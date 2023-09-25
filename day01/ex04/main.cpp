#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::ifstream input(filename);

    int pos;
    std::string line;
    std::string newFileContent;

    if (!input.is_open())
    {
        std::cout << "File does not exist" << std::endl;
        return 1;
    }
    while (std::getline(input, line))
    {
        for(int i = 0; i < line.length(); i++)
        {
            pos = line.find(s1);
            if (pos != std::string::npos)
            {
                line.erase(pos, s1.length());
                line.insert(pos, s2);
            }
            else
                break;
        }
        newFileContent += line;
        newFileContent += "\n";
    }
    input.close();
    std::ofstream output(filename + ".replace");
    output << newFileContent;
    output.close();
    return 0;
}