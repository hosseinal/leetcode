class Solution {
public:

    int get_carry(int a, int b, int c) {
        if ((a > 0 && b > 0) || 
            (a > 0 && c > 0) || 
            (b > 0 && c > 0)) {
            return 1;
        } else {
            return 0;
        }
    }

    int getSum(int a, int b) {
        int carry = 0; 
        unsigned int res = 0;

        for (int i = 0; i < 32; i++) {
            int a_bit = (a >> i) & 1;
            int b_bit = (b >> i) & 1;

            int cur_bit = a_bit ^ b_bit ^ carry;

            int new_carry = get_carry(a_bit, b_bit, carry);
            carry = new_carry;

            if (cur_bit) {
                res |= (1u << i);
            }
        }

        return static_cast<int>(res);
    }
};
