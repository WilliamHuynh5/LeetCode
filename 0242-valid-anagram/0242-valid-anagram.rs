use std::{collections::HashMap};

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }
        let s_vec = s.chars().collect::<Vec<char>>();
        let t_vec = t.chars().collect::<Vec<char>>();
        let mut s_map = HashMap::new();
        let mut t_map = HashMap::new();

        for idx in 0..s.len() {
            *s_map.entry(s_vec[idx]).or_insert(0) +=1;
            *t_map.entry(t_vec[idx]).or_insert(0) +=1;
        }

        println!("{:?}", s_map);
        println!("{:?}", t_map);

        if s_map.eq(&t_map) {
            return true;
        } else {
            return false;
        }
    }
}