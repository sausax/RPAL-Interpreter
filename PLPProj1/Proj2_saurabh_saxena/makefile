# Make file for PLPProj1

p2 : FileReader.o LexicalAnalyzer.o PLPProj1.o RecursiveParser.o Stack.o Token.o TreeNode.o CSEMachine.o TreeTransformer.o
	g++ -o p2 FileReader.o LexicalAnalyzer.o PLPProj1.o RecursiveParser.o Stack.o Token.o TreeNode.o CSEMachine.o TreeTransformer.o

CSEMachine.o: CSEMachine.cpp CSEMachine.h Token.h TreeNode.h
	g++ -c CSEMachine.cpp

TreeTransformer.o: TreeTransformer.cpp TreeTransformer.h TreeNode.h
	g++ -c TreeTransformer.cpp

FileReader.o : FileReader.cpp FileReader.h
	g++ -c FileReader.cpp
	
LexicalAnalyzer.o : LexicalAnalyzer.cpp LexicalAnalyzer.h Token.h
	g++ -c LexicalAnalyzer.cpp

PLPProj1.o : PLPProj1.cpp FileReader.h LexicalAnalyzer.h RecursiveParser.h
	g++ -c PLPProj1.cpp

RecursiveParser.o : RecursiveParser.cpp RecursiveParser.h Token.h
	g++ -c RecursiveParser.cpp

Stack.o : Stack.cpp Stack.h
	g++ -c Stack.cpp

Token.o : Token.cpp Token.h
	g++ -c Token.cpp

TreeNode.o : TreeNode.cpp TreeNode.h
	g++ -c TreeNode.cpp

run :
	./p2

test :
	perl testDir/difftest.pl -1 "testDir/rpal -ast FILE" -2 "./p2 -ast FILE" -t testDir/tests/

cl :
	rm *.o p2
