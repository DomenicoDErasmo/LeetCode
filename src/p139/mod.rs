use std::collections::HashSet;

struct SolutionDp;

impl SolutionDp {
    pub fn word_break(s: String, word_dict: Vec<String>) -> bool {
        // subproblems: list of indices
        let mut subproblems = vec![false; s.chars().count() + 1];
        subproblems[0] = true;

        let word_set: HashSet<String> = HashSet::from_iter(word_dict);

        for i in 0..=s.chars().count() {
            for j in i..s.chars().count() {
                if subproblems[i] && word_set.contains(&s[i..j + 1]) {
                    subproblems[j + 1] = true;
                }
            }
        }

        *subproblems.last().unwrap()
    }
}

#[test]
fn test_p139_dp() {
    assert!(SolutionDp::word_break(
        "leetcode".to_owned(),
        vec!["leet".to_owned(), "code".to_owned()]
    ));
    assert!(SolutionDp::word_break(
        "applepenapple".to_owned(),
        vec!["apple".to_owned(), "pen".to_owned()]
    ));
    assert!(!SolutionDp::word_break(
        "catsandog".to_owned(),
        vec![
            "cats".to_owned(),
            "dog".to_owned(),
            "sand".to_owned(),
            "and".to_owned(),
            "cat".to_owned()
        ]
    ));
    assert!(SolutionDp::word_break(
        "aaaaaaa".to_owned(),
        vec!["aaaa".to_owned(), "aaa".to_owned(),]
    ));
}
