let MongoClient = require('mongodb').MongoClient;
let url = "mongodb://localhost:27017/";
let $ = require('jquery')  

function getData(){
    MongoClient.connect(url,  {useNewUrlParser: true}, function(err, db) {
    if (err) throw err;
    let dbo = db.db("CodeReviewSystem");
    dbo.collection("Users").find({}).toArray(function(err, result) {
            if (err) throw err;
            for (let i=0;i<result.length;i++){
                addUserToList(result[i].username)
            // addUserToList1(result[i].username) // to test
            }
            $('#status').text("done fetching")
            db.close();
        });
    }); 
}

$('#loadDb').on('click', () => {
    // $('#status').text("calling getData");
     getData(); 
     //$('#status').text("called getData");
  }) 

//to test
function addUserToList1(name){
    console.log(name)
}

function addUserToList(userName) {
   $('#status').text("fetching")
    $('#listOfUsers').append('<li><div><alert class="alert alert-info">'+userName +'</alert></div></li><br>')
}

