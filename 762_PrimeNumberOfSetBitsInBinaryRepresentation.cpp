/*
762. Prime Number of Set Bits in Binary Representation
Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) having a prime number of set bits in their binary representation.

(Recall that the number of set bits an integer has is the number of 1s present when written in binary. For example, 21 written in binary is 10101 which has 3 set bits. Also, 1 is not a prime.)

Example 1:

Input: L = 6, R = 10
Output: 4
Explanation:
6 -> 110 (2 set bits, 2 is prime)
7 -> 111 (3 set bits, 3 is prime)
9 -> 1001 (2 set bits , 2 is prime)
10->1010 (2 set bits , 2 is prime)
Example 2:

Input: L = 10, R = 15
Output: 5
Explanation:
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)
Note:

L, R will be integers L <= R in the range [1, 10^6].
R - L will be at most 10000.
*/

/*class Solution {
private :
    bool prime[100005];

    void SieveOfEratosthenes(void){
            // Create a boolean array "prime[0..n]" and initialize
            // all entries it as true. A value in prime[i] will
            // finally be false if i is Not a prime, else true.
            memset(prime, true, sizeof(prime));
            prime[0]=prime[1]=false;
            for (int p=2; p*p<1e5+5; p++)
            {
                // If prime[p] is not changed, then it is a prime
                if (prime[p] == true)
                {
                    // Update all multiples of p
                    for (int i=p*2; i<1e5+5; i += p)
                        prime[i] = false;
                }
            }

        }
public:
    int countPrimeSetBits(int L, int R) {
        int cnt = 0;
        SieveOfEratosthenes();
        for(int i=L; i<=R; ++i){
            if(prime[__builtin_popcount(i)]){
                
                ++cnt;
            }
        }
       return cnt; 
    }
};*/


/*
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int cnt = 0;
        int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
        for(int i=L; i<=R; ++i){
            if(binary_search(primes, primes+18, __builtin_popcount(i))){
                
                ++cnt;
            }
        }
       return cnt; 
    }
};*/



/*
//Version#3 ::
class Solution {
public:
    
    bool isPrime(int num) {
        if (num==1){
            return false;
        }
        for (int i=2; i*i<=num; ++i)
            if (num % i == 0){
                return false;
            }
        return true;
    }
    
    int countPrimeSetBits(int L, int R) {
        int ans = 0;
        for (int num=L; num<=R; ++num){
            int cnt = 0;
            int x = num;
            while(x){
                cnt += x&1;
                x >>= 1;
            }
            if (isPrime(cnt)){
                ++ans;
            }
        }
        return ans;
    }
};*/


/*
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int cnt = 0;
        static set<int> primes{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
        for(int i=L; i<=R; ++i){
            if(primes.count(__builtin_popcount(i))){
                ++cnt;
            }
        }
       return cnt; 
    }
};*/

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        unordered_set<int> primes{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
        int ans = 0;
        for(int i = L; i <= R; ++i){
            int t = i;
            int cnt = 0;
            while(t) cnt += t & 1, t >>= 1;
            ans += primes.count(cnt);
        }
        return ans;
    }
};