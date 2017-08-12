#2009 contest senior ccc
import io
import math
import sys
class allQuestions(object):
    def question1(self):
        range1=input()
        range2=input()
        numcool=0
        for i in range(int(range1),int(range2)):
            self.currentNum=i
            if math.sqrt(i).is_integer()==True and self.evaluate(0)==1:
                numcool=numcool+1
        print (numcool)

    def evaluate(self, input):
        input=input+1
        if math.pow(input,3)<self.currentNum:
            return self.evaluate(input)
        elif math.pow(input,3)==self.currentNum:
            return 1
        else: 
            return 0
    def question2(self):
        self.numRows=input()
        self.numCols=input()
        #for storing numbers 
        self.allNums=[[0 for i in range(int(self.numCols))]]*int(self.numRows)
        for i in range(int(self.numRows)):
            currentLine=input()
            counter=0
            for t in currentLine:
                if t!=' ':
                    self.allNums[i][counter//2]=t
                    counter=counter+2

        tempVal=self.allNums
        allLast=[]
        for m in range(int(self.numRows)-1):     
            self.recursiveSol(m)
            currentVal=[]
            for g in range (int(self.numCols)):
                  currentVal.append(self.allNums[0][g])
            if currentVal not in allLast:                 
                  allLast.append([currentVal])
            self.allNums=tempVal
        #print response +1 for default case
        print (len(allLast)+1)

    def recursiveSol(self, m):
        if m==-1:
            return
        else:
             self.switchNums(m)
             return self.recursiveSol(m-1)

    def switchNums(self, m):
         for i in range (int(self.numCols)):
             if self.allNums[m+1][i]==self.allNums[m][i]:
                 self.allNums[m][i]=0
             else:
                 if self.allNums[m+1]==1:
                     self.allNums[m]=0
    def question3(self):
        self.allRelationships=[[1,6],[6,2],[6,3],[6,4],[6,5],[6,7],[7,8],[8,9],[9,10],[9,12],[10,11],[11,12],[12,13],[13,14],[13,15],[3,15],[16,18],[16,17],[17,18]]
        command='t'
        while command!='q':
            command = input()
            self.callHandler(command)
        sys.exit()
    def callHandler(self,command):
       
        if command=='i' or command =='d':
            firstPerson=int(input())
            secondPerson=int(input())
            if ([firstPerson,secondPerson] or [secondPerson,firstPerson] not in self.allRelationships ) and command=='i':
                self.allRelationships.append([firstPerson,secondPerson])
            elif [firstPerson,secondPerson] in self.allRelationships and command=='d':
                self.allRelationships.remove([firstPerson,secondPerson])
            elif [secondPerson,firstPerson] in self.allRelationships and command=='d':
                self.allRelationships.remove([secondPerson,firstPerson])
            print (self.allRelationships)
        elif command=='n':
            desiredSearch=int(input())
            numFriends=0
            for r in self.allRelationships:
                if r[0]==desiredSearch or r[1]==desiredSearch:
                    numFriends=numFriends+1
            print(numFriends)
        elif command=='f':
            f=int(input())
            allFriends=[]
            for r in self.allRelationships:
                if r[0] is f:
                    allFriends.append(r[1])
                elif r[1] is f:
                    allFriends.append(r[0])
            numFofF=0
            for t in allFriends:
                for r in self.allRelationships:
                    if t is r[0]:
                        if r[1] is not f and r[1] not in allFriends:
                            numFofF=numFofF+1
                    elif t is r[1]:
                        if r[0] is not f and r[0] not in allFriends:
                            numFofF=numFofF+1
            print (numFofF)
        elif command=='s':
            dOfS=[]
            startingPerson=int(input())
            finalPerson=int(input())
            stopper=False
            while stopper==False:



class codingchallenges(object):
    def q1(self):
        numIterations=int(input())
        for i in range (numIterations):
        #init duply method
            currentNum=int(input())
            currentLine=input()   
            counter=0
            factor=len(currentLine)//2
            if currentNum%2!=0:
                factor=len(currentLine)//2+1
            for t in range(factor):
                  if currentLine[t]==currentLine[len(currentLine)-t-1]:
                        counter=counter+1
            
            if counter==currentNum:
                  print ("yes")
            else: 
                  print ("no")
            
questions=allQuestions()
questions.question3()
"""
codingChallenge=codingchallenges()
codingChallenge.q1()
"""
