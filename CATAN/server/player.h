
#include <boost/asio.hpp>
#include <iostream>
#include <string>

using namespace std;

using namespace boost::asio;
using namespace ip;


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