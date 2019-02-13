var fs = require('fs');
var array = [];
var lines = fs.readFileSync('input').toString().split("\r\n");
//console.log(lines);

function quickSort(origArray) {
	if (origArray.length <= 1) { 
		return origArray;
	} else {

		var left = [];
		var right = [];
		var newArray = [];
		var pivot = origArray.pop();
		var length = origArray.length;

		for (var i = 0; i < length; i++) {
			if (origArray[i] <= pivot) {
				left.push(origArray[i]);
			} else {
				right.push(origArray[i]);
			}
		}

		return newArray.concat(quickSort(left), pivot, quickSort(right));
	}
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

array = quickSort(array);

console.log("after calling quick sort",new Date()," ",Date.now());

fs.writeFileSync("nodeoutput",array);