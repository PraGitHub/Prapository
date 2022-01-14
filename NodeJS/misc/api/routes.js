module.exports = function (router) {
    router.get('/nodejs', (req, res) => {
        console.log('Inside get nodejs');
        res.json({
            author: 'Prashanth',
            messsage: `You have reached ${req.method} ${req.url}`
        });
    });
    router.get('/event_loop', (req, res) => {
        console.log('Inside get event_loop');
        res.json({
            author: 'Prashanth',
            messsage: `You have reached ${req.method} ${req.url}`
        });
    });
    router.post('/nodejs', (req, res) => {
        console.log('Inside post nodejs');
        res.json({
            author: 'Prashanth',
            messsage: `You have reached ${req.method} ${req.url}`
        });
    });
    router.post('/event_loop', (req, res) => {
        console.log('Inside post event_loop');
        res.json({
            author: 'Prashanth',
            messsage: `You have reached ${req.method} ${req.url}`
        });
    });
    router.all('/*', (req, res) => {
        console.log('Inside router all');
        res.json({
            author: 'Prashanth',
            messsage: `You have reached the common api handler ${req.method} ${req.url}`
        });
    });
};
