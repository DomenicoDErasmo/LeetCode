class Solution {
    public:
     int reverseBits(int n) {
         int result = 0;
         for (int i = 0; i < 31; i++) {
             result |= (n & 1);
             n >>= 1;
             result <<= 1;
         }
         result |= (n & 1);
         return result;
     }
 };