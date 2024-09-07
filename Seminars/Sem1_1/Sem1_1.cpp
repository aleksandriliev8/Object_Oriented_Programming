#include<iostream>

struct Point {
	double x;
	double y;
};

struct Triangle {
	Point p1;
	Point p2;
	Point p3;

	double a;
	double b;
	double c;
};


//sqrt( ( x2 – x1 ) * (  x2 – x1 ) + ( y2 – y1 ) * ( y2 – y1) )
double findSides(const Point& p1, const Point& p2) {
	return (double)sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

double findArray(const double& a, const double& b, const double& c) {
	double p = (a + b + c) / 2.0;

	return (double)sqrt(p * (p - a) * (p - b) * (p - c));
}

void print(double arrays[], int N) {
	for (size_t i = 0; i < N; i++)
	{
		std::cout << arrays[i] << " ";
	}
}

int main() {
	int N;
	std::cout << "Number of triangles: ";
	std::cin >> N;

	Triangle triangles[3];

	for (size_t i = 0; i < N; i++)
	{
		std::cout << "Enter point 1 of triangle " << i + 1 << ": ";
		std::cin >> triangles[i].p1.x >> triangles[i].p1.y;
		std::cout << "Enter point 2 of triangle " << i + 1 << ": ";
		std::cin >> triangles[i].p2.x >> triangles[i].p2.y;
		std::cout << "Enter point 3 of triangle " << i + 1 << ": ";
		std::cin >> triangles[i].p3.x >> triangles[i].p3.y;
		
		std::cout << std::endl;

		triangles[i].a = findSides(triangles[i].p1, triangles[i].p2);
		triangles[i].b = findSides(triangles[i].p1, triangles[i].p3);
		triangles[i].c = findSides(triangles[i].p2, triangles[i].p3);
	}

	double arrays[3] = {0.0, 0.0, 0.0};

	for (size_t i = 0; i < N; i++)
	{
		arrays[i] = findArray(triangles[i].a, triangles[i].b, triangles[i].c);
	}

	//sorting

	int min_index = 0;

	for (size_t i = 0; i < N - 1; i++)
	{
		min_index = i;

		for (size_t j = i + 1; j < N; j++)
		{
			if (arrays[j] < arrays[min_index]) {
				min_index = j;
			}
		}

		double temp = arrays[min_index];
		arrays[min_index] = arrays[i];
		arrays[i] = temp;
	}

	print(arrays, N);
}
