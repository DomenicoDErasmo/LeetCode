struct SolutionRecursive;

impl SolutionRecursive {
    fn recurse(nums: &Vec<i32>, current_index: usize, current_max: i32) -> i32 {
        let Some(current_value) = nums.get(current_index) else {
            return 0;
        };
        let next_index = current_index + 1;
        let pick = if *current_value > current_max {
            1 + SolutionRecursive::recurse(nums, next_index, *current_value)
        } else {
            i32::MIN
        };

        let skip = SolutionRecursive::recurse(nums, next_index, current_max);

        pick.max(skip)
    }

    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        SolutionRecursive::recurse(&nums, 0, i32::MIN)
    }
}

#[test]
fn test_p300_recurse() {
    assert_eq!(
        SolutionRecursive::length_of_lis(vec![10, 9, 2, 5, 3, 7, 101, 18]),
        4
    );
}

struct SolutionDp;

// TODO: fix
impl SolutionDp {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let mut result = vec![1; nums.len()];

        for i in 0..nums.len() {
            for j in 0..=i {
                if nums[i] > nums[j] {
                    result[i] = result[i].max(result[j] + 1);
                }
            }
        }

        *result.iter().max().unwrap()
    }
}

#[test]
fn test_p300_dp() {
    assert_eq!(
        SolutionDp::length_of_lis(vec![10, 9, 2, 5, 3, 7, 101, 18]),
        4
    );
}
