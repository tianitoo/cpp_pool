#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

int ScalarConverter::getType(std::string str)
{
	if (str == "nan" || str == "nanf")
		return (NAN);
	if (str == "inf" || str == "+inf" || str == "inff" || str == "+inff")
		return (INF);
	if (str.length() == 1 && isalpha(str[0]))
		return (CHAR);
	if (str.find_first_not_of("0123456789") == std::string::npos)
		return (INT);
	if (str.find_first_not_of("0123456789.") == std::string::npos &&
		str.find_first_of(".") != std::string::npos &&
		str.find_first_of(".") == str.find_last_of("."))
		return (DOUBLE);
	if (str.find_first_not_of("0123456789.") == std::string::npos &&
		str.find_first_of(".") != std::string::npos &&
		str.find_first_of(".") != str.find_last_of(".") &&
		str.find_first_of("f") == str.find_last_of("f") &&
		str.find_first_of("f") == str.length() - 1)
		return (FLOAT);
	return (NAN);
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
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: inff" << std::endl;
	std::cout << "double: inf" << std::endl;
}

void ScalarConverter::convert(std::string str)
{
	int type = getType(str);
	if (type == CHAR)
		printChar(str[0]);
	else if (type == INT)
		printInt(std::stoi(str));
	else if (type == FLOAT)
		printFloat(std::stof(str));
	else if (type == DOUBLE)
		printDouble(std::stod(str));
	else if (type == NAN)
		printNan();
	else
		printInf();
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert [string]" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}