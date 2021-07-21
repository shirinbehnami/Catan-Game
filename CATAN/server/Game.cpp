
#include "Game.h"

Game::Game()
	:client_num(3),
	gr(new ground)
{
	io_service io;
	tcp::acceptor acc(io, tcp::endpoint(tcp::v4(), 8080));

	int idx = 0;
	while (idx < client_num)
	{
		P_list.push_back(new Player(ref(io), ref(acc)));
		trds.push_back(new thread(&Game::recieve_name, this, idx));
		++idx;
	}

	acc.close();

	for (int i = 0; i < client_num; ++i)
	{
		trds[i]->join();
	}

	make_ground();

	opening();

	play();

}
Game::~Game()
{
}

void Game::recieve_name(int p_index)
{
	boost::asio::streambuf buff;
	read_until(*(P_list[p_index]->get_sock()), buff, '\n');
	string msg = buffer_cast<const char*>(buff.data());
	P_list[p_index]->set_name(msg);

	msg = to_string(p_index + 1);
	write(*(P_list[p_index]->get_sock()), boost::asio::buffer(msg));
	if (p_index == 0)
	{
		number_of_player(p_index);
	}
	else
	{
		Sleep(1);
		write(*(P_list[p_index]->get_sock()), boost::asio::buffer(to_string(client_num)));
	}
}
void Game::number_of_player(int p_index)
{
	boost::asio::streambuf buff;
	read_until(*(P_list[p_index]->get_sock()), buff, '\n');
	string msg = buffer_cast<const char*>(buff.data());
	sscanf_s(msg.c_str(), "%d", &client_num);
}
void Game::make_ground()
{
	int desert_num = 0;

	string s = gr->setResources(desert_num);
	gr->setnumbers(desert_num, s);

	for (int p_index = 0; p_index < client_num; p_index++)
	{
		write(*(P_list[p_index]->get_sock()), boost::asio::buffer(s));
	}
}

void Game::opening()
{

	for (int p_index = 0; p_index < client_num; p_index++)
	{
		boost::asio::streambuf buff;

		read_until(*(P_list[p_index]->get_sock()), buff, '\n');
		string msg = buffer_cast<const char*>(buff.data());
		msg.erase(std::remove(msg.begin(), msg.end(), '\n'), msg.end());

		broadcast(p_index, msg);
	}

	for (int p_index = client_num - 1; p_index >= 0; p_index--)
	{
		boost::asio::streambuf buff;

		read_until(*(P_list[p_index]->get_sock()), buff, '\n');
		string msg = buffer_cast<const char*>(buff.data());
		msg.erase(std::remove(msg.begin(), msg.end(), '\n'), msg.end());

		broadcast(p_index, msg);
	}
}
void Game::play()
{
	int p_index = 0;
	while (p_index < client_num)
	{

		boost::asio::streambuf buff;
		read_until(*(P_list[p_index]->get_sock()), buff, '\n');
		string msg = buffer_cast<const char*>(buff.data());
		msg.erase(std::remove(msg.begin(), msg.end(), '\n'), msg.end());
		broadcast(p_index, msg);

		int sum;
		sscanf_s(msg.c_str(), "%d", &sum);
		if (((sum / 10) + (sum % 10)) == 7)
		{
			Sleep(1);
			boost::asio::streambuf buff2;
			read_until(*(P_list[p_index]->get_sock()), buff2, '\n');
			string msg = buffer_cast<const char*>(buff2.data());
			msg.erase(std::remove(msg.begin(), msg.end(), '\n'), msg.end());
			broadcast(p_index, msg);
		}

		p_index++;
		if (p_index == client_num)
			p_index = 0;
	}
}
void Game::broadcast(int index, string msg)
{
	for (int p_index = 0; p_index < client_num; p_index++)
		if (p_index != index)
			write(*(P_list[p_index]->get_sock()), boost::asio::buffer(msg));
}