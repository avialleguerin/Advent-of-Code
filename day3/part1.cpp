#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

bool isDelimiter(const std::string& str, std::string delimiter, std::string::size_type pos)
{
	if (pos + delimiter.size() <= str.size())
		return str.substr(pos, delimiter.size()) == delimiter;
	return false;
}

std::vector<std::string> ft_split(const std::string& str, const std::string& delimiter)
{
	std::vector<std::string> result;
	std::string tmp;
	std::string::size_type i = 0;

	while (i < str.size())
	{
		if (isDelimiter(str, delimiter, i))
		{
			if (!tmp.empty()) 
			{
				result.push_back(tmp);
				tmp.clear();
			}
			i += delimiter.size();
		}
		else
		{
			tmp += str[i];
			++i;
		}
	}

	if (!tmp.empty())
		result.push_back(tmp);
	return result;
}

int countDigits(int n) {
	if (n == 0) return 1;

	n = std::abs(n);

	int count = 0;
	while (n > 0) {
		n /= 10;
		count++;
	}
	return count;
}

bool isdigit(char c) {
	return c >= '0' && c <= '9';
}

bool	mul(std::string mul, int &a, int &b)
{
	std::string tmp_a;
	std::string tmp_b;
	int	pos = 0;

	while (mul[pos] != ',')
	{
		if (!isdigit(mul[pos]))
			return false;
		tmp_a += mul[pos];
		// j++;
		pos++;
	}
	a = std::stoi(tmp_a);

	if (mul[pos++] != ',')
		return false;

	while (mul[pos] != ')')
	{
		if (!isdigit(mul[pos]))
			return false;
		tmp_b += mul[pos];
		pos++;
	}
	b = std::stoi(tmp_b);

	return true;
}

int	main(void)
{
	int	result = 0;

	std::ifstream	file("file.txt");
	
	std::string line;
	for (int i = 0; i < 5; i++)
	{
		std::getline(file, line);
		std::vector<std::string>	substr = ft_split(line, "mul(");

		for (int j = 0; j < substr.size(); j++)
		{
			// std::cout << substr[j] << std::endl;
			int	a = 0;
			int	b = 0;
			mul(substr[j], a, b);
			result += a * b;
		}
	}
	std::cout << result << std::endl;
	return 0;
}