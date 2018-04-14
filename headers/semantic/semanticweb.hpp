#ifndef SEMANTICWEB_H
#define SEMANTICWEB_H

#include <unordered_set>
#include "node.hpp"

using std::unordered_set;
using std::string;
/*
 * Семантическая сеть:
 * из неё мы можем быстро получить доступ к желаемому объекту сети
 */
namespace vt {


class myhash {
public:
   size_t operator() (const Node* val) const {
	  return std::hash<std::string>()(val->getName());
   }
};

class myequal {
public:
   bool operator()(const Node *val1, const Node *val2) const{
	  return val1->getName() == val2->getName();
   }
};


class SemanticWeb
{
public:
	SemanticWeb();
	Node* getNode(Node  node); // Получаем указатель из любого значения!
	void  addNode(Node* node);
private:
	unordered_set<Node*, myhash, myequal> nodes;
};

}
#endif // SEMANTICWEB_H
