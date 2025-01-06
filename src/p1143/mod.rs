struct SolutionRecursive;

impl SolutionRecursive {
    fn helper(
        text1: &String,
        text2: &String,
        text1_pos: usize,
        text2_pos: usize,
    ) -> i32 {
        if text1_pos == text1.chars().count()
            || text2_pos == text2.chars().count()
        {
            return 0;
        }

        let match_both = if text1.chars().nth(text1_pos).unwrap()
            == text2.chars().nth(text2_pos).unwrap()
        {
            1 + SolutionRecursive::helper(
                text1,
                text2,
                text1_pos + 1,
                text2_pos + 1,
            )
        } else {
            0
        };

        let increment_left =
            SolutionRecursive::helper(text1, text2, text1_pos + 1, text2_pos);
        let increrment_right =
            SolutionRecursive::helper(text1, text2, text1_pos, text2_pos + 1);

        let choices = [match_both, increment_left, increrment_right];
        *choices.iter().max().unwrap()
    }

    pub fn longest_common_subsequence(text1: String, text2: String) -> i32 {
        SolutionRecursive::helper(&text1, &text2, 0, 0)
    }
}

struct SolutionDp;
impl SolutionDp {
    pub fn longest_common_subsequence(text1: String, text2: String) -> i32 {
        let text1_len = text1.chars().count();
        let text2_len = text2.chars().count();
        let mut subproblems = vec![vec![0; text2_len + 1]; text1_len + 1];

        for (i, c1) in text1.chars().enumerate() {
            for (j, c2) in text2.chars().enumerate() {
                subproblems[i + 1][j + 1] = if c1 == c2 {
                    1 + subproblems[i][j]
                } else {
                    subproblems[i][j + 1].max(subproblems[i + 1][j])
                };
            }
        }

        subproblems[text1_len][text2_len]
    }
}

#[test]
fn test_p1143_recursive() {
    assert_eq!(
        SolutionRecursive::longest_common_subsequence(
            "abcde".to_owned(),
            "ace".to_owned()
        ),
        3
    );
}

#[test]
fn test_p1143_dp() {
    assert_eq!(
        SolutionDp::longest_common_subsequence(
            "abcde".to_owned(),
            "ace".to_owned()
        ),
        3
    );
    assert_eq!(
        SolutionDp::longest_common_subsequence(
            "bl".to_owned(),
            "yby".to_owned()
        ),
        1
    );
    assert_eq!(
        SolutionDp::longest_common_subsequence(
            "ezupkr".to_owned(),
            "ubmrapg".to_owned()
        ),
        2
    );
    assert_eq!(
        SolutionDp::longest_common_subsequence(
            "bsbininm".to_owned(),
            "jmjkbkjkv".to_owned()
        ),
        1
    );
}
