// without recurssion // time limit exceeded 
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1; 
        if(n == 1) return x; 

        double result = 1;
        long long power = n; // use long long to avoid overflow

        if(power < 0) {
            power = -power;
            for(long long i = 0; i < power; i++) {
                result /= x;
            }
        } else {
            for(long long i = 0; i < power; i++) {
                result *= x;
            }
        }
        return result; 
    }
};


/// recursive method 
class Solution {
public:
    double myPow(double x, long long n) {
        if (n < 0) {
            return 1.0 / myPow(x, -n);
        }
        if(n==0) return 1; 
        if(n==1) return x; 
    
        if(n%2==0) // n is even 
        {
            double even = myPow(x,n/2); 
            return even*even; 

        }
        else {
            // n is odd
            double odd = myPow(x,n/2);
            return x*odd*odd; 
        }
        
    }
};