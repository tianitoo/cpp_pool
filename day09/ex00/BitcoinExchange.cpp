#include "BitcoinExchange.hpp"

std::map<std::string, float> BitcoinExchange::_prices;

BitcoinExchange::BitcoinExchange()
{}

int BitcoinExchange::checkDate(std::string date)
{
    std::istringstream ss(date);
    char delim;
    int year, month, day;

    if (date.find_first_not_of("0123456789-") != std::string::npos || date.length() != 10)
    {
        return false;
    }

    if (ss >> year >> delim >> month >> delim >> day)
    {
        if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1 || day > 31 || (year == 2009 && month == 1))
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
        return true;
    }
    else
    {
        return false;
    }
}

void BitcoinExchange::readData() {
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
        float price;
        std::getline(ss, date, ',');
        ss >> price;
        _prices.insert(std::pair<std::string, float>(date, price));
    }
    data.close();
}

std::string BitcoinExchange::findClosestDate(std::string date) {
    std::string closestDate = "";
    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));
    while (closestDate == "")
    {
        if (BitcoinExchange::_prices.find(date) != BitcoinExchange::_prices.end())
        {
            closestDate = date;
        }
        else
        {
            day--;
            if (day < 1)
            {
                day = 31;
                month--;
                if (month < 1)
                {
                    month = 12;
                    year--;
                }
            }
            std::string newMonth = (month < 10) ? "0" + std::to_string(month) : std::to_string(month);
            std::string newDay = (day < 10) ? "0" + std::to_string(day) : std::to_string(day);
            date = std::to_string(year) + "-" + newMonth + "-" + newDay;
        }
    }
    return closestDate;
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
        float amount;
        std::string pipe;
        if (!(ss >> date >> pipe >> amount) || pipe != "|" || !checkDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (amount < 0)
        {
            std::cerr << "Error: not a positive number" << std::endl;
            continue;
        }
        if (amount > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        if (BitcoinExchange::_prices.find(date) != BitcoinExchange::_prices.end())
        {
            std::cout << date << " => " << amount << " = " << amount * BitcoinExchange::_prices.at(date) << std::endl;
        } else {
            std::cout << date << " => " << amount << " = " << amount * BitcoinExchange::_prices.at(findClosestDate(date)) << std::endl;
        }
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

std::map<std::string, float> BitcoinExchange::getPrices() const
{
    return _prices;
}
