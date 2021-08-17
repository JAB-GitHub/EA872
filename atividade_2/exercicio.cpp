// by João Pedro Bizzi Velho 218711
#include<iostream>
#include<memory>

// Evita de usar std::<nome> em toda chamada do include iostream
using namespace std;

// Definição das classes 
class coord{
	private:
		int x,y;
	public:
		coord(int x_in, int y_in);
		~coord();
};

class cube{
	private:
		int x,y,z;
	public:
		cube(int x_in, int y_in, int z_in);
		~cube();
		void cube_print_volume();
};

// Construtores e destrutores
coord::coord(int x_in, int y_in){
		x = x_in;
		y = y_in;
}

coord::~coord(){
		cout << "Calling Destructor" << endl;
}
cube::cube(int x_in, int y_in, int z_in){
		x = x_in;
		y = y_in;
		z = z_in;
}

cube::~cube(){
	cout << "Calling Destructor" << endl;
}

// método
void cube::cube_print_volume(){
	cout << x * y * z << endl;
}

int main(){

	// Cria/instancia os objetos
  unique_ptr <coord> c1 (new coord(50,10));
  unique_ptr <cube> c2 (new cube(10,20,30));

	// Chama o método necessário
	c2->cube_print_volume();

	return 0;
}

