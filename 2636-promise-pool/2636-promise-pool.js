/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */
var promisePool = async function(functions, n) {
    return new Promise((resolve) => {
        let inProgressCount = 0;
        let funct = 0;
        function helper(){
            if(funct >= functions.length){
                if (inProgressCount === 0) resolve();
                return;
            }
            while(inProgressCount < n && funct < functions.length){
                inProgressCount++;
                const promise = functions[funct]();
                funct++;
                promise.then(() => {
                    inProgressCount--;
                    helper();
                });
            }
        }
        helper();
    })
};

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */