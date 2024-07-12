#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cmath>
# include <iomanip>
# include <limits>

# define CHAR 1
# define INT 2
# define FLOAT 3
# define DOUBLE 4
# define INF 5
# define NN 6

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		static int		getType(std::string str);
		static void		printChar(char c);
		static void		printInt(int i);
		static void		printFloat(float f);
		static void		printDouble(double d);
		static void		printNan();
		static void		printInf();
	
	public:
		static void		convert(std::string str);
};

#endif