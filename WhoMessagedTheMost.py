"""
N is number of messages
Following 'N' will be 'N' lines containing name and message separated by space

def WhoMessagedTheMost:
    iMaxCount = 0;
    listOfNames = []
    dictNameCount = {}
    for i in range(N):
        read name and message as strCurrentName and strMessage
        if strName not in dictNameCount
            dictNameCount[strName] = 0
        iCurrentCount = dictNameCount[strName] = dictNameCount[strName] + 1
        if iCurrentCount > iMaxCount:
            iMaxCount = iCurrentCount
            listOfNames = []
            listOfNames.append(strName)
        else if iCurrentCount == iMaxCount
            if strName is not in listOfNames:
                listOfNames.append(strName)
        else
            do nothing

"""