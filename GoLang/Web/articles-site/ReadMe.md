I followed this tutorial to build => https://semaphoreci.com/community/tutorials/building-go-web-applications-and-microservices-using-gin
 
command to build:
  "go build main.go router.go models.articles.go handlers.articles.go handlers.user.go"
  
run "main.exe" and look for port "8080" in your browser. ( http://localhost:8080" )

If you want to change the port then edit main.go accoudingly.
  change required : router.Run() => router.Run(":number") where 'number' is any valid port number
