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
#include <ctime>
#include <fstream>
#include <iostream>

class BitcoinExchange
{
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);

    std::map<std::string, float> getPrices() const;

    static int readData();
    static int checkDate(std::string date);
    static std::string findClosestDate(std::string date);
    static void exchange(std::string fileName);


    void getData();
private:
    static std::map<std::string, float> _prices;
};
