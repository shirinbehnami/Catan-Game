
#include "player.h"
#include "ground.h"

#include <thread>

class Game
{
public:
	Game();
	~Game();

	void make_ground();
	void broadcast(int index, string msg);
private:
	void number_of_player(int p_index);
	void recieve_name(int p_index);
	void opening();
	void play();

	int client_num;
	vector<Player*> P_list;
	vector<thread*> trds;
	ground* gr;
};