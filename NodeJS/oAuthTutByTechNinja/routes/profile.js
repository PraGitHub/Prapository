const router = require('express').Router();

const authCheck = function(req, res, next){
  console.log('authCheck :: req.user = ', req.user);
  if(req.user){
    next();
  }else{
    res.redirect('/auth/login');
  }
}

router.get('/', authCheck, function(req, res){
  res.render('profile', {user: req.user});
});

module.exports = router;
