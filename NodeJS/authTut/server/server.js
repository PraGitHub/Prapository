const express = require('express');
const uuid = require('uuid/v4');
const session = require('express-session');
const fileStore = require('session-file-store')(session);
const bodyParser = require('body-parser');
const passport = require('passport');
const localStrategy = require('passport-local').Strategy;

const port = 8085;
const users = [
	{id : 'prashanh', email : 'prashanthhn2509@gmail.com', password : 'password'},
	{id : 'prashanh1', email : 'prashanthhn2509@gmail.com', password : 'password'},
	{id : 'prashanh2', email : 'prashanthhn2509@gmail.com', password : 'password'},
	{id : 'prashanh3', email : 'prashanthhn2509@gmail.com', password : 'password'},
	{id : 'prashanh4', email : 'prashanthhn2509@gmail.com', password : 'password'}
];

function findUser(id, password){
	for(var i in users){
		if(users[i].id === id && users[i].password === password){
			return {result: true, data: users[i]};
		}
	}
	return {result: false, data: {}};
}

function findUserById(id){
	for(var i in users){
	        if(users[i].id === id){
	                return {result: true, data: users[i]};
	        }
	}
	return {result: false, data: {}};
}

// confi1gure passport.js to use the local strategy
passport.use(new localStrategy(
	{ usernameField : 'id' },
	function(id, password, done){
		console.log('localStrategy callback');
		// here is where you make a call to the database
		// to find the user based on their username or email address
		// for now, we'll just pretend we found that it was users[0]
		const result = findUser(id, password);
		if(result.result == true){
			user = result.data;
			return done(null, user);
		}
		return done({message: 'user not found'}, null);
	}
));

// tell passport how to serialize the user
passport.serializeUser(function(user, done){
	console.log('serializer function :: userid will be saved to the session file store here');
	done(null, user.id);
});

passport.deserializeUser(function(id, done){
	console.log('deserializeUser :: user id = ', id);
	result = findUserById(id);
	if(result.result == true){
		var user = result.data;
		done(null, user);
	}
	else{
		done({message: 'user not found'}, null);
	}
});

const app = express();

app.use(bodyParser.urlencoded({extended : false}));
app.use(bodyParser.json());
app.use(session({
	genid : function(req){
		console.log('genid fucntion :: begin');
		console.log('genid function :: req.sessionID = ', req.sessionID);
		var uniqueId = uuid();
		console.log('genid function :: uniqueId = ', uniqueId);
		console.log('genid fucntion :: end');
		return uniqueId;
	},
	store : new fileStore(),
	secret : 'auth tut secret',
	resave : false,
	saveUninitialized : true
}));
app.use(passport.initialize());
app.use(passport.session());

app.listen(port, function(err){
	if(err) throw err;
	console.log('Server is listening on port ',port);
});

app.get('/', function(req, res){
	console.log('get request handler :: req.sessionID = ',req.sessionID);
	res.json({
		server : 'authTut Server',
		message : 'Welcome !',
		session_id : req.sessionID
	});
});

app.get('/login', function(req, res){
	console.log('get login :: req.sessionId = ', req.sessionId);
	res.json({
		server : 'authTut Server',
		message : 'Log in page.',
		session_id : req.sessionID
	});
});

app.post('/login', function(req, res, next){
	console.log('post login :: req.body = ', req.body);
	func = passport.authenticate('local', function(err, user, info){
		console.log('passport authenticate callback begin');
		console.log('req.session.passport = ', req.session.passport);
		console.log('req.user = ', req.user);
		req.login(user, function(err){
			console.log('req.login callback begin');
			console.log('req.session.passport = ', req.session.passport);
			console.log('req.user = ', req.user);
			console.log('req.login callback end');
			return res.json({
				server: 'authTut Server',
				message: 'Logged in !'
			});
		});
		console.log('passport authenticate callback end');
	});
	func(req, res, next);
});

app.get('/authrequired', function(req, res){
	var authResult = req.isAuthenticated();
	console.log('get authrequired callback :: user authenticated ? = ', authResult);
	if(authResult){
		res.json({
			server: 'authTut Server',
			message: '/authrequired :: you are authorised.'
		});
	}
	else{
		res.json({
			server: 'authTut Server',
			message: '/authrequired :: you are not authorised.'
		});
	}
});
