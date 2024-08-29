#include "BitcoinExchange.hpp"


int checkDate(std::string date, BitcoinExchange exchange)
{
    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));
    if (year < 2009 || year > 2022)
    {
        return 0;
    }
    if (month < 1 || month > 12)
    {
        return 0;
    }
    if (day < 1 || day > 31)
    {
        return 0;
    }
    if (date.length() != 10)
    {
        return 0;
    }
    if (date[4] != '-' || date[7] != '-')
    {
        return 0;
    }
    std::cout << "date:c " << exchange.getPrices().find(date)->first << std::endl;
    if (exchange.getPrices().find(date) == exchange.getPrices().end())
    {
        return 0;
    }
    return 1;
}

int checkValue(double value)
{
    if (value < 0)
    {
        std::cerr << "Error: not a positive number" << std::endl;
        return 0;
    }
    return 1;
}


int main(int argc, char **argv)
{
    // read from file
    (void)argc;
    BitcoinExchange exchange;
    std::ifstream btc;

    btc.open(argv[1]);
    if (!btc.is_open())
    {
        std::cerr << "Error: cannot open data.csv" << std::endl;
        return 1;
    }

    // std::cout << "|" << exchange.getPrices().at("2009-01-02") << "|" << std::endl;

    std::string line;
    while (std::getline(btc, line))
    {
        std::string date;
        double value;
        // double price;

        // get date and value separated by |
        std::istringstream ss(line);
        // check if line is valid format YYYY-MM-DD | value

        std::getline(ss, date, '|');
        date = date.substr(0, date.length() - 1);
        if (checkDate(date, exchange) == 0)
        {
            std::cerr << "Error: invalid date format" << std::endl;
            continue;
        }
        ss >> value;
        if (checkValue(value) == 0)
        {
            continue;
        }

        std::cout << "|" << date << "|" << value << "|" << std::endl;
        std::cout << date << " => " << value << " = " << value * exchange.getPrices().at(date) << std::endl;
    }
    
}