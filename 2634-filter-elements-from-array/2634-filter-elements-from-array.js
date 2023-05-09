/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    newArr = []
    for(const i in arr){
        if(fn(parseInt(arr[i]), parseInt(i)))
            newArr.push(arr[i])
    }
    return newArr
};