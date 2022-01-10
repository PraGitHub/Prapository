function getFirstThreeMinMax (arr) {
    if (arr.length < 3) {
        return;
    }

    let min1 = min2 = min3 = arr[0];
    let max1 = max2 = max3 = arr[0];

    for (let n of arr) {
        if (n <= min1) {
            min3 = min2;
            min2 = min1;
            min1 = n;
        } else if (n <= min2) {
            min3 = min2;
            min2 = n;
        } else if (n <= min3) {
            min3 = n;
        }
        if (n >= max1) {
            max3 = max2;
            max2 = max1;
            max1 = n;
        } else if (n >= max2) {
            max3 = max2;
            max2 = n;
        } else if (n >= max3) {
            max3 = n;
        }
    }
    return {
        min: [min1, min2, min3],
        max: [max1, max2, max3]
    };
}

const arr = [31, 324, 5435, 22, 456, 1, 10, 100, 83, 1995, 25, 9, 12345];

let result = getFirstThreeMinMax(
    arr
);

console.log(result);