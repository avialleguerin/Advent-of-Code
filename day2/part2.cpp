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

int	isSafe(int	line[8], int modif)
{
	bool	evolution = line[0] < line[1];

	for (int i = 1; i < 8; i++)
	{
		bool	tmp_evolution = line[i - 1] < line[i];
		int		diff = (line[i - 1] - line[i] > 0 ? line[i - 1] - line[i] : line[i] - line[i - 1]);

		if (line[i] == 0)
			break ;
		if (diff == 0 || evolution != tmp_evolution || diff > 3)
		{
			return rmlvl(line, i - 1);
			if (modif >= 1)
				return (0);
		}
	}
	if (modif > 0 && modif <= 1)
		return (1);
}

int	main(void)
{
	int	result = 0;

	std::ifstream	file("file.txt");
	
	std::string line;
	for (int i = 0; i < 1000; i++)
	{
		std::getline(file, line);
		std::vector<std::string>	substr = ft_split(line, ' ');
		int tmp_line[8] = {0, 0, 0, 0, 0, 0, 0};
		for (int j = 0; j < substr.size(); j++)
			tmp_line[j] = std::stoi(substr[j]);
		result += isSafe(tmp_line, 0);
	}
	std::cout << result << std::endl;
	return 0;
}