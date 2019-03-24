var express = require('express');
var Cart = require('../models/cart');
var csrf = require('csurf');
var router = express.Router();


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
    res.render('shop/index', { products:productChunks });
  });
});

router.get('/add-to-cart/:id',function(req,res,next){
  var productId = req.params.id;
  var cart = new Cart(req.session.cart ? req.session.cart : {});

  Product.findById(productId,function(err,product){
    if(err){
      return res.redirect('/');
    }
    cart.add(product,product.id);
    req.session.cart = cart;
    console.log('cart :: ',req.session.cart);
    res.redirect('/');
  });
});

router.get('/shopping-cart',function(req,res,next){
  if(!req.session.cart){
    return res.render('shop/shopping-cart',{products:null});
  }
  var cart = new Cart(req.session.cart);
  res.render('shop/shopping-cart',{products:cart.generateArray(), totalPrice:cart.totalPrice});
});

router.get('/remove-one/:id',function(req,res,next){
  if(!req.session.cart){
    return res.render('shop/shopping-cart',{products:null});
  }
  var cart = new Cart(req.session.cart);
  cart.removeOne(req.params.id);
  res.render('shop/shopping-cart',{products:cart.generateArray(), totalPrice:cart.totalPrice});
});

router.get('/remove/:id',function(req,res,next){
  if(!req.session.cart){
    return res.render('shop/shopping-cart',{products:null});
  }
  var cart = new Cart(req.session.cart);
  cart.remove(req.params.id);
  res.render('shop/shopping-cart',{products:cart.generateArray(), totalPrice:cart.totalPrice});
});

router.get('/checkout',function(req,res,next){
  if(!req.session.cart){
    return res.redirect('/shopping-cart');
  }
  var cart = new Cart(req.session.cart);
  res.render('shop/checkout',{total:cart.totalPrice,noError:true});
});

router.post('/checkout',function(req,res,next){

});

module.exports = router;
