var mongoose = require('mongoose');
var Admin = mongoose.mongo.Admin;
var baseUrl = 'mongodb://localhost:27017/';


function mongooseData(){
    /// create a connection to the DB    
    var connadminDb = mongoose.createConnection( baseUrl+'admin',{useNewUrlParser: true});
    connadminDb.on('open', function() {
        // connection established
        var adminDb = new Admin(connadminDb.db);
        adminDb.listDatabases(function(err, result) {
            console.log('listDatabases succeeded');
            // database list stored in result.databases
            var allDatabases = result.databases;    
            for(let i=0;i<allDatabases.length;i++){
                var dbName = allDatabases[i].name;
                //console.log("dbName :: ",dbName);
                listCollections(dbName);
            }
        });
    });
}

function listCollections(dbName){
    var connDb = mongoose.createConnection( baseUrl+dbName,{useNewUrlParser: true});
    connDb.on('open',function(){
        connDb.db.listCollections().toArray(function(err,collections){
            console.log("dbName :: ",dbName);
            console.log("collections :: ");
            for(var i=0;i<collections.length;i++){
                console.log(collections[i].name)
            }
        });
    });
}

mongooseData();