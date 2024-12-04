#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::vector<std::string>	ft_split(const std::string& str, char delimiter)
{
	std::vector<std::string> result;
	std::string tmp;

	for (std::string::size_type i = 0; i < str.size(); ++i)
	{
		if (str[i] == delimiter)
		{
			result.push_back(tmp);
			tmp.clear();
		}
		else
			tmp += str[i];
	}
	if (!tmp.empty())
		result.push_back(tmp);
	return result;
}

bool	isSorted(int col[1000])
{
	for (int i = 1; i < 1000; i++)
		if (col[i - 1] > col[i])
			return false;
	return true;
}

int	main(void)
{
	int	col1[1000];
	int	col2[1000];
	int	result = 0;

	std::ifstream	file("file.txt");
	
	std::string line;
	for (int i = 0; i < 1000; i++)
	{
		std::getline(file, line);
		std::vector<std::string>	substr = ft_split(line, ' ');

		col1[i] = std::stoi(substr[0]);
		col2[i] = std::stoi(substr[1]);
	}
	while (!isSorted(col1) || !isSorted(col2))
	{
		for (int i = 1; i < 1000; i++)
		{
			if (col1[i - 1] > col1[i])
				std::swap(col1[i - 1], col1[i]);
			if (col2[i - 1] > col2[i])
				std::swap(col2[i - 1], col2[i]);
		}
	}
	for (int i = 0; i < 1000; i++)
		result += col1[i] - col2[i] >= 0 ? col1[i] - col2[i] : col2[i] - col1[i];
	std::cout << result << std::endl;
	return 0;
}