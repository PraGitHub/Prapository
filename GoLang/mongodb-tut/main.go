package main

import (
	"log"

	"github.com/globalsign/mgo"
)

const (
	dbUrl = "localhost/go-mongo"
)

var (
	dbSession *mgo.Session
	err       error
)

func printDBNames() {
	dbNames, err := dbSession.DatabaseNames()

	if err != nil {
		log.Fatalln("error while getting DB names, err = ", err)
	}
	for i, dbName := range dbNames {
		log.Println("DB ", i+1, " :: ", dbName)
		printCollectionNames(dbName)
	}
}

func printCollectionNames(dbName string) {
	db := dbSession.DB(dbName)

	if db == nil {
		log.Fatalln("db not found db = ", dbName)
	}

	colNames, err := db.CollectionNames()

	if err != nil {
		log.Fatalln("error while getting collection names from db = ", dbName, " err = ", err)
	}

	for i, colName := range colNames {
		log.Println("\tcollection ", i, " :: ", colName)
		if dbName == "dart" {
			continue
		}
		var docs []map[string]interface{} // same as bson.M
		err := db.C(colName).Find(nil).All(&docs)
		if err != nil {
			log.Fatalln("error while getting docs from collection = ", colName, " err = ", err)
		}
		for i, doc := range docs {
			log.Println("\t \t doc ", i, " :: ", doc)
		}
	}
}

func main() {
	log.SetFlags(log.Ldate | log.Ltime | log.Lmicroseconds)
	dbSession, err = mgo.Dial(dbUrl)

	if err != nil {
		log.Fatalln("error while connecting to db, err = ", err)
	}

	defer dbSession.Close()

	log.Println("Successfully connected to db, URL = ", dbUrl)

	printDBNames()
}
