# /bin/bash 

docker-compose build
docker-compose up -d mongo
docker-compose up -d app
docker-compose up -d client
