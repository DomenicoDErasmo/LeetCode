#![allow(dead_code)]

struct Solution {}

impl Solution {
    pub fn dest_city(paths: Vec<Vec<String>>) -> String {
        let sources = paths.iter().map(|path| path[0].clone()).collect::<std::collections::HashSet::<String>>();
        let destinations = paths.iter().map(|path| path[1].clone()).collect::<std::collections::HashSet::<String>>();
        
        match (&destinations - &sources).iter().next() {
            Some(val) => val.clone(),
            None => "".to_owned(),
        }
    }
}