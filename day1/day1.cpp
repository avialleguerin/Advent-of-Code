#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int	ft_stoi(const std::string &str)
{
	bool	isNegative = false;
	int		result;
	size_t i = 0;

	while (i < str.length() && (str[i] == ' ' || str[i] == '\t')) {
		i++;
	}
	if (i < str.length() && (str[i] == '-' || str[i] == '+')) {
		if (str[i] == '-') {
			isNegative = true;
		}
		i++;
	}
	while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (i < str.length() && (str[i] < '0' || str[i] > '9')) {
		return -1;
	}

	result = isNegative ? -result : result;
	return result;
}

std::vector<std::string>	ft_split(const std::string& str, char delimiter)
{
	std::vector<std::string> result;
	std::string tmp;

	for (std::string::size_type i = 0; i < str.size(); ++i) {
		if (str[i] == delimiter) {
			result.push_back(tmp);
			tmp.clear();
		} else {
			tmp += str[i];
		}
	}

	// Ajouter la dernière partie (si elle existe)
	if (!tmp.empty()) {
		result.push_back(tmp);
	}

	return result;
}

int	main(void)
{
	std::vector<int>	col1;
	std::vector<int>	col2;
	int					diff;
	std::ifstream	file("file.txt");
	
	std::string line;
	for (int i = 0; i < 10000; i++)
	{
		std::getline(file, line);
		std::vector<std::string>	substr = ft_split(line, ' ');

		col1[i] = ft_stoi(substr[0]);
		col2[i] = ft_stoi(substr[1]);
		diff += col1[i] - col2[i] >= 0 ? col1[i] - col2[i] : col2[i] - col1[i];
	}
	std::cout << diff << std::endl;

}