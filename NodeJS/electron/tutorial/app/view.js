let $ = require('jquery')  // jQuery now loaded and assigned to $
let mongoose = require('mongoose')
let Admin = mongoose.mongo.Admin;
let baseUrl = 'mongodb://localhost:27017/';

function dummy(){
    $('#status').text("dummy");
}

function addDbNamesToList(db) {
    name = db.name;
    size = db.sizeOnDisk +' bytes';
        $('#listOfDbs').append(`<li class="list-group-item">
        <div>
            <a href="#db_`+name+`" data-toggle="collapse" class="btn btn-info btn-block">`+name+`</a>`+
            `<br>
            <div id="db_`+name+`" class="collapse">
                <span class="badge badge-pill badge-dark">`+size+`</span>`+`
            </div>
        </div>
    </li>
    <br>`)
}

function temp(){
    let name = "name";
    let size = "size";
    x = `<li class="list-group-item">
    <div>
        <a href="#db_`+name+`" data-toggle="collapse" class="btn btn-info btn-block">`+name+`</a>`+
        `<br>
        <div id="db_`+name+`" class="collapse">
            <span class="badge badge-pill badge-dark">`+size+`</span>`+`
        </div>
    </div>
</li>
<br>`
$('#status').text(x)

}

function addCollectionNamesToList(dbName, collection){

}

function mongooseData(){ 
   $('#status').text("getting data");
    var connadminDb = mongoose.createConnection( baseUrl+'admin',{useNewUrlParser: true});
    //$('#status').text(connadminDb);
    connadminDb.on('open', function() {
        $('#status').text("connection established");
        var adminDb = new Admin(connadminDb.db);
        adminDb.listDatabases(function(err, result) {
            $('#status').text("database list stored in result.databases");
            var allDatabases = result.databases;    
            for(let i=0;i<allDatabases.length;i++){
                var dbName = allDatabases[i].name;
                addDbNamesToList(allDatabases[i]);
                 $('#status').text("fetching databases")
                //listCollections(dbName);
            }
            $('#status').text("done fetching databases")
            temp();
        });
    });
}

function listCollections(dbName){
    var connDb = mongoose.createConnection( baseUrl+dbName,{useNewUrlParser: true});
    connDb.on('open',function(){
        connDb.db.listCollections().toArray(function(err,collections){
            for(var i=0;i<collections.length;i++){
                $('#status').text("fetching collections")
            }
            $('#status').text("done fetching collections")
        });
    });
}

mongooseData();
