#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

template <class T> class graph
{
private:
	std::map<T, std::vector<T>> _map;
public:
	graph() {
		std::vector<T> v;
		_map[0] = v;
	}

	~graph() {}

	template <typename ...ArgsT>
	void addConnection(T from, ArgsT... to) {
		std::vector<T> const leafs {to...};
		if (!_map.count(from)) {
			_map[from] = leafs;
		}
		else {
			for (auto v : leafs) {
				_map[from].push_back(v);
			}
		}
		for (auto v : leafs) {
			_map[v].push_back(from);
		}
	}

	void addConnection(T from, std::vector<T> to) {
		if (!_map.count(from)) {
			_map[from] = to;
		}
		else {
			for (auto v : to) {
				_map[from].push_back(v);
			}
		}
		for (auto v : to) {
			_map[v].push_back(from);
		}
	}

	void printAdjacencyList() {
		std::cout << "----------" << std::endl;
		for (auto kvp : _map) {
			std::cout << "Node " << kvp.first << ": [";

			for (auto v : kvp.second) {
				std::cout << v << ", ";
			}
			std::cout << "]" << std::endl;
		}
	}

	std::vector<std::vector<T>> findCollections() {
		std::vector<T> visited_nodes;
		std::vector<T> collection;
		std::vector<std::vector<T>> collections;
		std::vector<T> nodes_to_visit;
		nodes_to_visit.push_back(0);
		for (auto i=0; i<nodes_to_visit.size(); ++i) {
			auto n = nodes_to_visit.at(i);
			if (std::find(visited_nodes.begin(), visited_nodes.end(), n) == visited_nodes.end()) {
				visited_nodes.push_back(n);
				collection.push_back(n);
				for (auto v : _map[n]) {
					nodes_to_visit.push_back(v);
				}
			}
			if (i == nodes_to_visit.size() - 1) {
				std::cout << "# elements in collection: " << collection.size() << std::endl;
				for (auto v : collection) {
					std::cout << v << std::endl;
				}
				collections.push_back(collection);
				collection.clear();
				std::sort(visited_nodes.begin(), visited_nodes.end());
				auto prev = visited_nodes[0];
				auto j = 1;
				for (j=1; j<visited_nodes.size(); ++j) {
					if (visited_nodes[j] == prev + 1) {
						prev = visited_nodes[j];
					}
					else {
						std::cout << "Missing node: " << prev + 1 << std::endl;
						nodes_to_visit.push_back(prev + 1);
						break;
					}
				}
				if ((j == visited_nodes.size()) && (j < _map.size())) {
					nodes_to_visit.push_back(visited_nodes.at(visited_nodes.size() - 1) + 1);
				}
			}
		}
		return collections;
	}

	int size() {
		return _map.size();
	}

};

int main(int argc, char const *argv[])
{
	graph<int> g;
	g.addConnection(0, {1, 2});
	g.addConnection(1, 4);
	g.addConnection(2, 4);
	g.addConnection(4, 5);
	g.addConnection(3, 6);
	g.addConnection(7);
	g.printAdjacencyList();

	auto a = g.findCollections();
	// std::cout << a[0][0] << std::endl;
	std::cout << "Number of nodes: " << g.size() << std::endl;

	return 0;
}
