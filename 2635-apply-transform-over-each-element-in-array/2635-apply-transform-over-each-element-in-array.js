/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    newArr = []
    for(const i in arr){
        newArr.push(fn(parseInt(arr[i]), parseInt(i)))
    }
    return newArr
};