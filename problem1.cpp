//projecteuler.net problem 1
//If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
//The sum of these multiples is 23.
//Find the sum of all the multiples of 3 or 5 below 1000.
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

int main(int argc, char ** argv){
	const long long unsigned int three(3);
	const long long unsigned int five(5);
	long long unsigned int sum(0);

	std::string boundString(argv[argc -1]); 
	std::stringstream str(boundString); 
	long long unsigned int bound;  
	str >> bound;  
	if (!str) 
	{      
		std::cout << "The conversion failed." << std::endl;
  } 
	else
		std::cout << "Upper bound is: " << bound << std::endl;

	std::vector<long long unsigned int> unfiltered;
	std::vector<long long unsigned int> filtered_for_threes;
	std::vector<long long unsigned int> filtered_for_fives;
	std::vector<long long unsigned int> multiples;
	
	unfiltered.reserve(bound);
	filtered_for_threes.reserve(bound);
	filtered_for_fives.reserve(bound);
	multiples.reserve(bound);

	for(long long unsigned int n = 0 ; n < bound; ++n){
		unfiltered.push_back(n);
		filtered_for_threes.push_back(n%three);
		filtered_for_fives.push_back(n%five);
	}

	std::vector<long long unsigned int>::iterator t = filtered_for_threes.begin();
	std::vector<long long unsigned int>::iterator f = filtered_for_fives.begin();
	for(std::vector<long long unsigned int>::iterator n = unfiltered.begin(); n != unfiltered.end(); ++n, ++t, ++f){
		if(	*t == 0)
			multiples.push_back(*n);
		else if(*f == 0)
			multiples.push_back(*n);
		else
			asm("nop");
	}

	for(std::vector<long long unsigned int>::iterator m = multiples.begin(); m != multiples.end(); ++m){
		sum += *m;	
	}

	std::cout << "The solution is: " << sum << std::endl;

	return 0;
}
