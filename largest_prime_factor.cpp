#include<cmath>
#include<vector>
#include<iostream>

unsigned long long num_ops;

bool is_a_factor(const unsigned long long factor, const unsigned long long product){
  num_ops += 3;
  return (((product/factor)*factor)==product);
}

bool is_prime(const unsigned long long number){
  unsigned long long divisor(2);
  while(true){
    // Every nonzero is its own divisor
    if(divisor == number) break;
    //If the number has a factor of 2 or greater it is not prime
    if(is_a_factor(divisor, number)){
      return false;
    }
    num_ops++;
    divisor++;
  }

  num_ops ++;
  // No factors, this number is prime
  return true;
}

int main(){
  unsigned long long original = 600851475143;
  unsigned long long changed = original;
  unsigned long long factor(2);

  num_ops = 0;

  std::vector<unsigned long long> prime_factors;

  while(true){
    if(is_a_factor(factor, changed)){
      if(is_prime(factor)){
        num_ops +=2;
        changed /= factor;
        prime_factors.push_back(factor);
      }
      else{
        num_ops++;
        factor ++;
      }
    }
    else{
      num_ops++;
      factor ++;
    }
    if(changed == 1) break;
  }

  num_ops ++;

  for(const auto & elm : prime_factors) std::cout << elm << std::endl;

  std::cout << "NUM OPS: " << num_ops << std::endl;
}
