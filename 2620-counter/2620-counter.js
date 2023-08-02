/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    var count = 0;
    return function() {
        if (count === 0) {
            count+=1;
            return n;
        } else {
            n+=1;
            count+=1;
            return n;
        }
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */