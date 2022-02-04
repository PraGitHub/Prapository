// Problem: https://www.hackerrank.com/challenges/candies/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dynamic-programming

function candies(n, arr) {
    // Write your code here
    if (n == 1) return 1;
    if (n == 2) {
        if (arr[1] > arr[0]) {
            return 3;
        }
        return 2;
    }
    let candies = new Array(n).fill(1, 0, n);
    for (let i = 1; i < n;) {
        if (arr[i] > arr[i - 1]) {
            if (candies[i] <= candies[i - 1]) {
                candies[i] += 1;
            } else {
                i++;
            }
        } else if (arr[i] < arr[i - 1]) {
            if (candies[i - 1] <= candies[i]) {
                candies[i - 1] += 1;
                if (i > 1) i--;
            } else {
                i++;
            }
        } else {
            i++;
        }
    }
    console.log(candies);
    let sum = candies.reduce((a, b) => a + b, 0);
    return sum;
}