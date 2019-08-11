const fs = require('fs');
const http = require('http');
const {parse} = require('querystring');

const port = 8085;

const server = http.createServer();

const ERROR = 0;
const DIR = 1;
const FILE = 2;

const initHtml = `
<html>
    <head>
        <title>
            HX Machine
        </title>
        <link rel="icon" href="https://upload.wikimedia.org/wikipedia/commons/thumb/2/22/HP-HP9000-C110-Workstation_10.jpg/440px-HP-HP9000-C110-Workstation_10.jpg" type = "image/x-icon"> 
        <link rel="stylesheet" href="//maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
        <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
        <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
    </head>
    <body>
`;

const endHtml = `
    </body>
</html>
`;

const convertToHtml = (data) => {
    data.replace()
    data = data.replace(/&/g, '&amp;');
    data = data.replace(/</g, '&lt;');
    data = data.replace(/>/g, '&gt;');
    data = data.replace(/"/g, '&quot;');
    return data;
}

const getCard = (data) => {
    return `
    <div class="card">
        <div class="card-body">
            <pre>

${data}
            </pre>
        </div>
    </div>
    `;
}

const getNavBar = (dir) => {
    return `
    <header>
        <ul><li></li></ul><br>
        <nav class="navbar navbar-dark bg-dark fixed-top">
            <span class="navbar-brand mb-0 h1"><i class="fa fa-folder-open"></i> ${dir}</span>
        </nav>
    </header>
    `;
}

const getFilePathFormNew = (path, size) => {
    return `
    <div class="form-group">
        <form action="/getfile" method="post">
            <label>
                <span class="badge badge-light">
                    <i class="fa fa-file-text"></i>
                </span>
            </label>
            <label>
                <input class="btn btn-dark" value="${path.substr(path.lastIndexOf('/')+1)}" readonly/>
            </label>
            <label>
                <span class="badge badge-light">
                    ${size} bytes
                </span>
            </label>
            <input class="form-control" name="filepath" type="text" value="${path}" hidden />
            <button class="btn btn-light" data-toggle="tooltip" data-placement="top" title="View" type="submit">
                <i class="fa fa-eye"></i>
            </button>
            <button class="btn btn-light" data-toggle="tooltip" data-placement="top" title="Download" type="submit" formaction="/downloadfile">
                <i class="fa fa-download"></i>
            </button>
        </form>
    </div>
    `;
}

const getFilePathForm = (path, size) => {
    return `
    <div class="form-group">
        <form action="/getfile" method="post">
            <label>
                <span class="badge badge-light">
                    <i class="fa fa-file-text"></i>
                </span>
            </label>
            <input class="form-control" name="filepath" type="text" value="${path}" hidden />
            <input class="btn btn-dark" type="submit" value="${path.substr(path.lastIndexOf('/')+1)}" />
            <label>
                <span class="badge badge-light">
                    ${size} bytes
                </span>
            </label>
        </form>
        <form action="/downloadfile" method="post">
            <input class="form-control" name="filepath" type="text" value="${path}" hidden />
            <a class="btn btn-dark" type="submit"><i class="fa fa-download"></i></a>
        </form>
    </div>
    `;
}

const getDirPathForm = (path) => {
    return `
    <div class="form-group">
        <form action="/getdir" method="post">
            <label>
                <span class="badge badge-light">
                    <i class="fa fa-folder"></i>
                </span>
            </label>
            <input class="form-control" name="dirpath" type="text" value="${path}" hidden />
            <button class="btn btn-dark" type="submit" data-toggle="tooltip" data-placement="top" title="Open">
                ${path.substr(path.lastIndexOf('/')+1)}
            </button>
            <!--<input class="btn btn-dark" type="submit" data-toggle="tooltip" data-placement="top" title="Open" value="${path.substr(path.lastIndexOf('/')+1)}" />-->
        </form>
    </div>
    `;
}

const whatsThisPath = (filepath) => {
    var attr = {
        type: ERROR,
        size: null
    };
    if(fs.existsSync(filepath)){
        var stat = fs.statSync(filepath);
        if(stat.isDirectory()){
            attr.type = DIR;
        }else{
            attr.type = FILE;
            attr.size = stat.size;
        }
    }
    return attr;
}

/*
const getDirTreeSync = (dir) => {
    var tree = {};
    const files = fs.readdirSync(dir);
    files.forEach((file) => {
        const filepath = dir + '/' + file;
        if(whatsThisPath(filepath) == DIR){
            tree[file] = getDirTreeSync(filepath);
        }else if(whatsThisPath(filepath) == FILE){
            tree[file] = null;
        }else;
    });
    return tree;
}
*/

const getDirTreeFormSync = (dir) => {
    var response = '';
    response = initHtml;
    response += getNavBar(dir);
    response += '<section><ul class="list-group">';
    const files = fs.readdirSync(dir);
    files.forEach((file) => {
        if(dir.lastIndexOf('/') != dir.length-1){
            dir = dir + '/';
        }
        const filepath = dir + file;
        const pathAttr = whatsThisPath(filepath);
        if(pathAttr.type == DIR){
            response += '<li class="list-group-item list-group-item-secondary">' + getDirPathForm(filepath) + '</li>';
            //console.log('filepath = ', filepath, 'is a directory');
        }else if(pathAttr.type == FILE){
            response += '<li class="list-group-item list-group-item-secondary">' + getFilePathFormNew(filepath, pathAttr.size) + '</li>';
            //console.log('filepath = ', filepath, 'is a file');
        }else;
    });
    response += '</ul></section>' + endHtml;
    return response;
}

server.listen(port, (err) => {
    if(err){
        throw err;
    }
    console.log('server is running @ ', port);
});

server.on('request', (req, res) => {
    const method = req.method;
    const url = req.url;
    //console.log(method, url);
    if(method == 'GET'){
        res.writeHeader(200, {'Content-Type' : 'text/html'});
        res.write(getDirTreeFormSync('/'));
        res.end();
    }else if(method == 'POST'){
        if(url == '/getfile'){
            let formData = '';
            req.on('data', (chunk) => {
                formData = formData + chunk.toString();
            });
            req.on('end', () => {
                let path = parse(formData)['filepath'];
                //console.log('filepath = ', path);
                res.writeHeader(200, {'Content-Type' : 'text/html'});
                res.write(initHtml);
                res.write(getNavBar(path));
                fs.readFile(path, (err, data) => {
                    if(err){
                        res.write('<section>' + getCard(err.stack) + '</section>');
                        //res.write(err.stack);
                    }else{
                        res.write('<section>' + getCard(convertToHtml(data.toString())) + '</section>');
                    }
                    res.write(endHtml);
                    res.end();
                });
            });
        }else if(url == '/getdir'){
            let formData = '';
            req.on('data', (chunk) => {
                formData = formData + chunk.toString();
            });
            req.on('end', () => {
                let path = parse(formData)['dirpath'];
                //console.log('dirpath = ', path);
                res.writeHeader(200, {'Content-Type' : 'text/html'});
                res.write(getDirTreeFormSync(path));
                res.end();
            });
        }else if(url == '/downloadfile'){
            let formData = '';
            req.on('data', (chunk) => {
                formData = formData + chunk.toString();
            });
            req.on('end', () => {
                let path = parse(formData)['filepath'];
                res.setHeader('Content-Disposition', 'attachment; filename=' + path.substr(path.lastIndexOf('/')+1));
                fs.createReadStream(path).pipe(res);
            });
        }else{
            res.writeHeader(200, {'Content-Type' : 'text/html'});
            res.write(getDirTreeFormSync('/'));
            res.end();
        }
    }else{
        res.writeHeader(200, {'Content-Type' : 'text/html'});
        res.write(getDirTreeFormSync('/'));
        res.end();
    }
});
