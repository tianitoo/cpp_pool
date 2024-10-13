#include "BitcoinExchange.hpp"

std::map<std::string, float> BitcoinExchange::_prices;
int BitcoinExchange::_firstYear = -1;
int BitcoinExchange::_firstMonth = -1;
int BitcoinExchange::_firstDay = -1;

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
        if (year < _firstYear) {
            return false;
        }
        if (year == _firstYear && month < _firstMonth) {
            return false;
        }
        if (year == _firstYear && month == _firstMonth && day < _firstDay) {
            return false;
        }
        if (month < 1 || month > 12 || day < 1 || day > 31)
        {
            return false;
        }
        if (month == 2)
        {
            if (day > 29)
            {
                return false;
            }
            if (day == 29 && year % 4 != 0)
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

int BitcoinExchange::readData() {
    std::ifstream data;
    data.open("data.csv");

    if (!data.is_open())
    {
        std::cerr << "Error: cannot open data.csv" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(data, line))
    {
        std::istringstream ss(line);
        std::string date;
        float price;
        std::getline(ss, date, ',');
        ss >> price;
        if (_firstYear == -1 && date.find_first_not_of("0123456789-") == std::string::npos)
        {
            _firstYear = std::stoi(date.substr(0, 4));
            _firstMonth = std::stoi(date.substr(5, 2));
            _firstDay = std::stoi(date.substr(8, 2));
        }
        _prices.insert(std::pair<std::string, float>(date, price));
    }
    data.close();
    return 0;
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

void BitcoinExchange:: exchange(std::string fileName) {
    std::ifstream infile(fileName);
    if (!infile.is_open())
    {
        std::cerr << "Error: cannot open " << fileName << std::endl;
        return;
    }
    std::string line;
    std::getline(infile, line);
    if (line != "date | value")
    {
        std::cerr << "Error: bad data.csv" << std::endl;
        return;
    }
    while (std::getline(infile, line))
    {
        std::istringstream ss(line);
        std::string date;
        float amount;
        std::string strAmount;
        std::string pipe;
        std ::string rest;
        if (
            !(ss >> date >> pipe >> strAmount) ||
            ss >> rest ||
            strAmount.find_first_not_of("0123456789.") != std::string::npos ||
            strAmount[0] == '.' ||
            strAmount[strAmount.length() - 1] == '.' ||
            strAmount.find('.') != strAmount.rfind('.') ||
            pipe != "|" || !checkDate(date)
            ) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        ss.clear();
        ss.str(strAmount);
        ss >> amount;
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
