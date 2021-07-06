#include <iostream>
#include <boost/asio.hpp>
#include <thread>
#include <vector>
#include <string>

using namespace std;
using namespace boost::asio;
using namespace ip;

#define Max_Clients 3
tcp::socket* srvsock[Max_Clients + 1];
int idx = 0;

thread* trds[Max_Clients];
int Tidx = 0;

void recieve_and_send(tcp::socket& sock,int C)
{
	while (1) {
		boost::asio::streambuf buff;
		read_until(sock, buff, "\n");
		string msg = buffer_cast<const char*>(buff.data());
		//save the massage as player::name.
		//srand(time(0));
		//int c = rand() % 3 + 1;
		msg = to_string(C) + "\n";
		cout << C;
		write(sock, boost::asio::buffer(msg));
	}

}


int main()
{
	io_service io;
	srvsock[0] = new tcp::socket(io);
	tcp::acceptor acc(io, tcp::endpoint(tcp::v4(), 8080));

	while (idx < Max_Clients)
	{
		acc.accept(*srvsock[idx]);
		++idx;
		srvsock[idx] = new tcp::socket(io);

	}

	int C = 1;
	for (Tidx = 0, idx = 0; idx < Max_Clients; ++idx)
	{
		trds[Tidx] = new thread(recieve_and_send, ref(*srvsock[idx]),C);
		++Tidx;
		++C;
	}

	for (int i = 0; i < Max_Clients; ++i)
	{
		trds[i]->join();
	}


	


	return 0;
}
