var productModel = require('../models/product');
var mongoose = require('mongoose');
mongoose.connect('mongodb://localhost:27017/shopping');

var products = [
    new productModel({
    imagePath:'https://image2.geekbuying.com/ggo_pic/2018-12-26/20181226018661279yhr1.jpg',
    title:'Honor View 20',
    description:'First ever phone with 7mn chipset to release. First smartphone to have link turbo technology.',
    price:37000
}),
new productModel({
    imagePath:'https://i.gadgets360cdn.com/products/large/1551344229_635_redmi_note_7_pro.jpg?downsize=770:*&output-quality=70&output-format=webp',
    title:'Redmi Note 7 Pro',
    description:'48 MP Primary Cam. SD 675.',
    price:13999
}),
new productModel({
    imagePath:'https://drop.ndtv.com/TECH/product_database/images/104201774316PM_635_google_pixel_2.jpeg?downsize=770:*&output-quality=70&output-format=webp',
    title:'Google Pixel 2',
    description:'From Google !',
    price:49999
}),
new productModel({
    imagePath:'https://www.gizmochina.com/wp-content/uploads/2018/12/Huawei-nova-4-Standard-version-600x600.jpg',
    title:'Huawei Nova 4i',
    description:'One of the coolest huawei phones. Worth every paisa.',
    price:13999
}),
new productModel({
    imagePath:'https://i.gadgets360cdn.com/products/large/1543923025_635_asus_zenfone_max_pro_m2_winfuture.jpg?downsize=770:*&output-quality=70&output-format=webp',
    title:'ASUS Zenphone Max Pro M2',
    description:'12 MP Sony cam. Awesome battery backup. Gorilla glass body.',
    price:12999
}),
new productModel({
    imagePath:'https://i.gadgets360cdn.com/products/large/1532062010_635_nokia61plus_db.jpg?downsize=770:*&output-quality=70&output-format=webp',
    title:'Nokia 6.1 Plus',
    description:'16 + 5 MP Rear Cam. SD 632.',
    price:14999
})
];

var done = 0;

for (var i=0;i<products.length;i++){
    products[i].save(function(err,res){
        if(err){
            console.log('Erroe while saving :: ');
            throw err;
        }
        done++;
        if(done === products.length){
           disconnect();
        }
    });
}

function disconnect(){
    console.log("Disconnecting ...");
    mongoose.disconnect();
    console.log('Disconnected');
}