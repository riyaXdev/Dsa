class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){  // loop until carry becomes 0
            int carry = a & b;
            carry = carry << 1;
            a = a ^ b; // sum without carry
            b = carry; // use b to store carry
        }
        return a;
    }
};