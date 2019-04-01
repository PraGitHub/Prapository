let $ = require('jquery')  // jQuery now loaded and assigned to $
let count = 0
$('#click-counter').text(count.toString())
$('#plusButton').on('click', () => {
   count ++ 
   $('#click-counter').text(count)
}) 
$('#minusButton').on('click', () => {
    count --
    $('#click-counter').text(count)
 }) 
 