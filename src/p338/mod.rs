struct Solution {}

impl Solution {
    fn hamming_weight(mut n: i32) -> i32 {
        let mut result = 0;
        while n > 0 {
            result += n & 1;
            n >>= 1;
        }
        result
    }

    pub fn count_bits(n: i32) -> Vec<i32> {
        (0..=n)
            .map(|i| Solution::hamming_weight(i))
            .collect::<Vec<i32>>()
    }
}

#[test]
fn test_p338() {
    assert_eq!(Solution::count_bits(5), vec![0, 1, 1, 2, 1, 2])
}
