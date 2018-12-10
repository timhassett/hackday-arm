// C++ program to print all primes smaller than or equal to 
// n using Sieve of Eratosthenes 
#include <bits/stdc++.h> 
#include <iostream>
#include <time.h>
#include <math.h> 

using namespace std; 
  
void SieveOfEratosthenes(long long n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (long long p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p 
            for (long long i=p*2; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
  //  for (int p=2; p<=n; p++) 
    //   if (prime[p]) 
      //    cout << p << " "; 
} 
  
// Driver Program to test above function 
int main() 
{ 
    long long n = 1000000; 
    cout << "Following are the prime numbers smaller "
         << " than or equal to " << n << endl; 

    clock_t t1,t2;
    t1=clock();
    SieveOfEratosthenes(n);
    t2=clock();
    float diff = ((float)t2-(float)t1)/CLOCKS_PER_SEC;
    cout << "Running time: " << diff << endl; 
    return 0; 
} 



