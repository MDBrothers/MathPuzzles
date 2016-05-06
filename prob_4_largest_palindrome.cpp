#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <tuple>
#include <algorithm>

using namespace std;

inline int what_is_the_nth_digit(const int candidate, const int n){
  int divided = candidate/pow(10,n);
  divided *= pow(10,n);
  return ((candidate - divided)/pow(10,n-1));
}

inline bool is_m_digit_same_as_n_digit(const int candidate, const int m, const int n){
  return (what_is_the_nth_digit(candidate, m) == what_is_the_nth_digit(candidate, n));
}

inline int how_many_digits(const int candidate){
  for(int numdigits = 1; numdigits < 10; numdigits++){
    if((candidate / int(pow(10, numdigits))) == 0) return numdigits;
  }

  return -999;
}

inline bool is_this_a_palindrome(const int candidate){
  bool is_palindrome = true;
  int num_digits = how_many_digits(candidate);
  for(int comparison = 1; comparison < (num_digits/2 + 1); comparison++){
    is_palindrome = (is_palindrome && (is_m_digit_same_as_n_digit(candidate, comparison, num_digits + 1 - comparison)));
  }

  return is_palindrome;
}

bool comparison_func(tuple<int,int> a, tuple<int,int> b){
  return ( std::get<0>(a)*std::get<1>(a)  >  std::get<0>(b)*std::get<1>(b));
}

int main(){
  int factor_a(1), factor_b(1), b_start(1);

  std::vector<tuple<int, int> > palindrome_factors;

  for(factor_a = 1; factor_a < 1000 ; factor_a++){
    for(factor_b = b_start; factor_b < 1000; factor_b++){
      if(is_this_a_palindrome(factor_a*factor_b)) palindrome_factors.push_back(std::make_tuple(factor_a, factor_b));
    }
    b_start++;
  }

  std::sort( palindrome_factors.begin(), palindrome_factors.end(), comparison_func);

  std::cout << "Greatest palindrome of three digit factors is: " << std::get<0>(palindrome_factors[0]) * std::get<1>(palindrome_factors[0]) << std::endl;
  std::cout << "First digit of 1357: " << what_is_the_nth_digit(1357,1) << std::endl;
  std::cout << "Second digit of 1357: " << what_is_the_nth_digit(1357,2) << std::endl;
  std::cout << "Third digit of 1357: " << what_is_the_nth_digit(1357,3) << std::endl;
  std::cout << "Fourth digit of 1357: " << what_is_the_nth_digit(1357,4) << std::endl;
  std::cout << "is 123321 a palindrome? " << is_this_a_palindrome(123321) << std::endl;
  std::cout << "is 1112311 a palindrome? " << is_this_a_palindrome(1112311) << std::endl;

  return 0;
}
