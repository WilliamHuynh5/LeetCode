type ReturnObj = {
    increment: () => number,
    decrement: () => number,
    reset: () => number,
}

function createCounter(init: number): ReturnObj {
	let val = init || 0;
    
    const increment = function() {
        val++;
        return val;
    }
    const decrement = function() {
        val--;
        return val;
    }
    const reset = function() {
        val = init;
        return val;
    }
    
    return {increment, decrement, reset};
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */