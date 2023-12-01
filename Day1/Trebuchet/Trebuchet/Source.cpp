#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const char DIGITS[] = {'1','2','3','4','5','6','7','8','9','0'};
const int DIGITS_SIZE = sizeof(DIGITS) / sizeof(char);

const string WORDS[] = { "one","two","three","four","five","six","seven","eight","nine" };
const int WORDS_SIZE = 9;

//takes a line from the list and makes a 2 digit number from the first and last digit
int GetDigits(string line)
{
	int firstDigit = -1;
	int secondDigit = -1;
	for (int i = 0; i < line.size(); i++)
	{
		for (int j = 0; j < DIGITS_SIZE; j++)
		{
			if (line[i] == DIGITS[j])
			{
				firstDigit = line[i] - '0';
				break;
			}
		}
		if (firstDigit != -1)
		{
			break;
		}
		for (int j = 0; j < WORDS_SIZE; j++)
		{
			if (i + WORDS[j].size()-1 < line.size())
			{
				if (line.substr(i, WORDS[j].size()) == WORDS[j])
				{
					firstDigit = j + 1;
					break;
				}
			}
		}
		if (firstDigit != -1)
		{
			break;
		}
	}

	for (int i = line.size() - 1; i >= 0; i--)
	{
		for (int j = 0; j < DIGITS_SIZE; j++)
		{
			if (line[i] == DIGITS[j])
			{
				secondDigit = line[i] - '0';
				break;
			}
		}
		if (secondDigit != -1)
		{
			break;
		}
		for (int j = 0; j < WORDS_SIZE; j++)
		{
			int newI = i - (WORDS[j].size() - 1);
			if (newI + WORDS[j].size()-1 < line.size() && newI >= 0)
			{
				if (line.substr(newI, WORDS[j].size()) == WORDS[j])
				{
					secondDigit = j + 1;
					break;
				}
			}
		}
		if (secondDigit != -1)
		{
			break;
		}
	}

	int ret = (firstDigit * 10) + secondDigit;

	cout << line << " = " << ret << endl;

	return ret;
}

int main()
{
	int sum = 0;

	string line;
	ifstream file("values.txt");

	while (getline(file, line))
	{
		sum += GetDigits(line);
	}

	cout << sum;
}