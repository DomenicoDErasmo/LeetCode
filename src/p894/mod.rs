use std::{rc::Rc, cell::RefCell, collections::HashMap};

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode { 
            val, 
            left: None, 
            right: None, 
        }
    }
}

pub struct Solution{}

impl Solution {
    pub fn all_possible_fbt(n: i32) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
        if n % 2 == 0 {
            return vec![];
        }
        let mut cache = HashMap::<i32, Vec<Option<Rc<RefCell<TreeNode>>>>>::new();
        cache.insert(1, vec![Some(Rc::new(RefCell::new(TreeNode::new(0))))]);
        Self::helper(n, &mut cache)
    }

    fn helper(remaining_nodes: i32, cache: &mut HashMap<i32, Vec<Option<Rc<RefCell<TreeNode>>>>>) -> Vec<Option<Rc<RefCell<TreeNode>>>> {

        match cache.get(&remaining_nodes) {
            Some(stored) => stored.clone(),
            None => {
                let mut result = vec![];
                for i in (1..=remaining_nodes-2).step_by(2) {
                    let raw_left = Self::helper(i, cache);
                    let lefts = raw_left.iter().cloned();
                    let raw_right = Self::helper(remaining_nodes - i - 1, cache);
                    let rights = raw_right.iter().cloned();
                    let cross = lefts
                        .flat_map(|left| 
                            rights
                            .clone()
                            .map(move |right| 
                                (right.clone(), left.clone())));
                    for (left, right) in cross.into_iter() {
                        let node = Rc::new(RefCell::new(TreeNode::new(0)));
                        node.try_borrow_mut().unwrap().left = left;
                        node.try_borrow_mut().unwrap().right = right;
                        result.push(Some(node));
                    }
                }
                cache.insert(remaining_nodes, result.clone());
                result
            }
        }
    }
}

#[cfg(test)]
mod p894_tests {
    use super::*;
    #[test]
    fn test_all_possible_fbt() {

    }
}