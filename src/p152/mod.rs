struct Solution;

impl Solution {
    pub fn max_product(nums: Vec<i32>) -> i32 {
        let mut result = i32::MIN;

        let mut max_product = 1;
        let mut min_product = 1;

        for num in nums {
            if num < 0 {
                (max_product, min_product) = (min_product, max_product);
            }
            max_product = i32::max(max_product * num, num);
            min_product = i32::min(min_product * num, num);
            result = result.max(max_product);
        }

        result
    }
}

#[test]
fn test_p152() {
    assert_eq!(Solution::max_product(vec![2, 3, -2, 4]), 6);
    assert_eq!(Solution::max_product(vec![-2, 0, -1]), 0);
    assert_eq!(Solution::max_product(vec![3, -1, 4]), 4);
    assert_eq!(Solution::max_product(vec![3, -1, 4, -2]), 24);
    assert_eq!(Solution::max_product(vec![2, -5, -2, -4, 3]), 24);
}
