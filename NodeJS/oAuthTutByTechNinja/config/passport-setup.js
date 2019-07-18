const passport = require('passport');
const GoogleStrategy = require('passport-google-oauth20');
const keys = require('./keys');
const User = require('../models/user');

passport.serializeUser(function(user, done){
  done(null, user.id);
});

passport.deserializeUser(function(id, done){
  User.findById(id).then(function(userRecord){
    if(userRecord){
      done(null, userRecord);
    }else{
      done('error', null);
    }
  })
});

passport.use(
  new GoogleStrategy({
    //options for strategy
    callbackURL:'/auth/google/redirect',
    clientID:keys.google.clientID,
    clientSecret:keys.google.clientSecret
  },
  function(accessToken, refreshToken, profile, done){
    //passport callback function
    console.log('passport callback function => (accessToken, refreshToken, profile, done) => {} is fired');
    console.log('profile = ', profile);
    User.findOne({
      googleId:profile.id
    }).then(function(userRecord){
      if(userRecord){
        //user exists
        console.log('user exists, user = ', userRecord);
        done(null, userRecord); // this will call passport.serializeUser
      }else{
        //user not found
        //so create a new userRecord
        new User({
          username: profile.displayName,
          googleId: profile.id,
          thumbnail: profile._json.picture
        }).save().then(function(newUserRecord){
          console.log('new user created = ', newUserRecord);
          done(null, newUserRecord); // this will call passport.serializeUser
        });
      }
    })
    //done();
  })
);
