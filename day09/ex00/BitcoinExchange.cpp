#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{
    std::ifstream data;
    data.open("data.csv");

    if (!data.is_open())
    {
        std::cerr << "Error: cannot open data.csv" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(data, line))
    {
        std::istringstream ss(line);
        std::string date;
        double price;
        std::getline(ss, date, ',');
        ss >> price;
        _prices[date] = price;
    }
    data.close();
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        _prices = other._prices;
    }
    return *this;
}

std::map<std::string, double> BitcoinExchange::getPrices() const
{
    return _prices;
}

// void BitcoinExchange::updateRate(std::string const &currency, double rate)
// {
//     _rates[currency] = rate;
// }

// double BitcoinExchange::convert(std::string const &from, std::string const &to, double amount) const
// {
//     if (_rates.find(from) == _rates.end() || _rates.find(to) == _rates.end())
//     {
//         return 0;
//     }
//     return amount * _rates.at(to) / _rates.at(from);
// }