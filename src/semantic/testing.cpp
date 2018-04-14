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
		cout << "cat is " << i->getName() << endl;
	}

	walk_through_isA(cat);
}

