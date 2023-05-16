struct MinStack {
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
        let last = self.stack.last();
        
        match last {
            Some(min) => {
                if val >= min.1 {
                    self.stack.push((val, min.1));
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