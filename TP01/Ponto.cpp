#include "Ponto.hpp"
#include <iostream>

using namespace std;

#define INF 100000009

Ponto::Ponto(long long int x, long long int y) {
    this.x = x;
    this.y = y;
}

Ponto::onSegment(Ponto a, Ponto b, Ponto c) {
	if (c.x <= max(a.x, b.x) && c.x >= min(a.x, b.x) &&
			c.y <= max(a.y, b.y) && c.y >= min(a.y, b.y))
		return true;
	return false;
}

Ponto::orientation(Ponto a, Ponto b, Ponto c) {
	int val = (b.y - a.y) * (c.x - b.x) -
			(b.x - a.x) * (c.y - b.y);

	if (val == 0)
        return 0; // colinear

	return (val > 0) ? 1 : 2; // sentido horário ou anti-horário
}

Ponto::doIntersect(Ponto a, Ponto b, Ponto c, Ponto d) {
	// Find the four orientations needed for general and
	// special cases
	int o1 = orientation(a, b, c);
	int o2 = orientation(a, b, d);
	int o3 = orientation(c, d, a);
	int o4 = orientation(c, d, b);

	// General case
	if (o1 != o2 && o3 != o4)
		return true;

	// Special Cases
	// a, b and c are colinear and c lies on segment p1q1
	if (o1 == 0 && onSegment(a, c, b)) return true;

	// a, b and c are colinear and d lies on segment p1q1
	if (o2 == 0 && onSegment(a, d, b)) return true;

	// c, d and a are colinear and a lies on segment p2q2
	if (o3 == 0 && onSegment(c, a, d)) return true;

	// c, d and b are colinear and b lies on segment p2q2
	if (o4 == 0 && onSegment(c, b, d)) return true;

	return false; // Doesn't fall in any of the above cases
}

Ponto::isInside(Ponto poligono[], int n, Ponto a) {
	// There must be at least 3 vertices in poligono[]
	if (n < 3) return false;

	// Create a point for line segment from a to infinite
	Ponto p_infinito = {INF, a.y};

	// Count intersections of the above line with sides of poligono
	int count = 0, i = 0;
	do
	{
		int next = (i+1)%n;

		// Check if the line segment from 'a' to 'p_infinito' intersects
		// with the line segment from 'poligono[i]' to 'poligono[next]'
		if (doIntersect(poligono[i], poligono[next], a, p_infinito))
		{
			// If the point 'a' is colinear with line segment 'i-next',
			// then check if it lies on segment. If it lies, return true,
			// otherwise false
			if (orientation(poligono[i], a, poligono[next]) == 0)
                return onSegment(poligono[i], a, poligono[next]);

			count++;
		}
		i = next;
	} while (i != 0);

	// Return true if count is odd, false otherwise
	return count&1; // Same as (count%2 == 1)
}
