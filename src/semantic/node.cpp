#include "semantic/node.hpp"

Node::Node(std::string name, NodeType type)
	:type(type), name(name)
{
}

Verb::Verb(string name):Node(name, Node::Verb){

}

void Node::addRelation(Node *subject, Relation relation){
	std::pair<Node*,Relation> p(subject, relation);
	subjects.insert(p);
}

std::list<Node*> Node::getSubectsByRelation(Relation::RelationType relation_filter){
	std::list<Node*> result; // Или создать в динамической памяти?

	for(auto i : subjects){
		if(i.second.getType() == relation_filter){
			result.push_back(i.first);
		}
	}

	// Неужели копирование будет происходить каждый раз при возврате из функции?
	return result;
}

bool Node::operator==(const Node &other) const{
	return other.getName() == this->getName();
}

std::string Node::getName() const
{
	return name;
}

void Node::setName(const std::string &value)
{
	name = value;
}



// RELATION
Relation::Relation(RelationType type)
	:type(type){

}

Relation::RelationType Relation::getType() const
{
	return type;
}

void Relation::setType(const RelationType &value)
{
	type = value;
}
// Не отменяет смысла в хранении типа Relation: мы всё ещё можем
// уникализировать каждый экземпляр класса
bool Relation::operator==(const Relation &other) const{
	return other.getType() == this->getType();
}
