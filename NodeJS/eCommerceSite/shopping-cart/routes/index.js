var express = require('express');
var router = express.Router();
var csrf = require('csurf');

var Product = require('../models/product');

var csrfProtection = csrf();
router.use(csrfProtection);

/* GET home page. */
router.get('/', function(req, res, next) {
  Product.find(function(err,docs){
    var productChunks = [];
    var chunkSize = 3;
    for(var i=0;i<docs.length;i=i+3){
      productChunks.push(docs.slice(i,i+chunkSize));
    }
    res.render('./shop/index', { products:productChunks });
  });
});

module.exports = router;
