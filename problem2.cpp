//projecteuler.net problem 2
//Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
//
//1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
//
//By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

int main(int argc, char ** argv){
	const unsigned int fourMill(4000000);
	unsigned int sum(0);

	std::vector<unsigned int> fibonacciTerms;

	fibonacciTerms.reserve(100);
	fibonacciTerms.push_back(1);
	fibonacciTerms.push_back(2);

	int n = 2;
	do{
		fibonacciTerms.push_back(fibonacciTerms[n-1] + fibonacciTerms[n-2]);
		std::cout << fibonacciTerms[n] << std::endl;
		++n;
	} while (fibonacciTerms[n-1] < fourMill);
	fibonacciTerms.pop_back();

	for(std::vector<unsigned int>::iterator it = fibonacciTerms.begin(); it != fibonacciTerms.end(); ++ it){
		if(*it % 2 == 0){
			sum += *it;
		}
	}

	std::cout << "The sum is: " << sum << std::endl;

	


	return 0;
}
