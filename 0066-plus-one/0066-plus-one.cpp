class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int n = digits.size();
        if(digits[n-1] == 9)
        {
            digits[n-1] = 0;
            carry = 1;
        }
        else{
            digits[n-1] = digits[n-1] + 1;
            return digits;
        }
        for(int i= digits.size()-2;i>=0;i--)
        {
            digits[i] = digits[i] + carry;
            if(digits[i] == 10)
            {
                digits[i] = 0;
                carry = 1;
            }
            else{
                return digits;
            }
        }
        if(carry == 1)
        {
            digits.push_back(1);
            rotate(digits.rbegin(), digits.rbegin() + 1, digits.rend());
        }
        return digits;
    }
};