#include <iostream>

#include "Ponto.hpp"

using namespace std;

int main(int argc, char * argv[]) {
    Point polygon1[] = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
	int n = sizeof(polygon1)/sizeof(polygon1[0]);
	Point p = {20, 20};
	isInside(polygon1, n, p)? cout << "Yes \n": cout << "No \n";

	p = {5, 5};
	isInside(polygon1, n, p)? cout << "Yes \n": cout << "No \n";

	Point polygon2[] = {{0, 0}, {5, 5}, {5, 0}};
	p = {3, 3};
	n = sizeof(polygon2)/sizeof(polygon2[0]);
	isInside(polygon2, n, p)? cout << "Yes \n": cout << "No \n";

	p = {5, 1};
	isInside(polygon2, n, p)? cout << "Yes \n": cout << "No \n";

	p = {8, 1};
	isInside(polygon2, n, p)? cout << "Yes \n": cout << "No \n";

	Point polygon3[] = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
	p = {-1,10};
	n = sizeof(polygon3)/sizeof(polygon3[0]);
	isInside(polygon3, n, p)? cout << "Yes \n": cout << "No \n";

	return 0;
}
