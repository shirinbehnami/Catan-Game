
#include <vector>
#include <algorithm>

#include"ground.h"

string ground::setResources(int& desert_index)
{
	srand(time(0));
	string s;

	//first part
	//1.wood  2.sheep   3.ore    4.clay    5.wheat  6.desert
	vector<char> vec = { '1','1','1',
					'2','2','2',
					'3','3','3','3','3',
					'4','4','4',
					'5','5','5','5',
					'6' };


	random_shuffle(vec.begin(), vec.end());

	for (int i = 0; i < 19; i++)
	{
		s += vec[i];
		if (vec[i] == '6')
			desert_index = i;
	}

	//second part
	vec = { '1','1',
		 '2','2',
		 '3','3',
		 '4','4',
		 '5' };


	random_shuffle(vec.begin(), vec.end());

	for (int i = 0; i < (hex_num - 19); i++)
	{
		s += vec[i];
	}
	return s;
}
void ground::setnumbers(int desert_index, string& s)
{
	srand(time(0));
	//--------------------------------------------------------
	//first part
	vector< vector<int> > neighbers = {
		/*0*/ {1,3,4},
		/*1*/ {0,4,5,2},
		/*2*/ {1,5,6},
		/*3*/ {0,4,7,8},
		/*4*/ {0,1,3,5,8,9},
		/*5*/ {1,2,4,6,9,10},
		/*6*/ {2,5,10,11},
		/*7*/ {3,8,12},
		/*8*/ {3,4,7,9,12,13},
		/*9*/ {4,5,8,10,13,14},
	};
	vector<int> indexes;
	vector<int> final;
	for (int i = 0; i < hex_num; i++)
	{
		if (i != desert_index && i < 19)
			indexes.push_back(i);
		final.push_back(-1);
	}
	vector<int> numbers = { 2,
						12,
						3,3,3,
						4,4,
						5,5,
						9,9,
						10,
						11,11 };//+6,6,8,8
	vector<int> numbers_islands = { 11,2,4,5,9,10,10 };//+6,8
	random_shuffle(indexes.begin(), indexes.end());
	vector<int> V;
	//6
	final[indexes[0]] = 6;
	V.push_back(indexes[0]);
	//8
	int numberof8 = 0, numberof6 = 0;
	for (int i = 1; i < 18 && (numberof8 != 2 || numberof6 != 1); i++)
	{
		bool flag = true;
		for (vector<int>::iterator j = V.begin(); j != V.end(); j++)
		{
			int T;
			*j > 9 ? T = 18 - (*j) : T = (*j);
			for (vector<int>::iterator it = neighbers[T].begin(); it != neighbers[T].end(); it++)
				if (*j > 9)
				{
					if (*it == 18 - indexes[i])
					{
						flag = false;
						break;
					}
				}
				else
				{
					if (*it == indexes[i])
					{
						flag = false;
						break;
					}
				}

		}
		if (flag && final[indexes[i]] == -1)
		{
			if (numberof6 == 0)
			{
				final[indexes[i]] = 6;
				numberof6++;
			}
			else
			{
				final[indexes[i]] = 8;
				numberof8++;
			}
			V.push_back(indexes[i]);
		}
	}

	//other numbers
	int j = 0;
	for (int i = 0; i < 18; i++)
		if (final[indexes[i]] == -1 && indexes[i] != desert_index)
		{
			final[indexes[i]] = numbers[j];
			j++;
		}

	//----------------------------------------------------------
	//second part
	//6,8
	int X = rand() % 7 + 19;
	int Y = rand() % (28 - X - 2) + 2;
	if (rand() % 2)
	{
		final[X] = 6;
		final[X + Y] = 8;
	}
	else
	{
		final[X] = 8;
		final[X + Y] = 6;
	}
	//other numbers
	random_shuffle(numbers_islands.begin(), numbers_islands.end());
	j = 0;
	for (int i = 19; i < hex_num; i++)
		if (final[i] == -1)
		{
			final[i] = numbers_islands[j];
			j++;
		}
	final[desert_index] = 0;

	for (int i = 0; i < final.size(); i++)
	{
		s += '-';
		s += to_string(final[i]);
	}
}