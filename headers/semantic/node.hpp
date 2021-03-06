#ifndef NODE_HPP
#define NODE_HPP

#include <unordered_map>
#include <list>
#include <string>

using std::string;
namespace vt{

// Тип связи в семантическом графе
class Relation{
public:
	enum RelationType{
		IsA,        // Является
		hasAttribue, // Имеет признак
		can
	};

	Relation(RelationType type);

	RelationType getType() const;
	void setType(const RelationType &value);
	bool operator==(const Relation &other) const;
private:
	RelationType type;
	bool invert;  // Например, чтобы подчеркнуть, что что-то
				  // НИ В КОЕМ СЛУЧАЕ НЕ ЯВЛЯЕТСЯ чем-то
				  // (Остуствие связи значит лишь незивестность)
};

/*
 * Узел семантической сети
 * Объект реального мира или его признак: кошка, дерево,
 * красный, бежать, быстро
 */
class Node
{
public:
	enum NodeType{
		Noun,
		Adjective,
		Verb
	};

	Node(std::string name, NodeType type=NodeType::Noun );
	void addRelation(Node* subject, Relation relation);
	std::list<Node *> getSubectsByRelation(Relation::RelationType relation_filter);

	std::string getName() const;
	void setName(const string &value);

	bool operator==(const Node &other) const;
private:
	std::string name;
	// Хранить отношение или просто ссылку одно из заранее определённых отношений?
	// Храня само отношение, мы можем задать ему уникальные характеристики. Надо ли?
//	std::list<std::pair<Node*,Relation>> subjects; // Субъекты взаимодействия
	// Это хэш-мапа. В списке бы там всё равно пришлось проеврять, есть ли связть с текущим элементом
	// Звёздочка - не лишнее ли? А если та же нода с другим указателем?
	std::unordered_multimap<Node*, Relation > subjects;
	// Множество. Ключ - это строка - название ноды
	// Указатель на каждую ноду хранится только один,
	// но к ней может быть множество отношений
	NodeType type;
//			Стоит ли хранить тип ноды?
//			И если да, то как? Наследование или перечисление?
//			Различать ли нареия и прилагательные?
//		    Не появляется ли дублицирование со связями?
//			Или остаются ли тогда нужными сами связи?
};

// Полезно ограничить иногда
class Verb : public Node{
public:
	Verb(string name);
};
}

using namespace vt;

#endif // NODE_HPP
