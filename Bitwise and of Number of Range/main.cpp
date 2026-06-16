class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (left < right) {
            right &= (right - 1);
        }
        return right;
    }
};


class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {

        if (left == right) return left;

        int result = left;
        for(int i = left+1 ; i <= right; i++){
            result = result & i;
        }
        
        return result;
    }
};
