#include "Stack.hpp"
#include <iostream>
int main()
{
	try {
		stack<int> st1;
		st1.push(1);
		std::cout << st1.count() << std::endl;
		st1.push(10);
		std::cout << st1.count() << std::endl;
		st1.pop();
		std::cout << st1.count() << std::endl;
		st1.push(2);
		std::cout << st1.count() << std::endl;
		st1.push(3);
		std::cout << st1.count() << std::endl;
		st1.push(4);
		std::cout << st1.count() << std::endl;
	}
	catch (std::underflow_error& err) 
	{
		std::cout << err.what();
	}
	return 0;
}
