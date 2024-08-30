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

int BitcoinExchange::checkDate(std::string date) const
{
    std::istringstream ss(date);
    char delim;
    int year, month, day;

    if (ss >> year >> delim >> month >> delim >> day)
    {
        if (year < 2009 || year > 2021 || month < 1 || month > 12 || day < 1 || day > 31)
        {
            return false;
        }
        if (month == 2)
        {
            if (day == 29 && year % 4 != 0)
            {
                return false;
            }
            else if (day > 28)
            {
                return false;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            if (day > 30)
            {
                return false;
            }
        }
        return 0;
    }
    else
    {
        return -1;
    }
}

void BitcoinExchange::exchange(std::string fileName) {
    std::ifstream infile(fileName);
    if (!infile.is_open())
    {
        std::cerr << "Error: cannot open " << fileName << std::endl;
        return;
    }
    std::string line;
    while (std::getline(infile, line))
    {
        std::istringstream ss(line);
        std::string date;
        double amount;
        std::string currency; // todo
        ss >> date >> amount >> currency;
        if (checkDate(date) == -1)
        {
            std::cerr << "Error: invalid date" << std::endl;
            continue;
        }
        if (_prices.find(date) == _prices.end())
        {
            std::cerr << "Error: no data for this date" << std::endl;
            continue;
        }
        std::cout << date << " " << amount << " BTC = " << amount * _prices.at(date) << " " << currency << std::endl;
    }
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