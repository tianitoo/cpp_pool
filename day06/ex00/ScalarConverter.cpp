#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int ScalarConverter::getType(std::string str)
{
	if (str == "nan" || str == "nanf")
		return (NN);
	if (str == "+inf" || str == "+inff")
		return (INF);
	if (str == "-inf" || str == "-inff")
		return (MINF);
	if (str.length() == 1 && isalpha(str[0]))
		return (CHAR);
	if (str.find_first_not_of("0123456789") == std::string::npos &&
		static_cast<long long>(std::strtoll(str.c_str(), nullptr, 10)) <= std::numeric_limits<int>::max() &&
		static_cast<long long>(std::strtoll(str.c_str(), nullptr, 10)) >= std::numeric_limits<int>::min())
		return (INT);
	if (str.find_first_not_of("0123456789.") == std::string::npos &&
		((str.find_first_of(".") != std::string::npos &&
		  str.find_first_of(".") == str.find_last_of(".") &&
		  str.find_first_of(".") != str.length() - 1) ||
		 (str.find_first_of(".") == std::string::npos)))
		return (DOUBLE);
	if (str.find_first_not_of("0123456789.f") == std::string::npos &&
		((str.find_first_of(".") != std::string::npos &&
		  str.find_first_of(".") == str.find_last_of(".") &&
		  str.find_first_of(".") != str.length() - 2) ||
		 (str.find_first_of(".") == std::string::npos)) &&
		str.find_first_of("f") == str.find_last_of("f") &&
		str.find_first_of("f") == str.length() - 1)
		return (FLOAT);
	return (NN);
}

void ScalarConverter::printChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::printInt(int i)
{
	if (i < 32 || i > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::printFloat(float f)
{
	if (f < 32 || f > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::printDouble(double d)
{
	if (d < 32 || d > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::printNan()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void ScalarConverter::printInf()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: +inf" << std::endl;
	std::cout << "float: +inff" << std::endl;
	std::cout << "double: +inf" << std::endl;
}

void ScalarConverter::printMinf()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: -inf" << std::endl;
	std::cout << "float: -inff" << std::endl;
	std::cout << "double: -inf" << std::endl;
}

void ScalarConverter::convert(std::string str)
{
	int type;
	char *end;
	int precision = 0;
	int sign = 1;

	if (str.find_first_of("-") != std::string::npos &&
		str.find_first_of("-") == str.find_last_of("-") &&
		str.find_first_of("-") == 0 &&
		str != "-inf" && str != "-inff")
	{
		str.erase(str.find_first_of("-"), 1);
		sign = -1;
	}
	type = getType(str);
	if (str.find_first_of(".") != std::string::npos)
	{
		for (size_t i = str.find_first_of("."); i < str.length(); i++)
		{
			if (str[i] != '0')
			{
				precision = i - str.find_first_of(".");
			}
		}
		if (!precision)
			precision = 1;
		std::cout << std::fixed << std::setprecision(precision);
	}
	if (type == CHAR)
		printChar(str[0]);
	else if (type == INT)
		printInt(std::strtod(str.c_str(), &end) * sign);
	else if (type == FLOAT)
		printFloat(std::strtof(str.c_str(), &end) * sign);
	else if (type == DOUBLE)
		printDouble(std::strtod(str.c_str(), &end) * sign);
	else if (type == NN)
		printNan();
	else if (type == INF)
		printInf();
	else if (type == MINF)
		printMinf();
}
