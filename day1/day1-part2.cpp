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
	for (int i = 0; i < 1000; i++)
	{
		int multiple = 0;
		for (int j = 0; j < 1000; j++)
		{
			if (col1[i] == col2[j])
				multiple++;
		}
		result += col1[i] * multiple;
	}
	std::cout << result << std::endl;
	return 0;
}