#include <iostream>
#include <string>

using namespace std;

class ground
{
public:
	string setResources(int& desert_index);
	void setnumbers(int desert_index, string& s);
private:
	int hex_num = 28;
	int water_num = 2;
};