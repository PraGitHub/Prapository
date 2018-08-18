import pymongo

def GetTheDictToInsert():
    dictToReturn = {}
    JobIDArray = ["JOB.ID.1","JOB.ID.2","JOB.ID.3"]
    TimeStampArray = ["1234","1235","1236"]
    KeyArray = ["Key1","Key2","Key3"]
    ValueArray = ["Value1","Value2","Value3"]
    for JOBID in JobIDArray:
        dictJobID = {}
        iCount = 0
        for TimeStamp in TimeStampArray:
            dictTimeStamp = {}
            for Key in KeyArray:
                dictTimeStamp[Key] = ValueArray[iCount]
            dictJobID[TimeStamp] = dictTimeStamp
            iCount = iCount + 1
        dictToReturn[JOBID] = dictJobID
    return dictToReturn


strDBName = "PraDBObject2"

strCollectionName = "CrosswordData"

MongoClient = pymongo.MongoClient("mongodb://localhost:27017/")

DBObj = MongoClient[strDBName]

DBList = MongoClient.list_database_names()

CollectionList = DBObj.list_collection_names()

print(DBList)

if strDBName in DBList:
    print(strDBName,"exists")
else:
    print(strDBName,"does not exist")

print(CollectionList)

if strCollectionName in  CollectionList:
    print(strCollectionName,"exists in",strDBName)
else:
    print(strCollectionName,"does not exist in",strDBName)

"""
Create a collection
newcollection = dbobject["collection name"] - that's it. so simple

"""

strNewCollectionName = "TempColPy1"

CollectionObj = DBObj[strNewCollectionName]

print(DBObj.list_collection_names())

dictToInsert = GetTheDictToInsert()

print('dictToInsert = ',dictToInsert)

"""
dictInsertRetVal = CollectionObj.insert_one(dictToInsert)

This does not work if any of the  key contain "." or "$" characters

So we need to use CollectionObj.insert(dict,check_keys=False)

This will allow us to store any json/dict with keys containing "." or "$" characters

"""

dictInsertRetVal = CollectionObj.insert(dictToInsert,check_keys = False)

print('dictInsertRetVal = ',dictInsertRetVal)


