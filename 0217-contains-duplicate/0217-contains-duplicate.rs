impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut mut_nums = nums.clone();
        mut_nums.sort();
        for idx in 0..mut_nums.len() - 1 {
            if mut_nums[idx] == mut_nums[idx + 1] {
                return true;
            };
        }
        false
    }
}