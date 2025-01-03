struct Solution;

impl Solution {
    pub fn climb_stairs_recursive(n: i32) -> i32 {
        if n <= 1 {
            return 1;
        }

        Solution::climb_stairs_recursive(n - 1)
            + Solution::climb_stairs_recursive(n - 2)
    }

    pub fn climb_stairs_dp(n: i32) -> i32 {
        if n == 1 {
            return 1;
        }
        let mut table = vec![0; n as usize];
        table[0] = 1;
        table[1] = 2;
        for i in 2..table.len() {
            table[i] = table[i - 1] + table[i - 2];
        }

        *table.last().unwrap()
    }
}

#[test]
fn test_p70_recursive() {
    assert_eq!(Solution::climb_stairs_recursive(5), 8);
}

#[test]
fn test_p70_dp() {
    assert_eq!(Solution::climb_stairs_dp(5), 8);
}
