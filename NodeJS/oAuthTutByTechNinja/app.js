const express = require('express');
const mongoose = require('mongoose');
const cookieSession = require('cookie-session');
const passport = require('passport');

const authRouter = require('./routes/auth');
const profileRouter = require('./routes/profile');

const passportSetup = require('./config/passport-setup');
const keys = require('./config/keys');

const port = 3000;

//connect to mLab mongoDb
mongoose.connect(
  keys.mongoDb.dbURI,
  { useNewUrlParser: true },
  function(err){
    if(err) {
      console.log('Error while connecting to database');
      throw err;
    }
    console.log('Connected to mLab MongoDb');
  }
);

//app
const app = express();

//set view engine
app.set('view engine', 'ejs');

//configure cookie
app.use(cookieSession({
  maxAge: 24*60*60*1000,
  keys: [keys.session.cookieKey]
}));

//initialize passport
app.use(passport.initialize());
app.use(passport.session());

//set routes
app.use('/auth', authRouter);
app.use('/profile', profileRouter);

//start server
app.listen(port, function(err){
  if(err){
    console.log('Error while starting the server');
    throw err;
  }
  console.log('server is running at ',port);
});

//homepage
app.get('/', function(req, res){
  res.render('home', {user: req.user});
});
