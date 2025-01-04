struct Solution;

impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        let type_casted_coins = coins
            .iter()
            .map(|coin| *coin as usize)
            .collect::<Vec<usize>>();
        let upper_bound = usize::try_from(amount + 1).unwrap();
        let mut result = vec![-1; upper_bound];
        result[0] = 0;
        for i in 1..upper_bound {
            let mut subproblem = vec![];
            for coin in &type_casted_coins {
                if i < *coin {
                    continue;
                }
                let prev_problem = i - *coin;
                if result[prev_problem] < 0 {
                    continue;
                }

                subproblem.push(1 + result[prev_problem]);
            }
            result[i] = *subproblem.iter().min().unwrap_or(&-1);
        }

        *result.last().unwrap()
    }
}

#[test]
fn test_p322_dp() {
    assert_eq!(Solution::coin_change(vec![1, 2, 5], 11), 3);
    assert_eq!(Solution::coin_change(vec![1, 2, 5], 100), 20);
    assert_eq!(Solution::coin_change(vec![2], 3), -1);
    assert_eq!(Solution::coin_change(vec![1], 0), 0);
}
