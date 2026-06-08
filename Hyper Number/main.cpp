class Solution {
public:

    int value(int a){

        string stra = to_string(a);
        int sum = 0;

        while(a!=0){
            int digit = a % 10;
            sum+= digit*digit;
            a = a/10;
        }

        return sum;
    }

    bool isHappy(int n) {

        unordered_set<int> finds;

        int val = value(n);

        while(val != 1){ 
            if(finds.count(val)){
                return false;
            }
            finds.insert(val);
            val = value(val);
        }

        return true;
        
    }
};

