struct MinStack {
    // Vec of tuples, where each tuple contains:
    // 0. The actual value pushed to the stack
    // 1. The current minimum value relative to when the actual value was pushed
    stack: Vec<(i32, i32)>,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MinStack {

    fn new() -> Self {
        MinStack {
            stack: Vec::new(),
        }
    }
    
    fn push(&mut self, val: i32) {
        
        // Get the last value in the stack
        let last = self.stack.last();
        
        match last {
            Some(min) => {
                // If the val is greater than the current min,
                // then just push the val, and the current min
                if val >= min.1 {
                    self.stack.push((val, min.1));
                // If the val is less than the current min,
                // push the val, and the val as the new current min
                } else {
                    self.stack.push((val, val));
                }
            },
            None => self.stack.push((val, val)),
        }
    }
    
    fn pop(&mut self) {
        self.stack.pop();
    }
    
    fn top(&self) -> i32 {
        self.stack.last().unwrap().0
    }
    
    fn get_min(&self) -> i32 {
        self.stack.last().unwrap().1
    }
    
}