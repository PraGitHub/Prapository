
var MongoClient = require('mongodb').MongoClient;
var Db = require('mongodb').Db;
var Server = require('mongodb').Server;


function getData(){
    var db = new Db('test', new Server('localhost', 27017));
    // Establish connection to db
    db.open(function(err, db) {

    // Use the admin database for the operation
    var adminDb = db.admin();

    // List all the available databases
    adminDb.listDatabases(function(err, result) {
            for(var i=0;i<result.databases.length;i++){
                addDbNames(result.databases[i]) // to test
                //assDbNamesToList(result.databases[i])
            }
            db.close();
        });
    });
}

//to test
function addDbNames(name){
    console.log(name)
}

function addDbNamesToList(db) {
    name = db.name;
    size = db.sizeOnDisk + 'bytes';
   $('#status').text("fetching")
    $('#listOfDbs').append('<li><div><alert class="alert alert-info">'+name+' ; '+size +'</alert></div></li><br>')
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
            }
        });
    });
}
