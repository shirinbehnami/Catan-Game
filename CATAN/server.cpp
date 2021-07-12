#include <iostream>
#include <boost/asio.hpp>
#include <thread>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using namespace boost::asio;
using namespace ip;

class ground
{
public:
	string setResources(int& desert_index);
	void setnumbers(int desert_index, string &s);
private:
	int hex_num = 28;
	int water_num = 2;
};

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
	vec = {'1','1',
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
	//------------------------------------------------------------------------------------------------------
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
	vector<int> numbers_islands = { 2,4,5,9,10,10,11 };//+6,8
	random_shuffle(indexes.begin(), indexes.end());
	//6
	final[indexes[0]] = 6;
	final[indexes[1]] = 6;
	//8
	int numberof8 = 0;
	for (int i = 0; i < 19 && numberof8 != 2; i++)
	{
		bool flag = true;
		for (int j = 0; j < 2 && flag; j++)
		{
			int T;
			indexes[j] > 9 ? T = 18 - indexes[j] : T = indexes[j];
			for (vector<int>::iterator it = neighbers[T].begin(); it != neighbers[T].end(); it++)
				if (indexes[j] > 9)
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
			final[indexes[i]] = 8;
			numberof8++;
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
	//-----------------------------------------------------------------------------------------------------
	//second part
	//6,8
	int X = rand() % 6 + 19;
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
	random_shuffle(numbers_islands.begin(), numbers_islands.end());
	j = 0;
	for (int i = 19; i < hex_num; i++)
		if (final[i] == -1 && i != desert_index)
		{
			final[i] = numbers_islands[j];
			j++;
		}


	for (int i = 0; i < final.size(); i++)
	{
		s += '-';
		s += to_string(final[i]);
	}
}

class Player
{
public:
	Player(io_service& io_service, tcp::acceptor& acc) :sock(io_service) { acc.accept(sock); }

	void set_name(string n) { name = n; };

	tcp::socket* get_sock() { return &sock; }
private:
	tcp::socket sock;
	string name;
};

class Game
{
public:
	Game();
	~Game();

	void make_ground();
private:
	void number_of_player(int p_index);
	void recieve_name(int p_index);

	int client_num;
	vector<Player*> P_list;
	vector<thread*> trds;
	ground* gr;
};

Game::Game()
	:client_num(3),
	gr(new ground)
{
	io_service io;
	tcp::acceptor acc(io, tcp::endpoint(tcp::v4(), 8080));

	int idx = 0;
	while (idx < client_num)
	{
		P_list.push_back(new Player(ref(io),ref(acc)));

		recieve_name(idx);

		++idx;
	}

	make_ground();
	
	acc.close();
}
Game::~Game()
{
	for (int i = 0; i < client_num; ++i)
	{
		trds[i]->join();
	}
}

void Game::make_ground()
{
	int desert_num = 0;

	string s = gr->setResources(desert_num);
	gr->setnumbers(desert_num,s);

	cout <<endl<< s;
	for (int p_index = 0; p_index < client_num; p_index++)
	{
		write(*(P_list[p_index]->get_sock()), boost::asio::buffer(s));
	}
}

void Game::number_of_player(int p_index)
{
	boost::asio::streambuf buff;
	read_until(*(P_list[p_index]->get_sock()), buff, '\n');
	string msg = buffer_cast<const char*>(buff.data());
	sscanf_s(msg.c_str(), "%d", &client_num);

	//-----------------------
	//client_num = 1;
}
void Game::recieve_name(int p_index)
{
	boost::asio::streambuf buff;
	read_until(*(P_list[p_index]->get_sock()), buff, '\n');
	string msg = buffer_cast<const char*>(buff.data());
	P_list[p_index]->set_name(msg);
	
	//srand(time(0));
	//int c = rand() % 3 + 1;
	msg = to_string(p_index+1);
	cout << p_index+1;
	write(*(P_list[p_index]->get_sock()), boost::asio::buffer(msg));
	if (p_index == 0)
	{
		number_of_player(p_index);
	}
	
}

int main()
{
	Game Catan;

	return 0;
}
