//============================================================================
// Name        : PLPProj1.cpp
// Author      : Saurabh Saxena
// UFID        : 21817195
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "FileReader.h"
#include "LexicalAnalyzer.h"
#include "RecursiveParser.h"
#include "TreeTransformer.h"
#include "TreeNode.h"
#include "CSEMachine.h"

using namespace std;


void preOrder(TreeNode* t, std::string dots);
void formattedPrint(Token t,std::string dots);
void computeResult(int argc,char** argv);

int main(int argc,char** argv) {
	//cout << "Total num of arguments "<< argc<<endl;
	if(argc == 2){
		computeResult(argc,argv);
		return 0;
	}
	bool astFound = false;
	for(int i=0;i<argc;i++){
		//cout <<argv[i]<<endl;
		if(strcmp(argv[i],"-ast") == 0){
			astFound = true;
			break;
		}
	}
	if(astFound == true){
		FileReader fr(argv[argc-1]);
		string fileContent = fr.getFileContent();
		if(fileContent.size() == 0)
			return 0;
		LexicalAnalyzer la(fileContent);
		RecursiveParser rp(la);
		rp.parse();
		//rp.printTree();
	    //Delete all the trees to clear up the memory


		TreeNode* root = rp.getTree();
		//cout << root->value.type;
		preOrder(root, "");
		//cout<<endl;
		TreeTransformer transformer;
		TreeNode* transformedRoot = transformer.transformTree(root);

		//cout << "Tree transformation done "<<endl;
		//preOrder(transformedRoot,"");
		CSEMachine machine(transformedRoot);
		machine.evaluateTree();
		//cout << "CSE machine evaluation done "<< endl;
		//delete root;
		//delete transformedRoot;

	}else{
		//cout<< "Usage: p1 -ast fileLocation"<<endl;
	}
	return 0;
}

void computeResult(int argc,char** argv){
	//cout<< "Inside compute"<<endl;
	FileReader fr(argv[argc-1]);
	string fileContent = fr.getFileContent();
	if(fileContent.size() == 0)
		return;
	LexicalAnalyzer la(fileContent);
	RecursiveParser rp(la);
	rp.parse();
	//cout<< "Parsing done"<<endl;
	TreeNode* root = rp.getTree();
	TreeTransformer transformer;
	TreeNode* transformedRoot = transformer.transformTree(root);
	//cout<< "Transformation done"<<endl;
	CSEMachine machine(transformedRoot);
	machine.evaluateTree();
	//cout << "Evaluation done"<<endl;
}


void preOrder(TreeNode* t, std::string dots){
	formattedPrint(t->value,dots);
	string dots1 = "." + dots;
	if(t->left != NULL)
		preOrder(t->left,dots1);
	if(t->right != NULL)
		preOrder(t->right,dots);
}

void formattedPrint(Token t,std::string dots){
	if(t.type == "IDENTIFIER"){
		cout <<dots<<"<ID:"<< t.value<<'>'<<endl;
	}else if(t.type == "INTEGER"){
		cout <<dots<<"<INT:"<< t.value<<'>'<<endl;
	}else if(t.type == "STRING"){
		cout << dots<<"<STR:"<<t.value<<'>'<<endl;
	}else if(t.value == "true" or t.value == "false" or t.value == "nil" or t.value== "dummy"){
		cout << dots<<'<'<<t.value<<'>'<<endl;
	}else{
		cout <<dots<<t.value<<endl;
	}
}

