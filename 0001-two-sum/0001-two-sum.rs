use std::{collections::HashMap};

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = HashMap::new();

        for i in 0..nums.len() {
            map.insert(nums[i], i);
        }

        for i in 0..nums.len() {
            let val = target - nums[i];
            if map.contains_key(&val) {
                if i == *map.get(&val).unwrap() as usize {
                    continue;
                }
                return vec![i as i32, *map.get(&val).unwrap() as i32];
            }
        }

        return [].to_vec();
    }
}