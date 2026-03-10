#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point a(0, -4/(float)3);
	Point b(12/(float)7, 0);
	Point c(3, -3);

	// Point a(0, 0);
	// Point b(0, 2);
	// Point c(3, 1);

	Point arr[6] = {
		Point(2, -1), //yes
		Point(1, -1), // yes
		Point(2, -2), // yes
		Point(1, -0.5), // slightly out (so no)
		Point(1, -5/(float)9), // on line (so no)
		Point(1, 0), // no
		//Point(2, 1)
	};
	for (int i = 0; i < 6; i++)
		std::cout << std::boolalpha << bsp(a, b, c, arr[i]) <<std::endl;

	//std::cout << "WEIRD TEST :"<<bsp(Point(0, 0), Point(2, 1), Point(0, 0), Point(1, 0.5))<<std::endl;
}

