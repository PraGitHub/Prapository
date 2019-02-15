var fs = require('fs');
var array = [];
var lines = fs.readFileSync('input').toString().split("\r\n");
//console.log(lines);

function quickSort(origArray) {
    //console.log("quickSort :: origArray = ",origArray)
	if (origArray.length <= 1) { 
		return origArray;
	} else {

		var left = [];
		var right = [];
		var newArray = [];
        //var pivot = origArray.pop();
        var length = origArray.length;
        var pivot_index = Math.floor(Math.random() * (length-1));
        var pivot = origArray[pivot_index];

		for (var i = 0; i < length; i++) {
            if(i == pivot_index){
                continue;
            }
			if (origArray[i] <= pivot) {
				left.push(origArray[i]);
			} else {
				right.push(origArray[i]);
			}
		}

		return newArray.concat(quickSort(left),pivot, quickSort(right));
	}
}

function swap(arr, first_Index, second_Index){
    var temp = arr[first_Index];
    arr[first_Index] = arr[second_Index];
    arr[second_Index] = temp;
}

function bubbleSort(arr){

    var len = arr.length,
        i, j, stop;

    for (i=0; i < len; i++){
        for (j=0, stop=len-i; j < stop; j++){
            if (arr[j] > arr[j+1]){
                swap(arr, j, j+1);
            }
        }
    }

    return arr;
}

for(var i in lines) {
    var numbers = lines[i].split(" ");
    for(var j in numbers){
        array.push(parseInt(numbers[j]));
    }
}   

//console.log("array :: ",array);

console.log("n = ",array.length)

console.log("before calling quick sort",new Date()," ",Date.now());

var quickSortedArray = quickSort(array);

console.log("after calling quick sort",new Date()," ",Date.now());

console.log("before calling bubble sort",new Date()," ",Date.now());

var bubbleSortedArray = bubbleSort(array);

console.log("after calling bubble sort",new Date()," ",Date.now());

fs.writeFileSync("nodeoutput_quickSort",quickSortedArray);

fs.writeFileSync("nodeoutput_bubbleSort",bubbleSortedArray);
