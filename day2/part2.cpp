#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
int*	rmlvl(int	line[8], int index);
int	isSafe(int	line[8]);
int	nb_line = 0;

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

int*	rmlvl(int	line[8], int index)
{
	for (int i = index; i < 8; i++)
	{
		if (line[i + 1] > 99)
			line[i] = 0;
		else
			line[i] = line[i + 1];
		if (line[i + 1] == 0)
			break ;
	}
	return line;
}

int	isSafe(int	line[8])
{
	bool	evolution = line[0] < line[1];
	for (int i = 1; i < 8; i++)
	{
		bool	tmp_evolution = line[i - 1] < line[i];
		int		diff = (line[i - 1] - line[i] > 0 ? line[i - 1] - line[i] : line[i] - line[i - 1]);

		if (line[i] == 0)
			break ;
		if (diff == 0 || evolution != tmp_evolution || diff > 3)
			return (0);
	}
	return (1);
}

int	main(void)
{
	int	result = 0;

	std::ifstream	file("file.txt");
	std::string line;
	for (int i = 0; i < 1000; i++)
	{
		nb_line++;
		std::getline(file, line);
		std::cout << line << std::endl;
		std::vector<std::string>	substr = ft_split(line, ' ');
		int tmp_line[8] = {0, 0, 0, 0, 0, 0, 0};
		for (int j = 0; j < substr.size(); j++)
			tmp_line[j] = std::stoi(substr[j]);
		if (isSafe(tmp_line))
			result++;
		else
		{
			for (int j = 0; j < 8; j++)
			{
				int	tmp_tab[8];
				for (int k = 0; k < 8; k++)
					tmp_tab[k] = tmp_line[k];
				if (isSafe(rmlvl(tmp_tab, j)))
				{
					result++;
					break ;
				}
			}
		}
	}
	std::cout << result << std::endl;
	return 0;
}