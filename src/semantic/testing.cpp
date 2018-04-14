#include "semantic/testing.h"


void walk_through_isA(Node* node){
	for(auto i : node->getSubectsByRelation(Relation::IsA)){
		cout << node->getName() << " is a " << i->getName() << endl;
		walk_through_isA(i);
	}
}


void test_semantic_node(){

	Node* object = new Node("Object", Node::Noun);

	Node* animal = new Node("Animal", Node::Noun);

	Relation isA(Relation::IsA);
	Relation hasAttribute(Relation::hasAttribue);

	Node* alive = new Node("Alive", Node::Noun);

	animal->addRelation(object, isA);
	animal->addRelation(alive, hasAttribute);


	Node* cat     = new Node("Cat",    Node::Noun);
	Node* fluffy  = new Node("Fluffy", Node::Adjective);
	Node* pretty  = new Node("Pretty", Node::Adjective);
	Node* pretty2 = new Node("Pretty", Node::Adjective);

	cat->addRelation(animal, isA);
	cat->addRelation(fluffy, hasAttribute);
	// Проерка множества на множество
	cat->addRelation(pretty, hasAttribute);
	cat->addRelation(pretty, hasAttribute);
	cat->addRelation(pretty2, hasAttribute);


	list<Node*> l = cat->getSubectsByRelation(Relation::hasAttribue);
	for(auto i : l){
		cout << "cat is " << i->getName() << " ";
	}

	walk_through_isA(cat);

	cout << "\n*****\nSEMANTIC WEB USING:\n******" << endl;
	SemanticWeb semantic;
	semantic.addNode(object);
	semantic.addNode(animal);
	semantic.addNode(cat);
	semantic.addNode(fluffy);
	semantic.addNode(pretty);
	semantic.addNode(pretty2);
	semantic.addNode(pretty2);
	semantic.addNode(pretty2);

	vt::Node n("Cat");
	if(semantic.getNode(*cat) == NULL){
		cout << " BAD CAT NULL " << endl;
	}
	walk_through_isA(semantic.getNode(n));
	cout << "it's over" << endl;
}

