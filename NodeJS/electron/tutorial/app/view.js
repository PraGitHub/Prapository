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

 mongooseData();


 $('#loadCollection').on('click', () => {
    // $('#status').text("calling getData");
    
     //$('#status').text("called getData");
  }) 

 //////////////////////////////////////////////////////////////////////////////

 function getDbDetails(dbName){

 }

 function addDbNamesToList(db) {
    name = db.name;
    size = db.sizeOnDisk +' bytes';
        $('#listOfDbs').append(`<li class="list-group-item">
            <div class="row">
                <div class = "col">
                    <button onclick="getDbDetails(`+name+`)" class="btn btn-info">`+name+`</button>`+
                `</div>`+
                `<div class = "col">
                    <span class="badge badge-pill badge-dark">`+size+`</span>`+
                `</div>
            </div>
        </li>
    <br>`)
}

function mongooseData(){
    var mongoose = require('mongoose')
    , Admin = mongoose.mongo.Admin;

    /// create a connection to the DB    
    var connection = mongoose.createConnection(
        'mongodb://localhost:27017/admin',{useNewUrlParser: true});
    connection.on('open', function() {
        // connection established
        var adminDb = new Admin(connection.db);
        adminDb.listDatabases(function(err, result) {
            console.log('listDatabases succeeded');
            // database list stored in result.databases
            var allDatabases = result.databases;    
            //console.log(allDatabases); to test
            for (var i=0;i<allDatabases.length;i++){
                addDbNamesToList(allDatabases[i]);
                $('#status').text("fetching")
            }
            $('#status').text("done fetching")
        });
    });
}

