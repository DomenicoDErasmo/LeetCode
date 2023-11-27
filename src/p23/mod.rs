#![allow(dead_code)]
#![allow(unused)]

struct MergeLists {}

#[derive(PartialEq, Eq, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

#[allow(dead_code)]
impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { val, next: None, }
    }
}

impl MergeLists {
    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        
        None
    }
}

#[cfg(test)]
pub mod p23_tests {
    use crate::p23::{ListNode, MergeLists};

    #[test]
    fn leetcode_test_one() {
        // most sane linked list initialization
        let expected = ListNode {
            val: 1,
            next: Some(Box::new(ListNode {
                val: 1,
                next: Some(Box::new(ListNode {
                    val: 2,
                    next: Some(Box::new(ListNode {
                        val: 3,
                        next: Some(Box::new(ListNode {
                            val: 4,
                            next: Some(Box::new(ListNode {
                                val: 4,
                                next: Some(Box::new(ListNode {
                                    val: 5,
                                    next: Some(Box::new(ListNode {
                                        val: 6,
                                        next: None,
                                    }))
                                }))
                            }))
                        }))
                    }))
                }))
            }))
        };

        let actual = *MergeLists::merge_k_lists(vec![
            Some(
                Box::new(
                    ListNode {
                        val: 1,
                        next: Some(
                            Box::new(
                                ListNode {
                                    val: 4,
                                    next: Some(
                                        Box::new(
                                            ListNode {
                                                val: 5,
                                                next: None,
                                            }
                                        )
                                    )
                                }
                            )
                        ),
                    }
                ),
            ), Some(
                Box::new(
                    ListNode {
                        val: 1,
                        next: Some(
                            Box::new(
                                ListNode {
                                    val: 3,
                                    next: Some(
                                        Box::new(
                                            ListNode {
                                                val: 4,
                                                next: None,
                                            }
                                        )
                                    )
                                }
                            )
                        ),
                    }
                ),
            ), Some(
                Box::new(
                    ListNode {
                        val: 2,
                        next: Some(
                            Box::new(
                                ListNode {
                                    val: 6,
                                    next: None,
                                }
                            )
                        ),
                    }
                ),
            )
        ]).unwrap();

        assert_eq!(expected, actual);
    }
}