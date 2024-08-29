#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <iostream>

class BitcoinExchange
{
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);

    std::map<std::string, double> getPrices() const;

private:
    std::map<std::string, double> _prices;
};
