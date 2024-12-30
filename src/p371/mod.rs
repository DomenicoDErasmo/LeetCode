struct Solution {}

impl Solution {
    pub fn get_sum(a: i32, b: i32) -> i32 {
        let mut a_copy = a;
        let mut b_copy = b;

        // Iterate till there is no carry
        while b_copy != 0 {
            // carry contains common set bits of a and b, left shifted by 1
            let carry = (a_copy & b_copy) << 1;

            // Update a with (a + b without carry)
            a_copy ^= b_copy;

            // Update b with carry
            b_copy = carry;
        }
        a_copy
    }
}

#[test]
fn test_p371() {
    assert_eq!(Solution::get_sum(-1, -2), -3);
}
