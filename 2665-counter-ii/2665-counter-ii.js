/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let current_val = init
    return {
        increment : function(){
            current_val = current_val + 1;
            return current_val;
        },
        decrement : function(){
            current_val = current_val - 1;
            return current_val;
        },
        reset : function(){
            current_val = init;
            return current_val;
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */