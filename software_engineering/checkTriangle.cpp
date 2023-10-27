#include <bits/stdc++.h>
int main()
{
	std::cout << "Enter the number of triangles to check : ";
	int t;
	std::cin >> t;
	while (t--)
	{
		int a, b, c;
		std::cout << "Enter three sides: ";
		std::cin >> a >> b >> c;

		if (a + b <= c or a + c <= b or b + c <= a)
		{
			std::cout << "Not a triangle" << std::endl;
		}

		else if (a == b and b == c)
		{
			std::cout << "Equilateral triangle" << std::endl;
		}

		else if (a == b or b == c or a == c)
		{
			std::cout << "Isoceles Triangle" << std::endl;
		}
		else 
		std::cout << "Scalene Triangle" << std::endl;
	}
}
