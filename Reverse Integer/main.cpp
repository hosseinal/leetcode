class Solution {
public:
    int reverse(int x) {

        const unsigned int MAX_SIGNED_INT = (unsigned int)INT_MAX;
        const unsigned int MIN_SIGNED_INT = MAX_SIGNED_INT+1;

        int sign = 1;
        if (x<0) sign = -1;

        x = abs(x);

        int counter = 1;
        long long result = 0;
        while(x!=0){
            
            int d = x%10;
            
            x /= 10;
            
            result = result * 10 + d;

            if (result >= INT_MAX) return 0;
       
        } 

        return static_cast<int>(result) * sign; 
        
    }
};

