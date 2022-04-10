#include <iostream>
#include <vector>
#include <map>
#include <climits>

class IGraph {

public:
	virtual ~IGraph(){};
	IGraph(){};
	IGraph(IGraph *_oth) {};
	virtual void AddEdge(int from, int to){}; // Метод принимает вершины начала и конца ребра и добавляет ребро
	virtual int VerticesCount(){}; // Метод должен считать текущее количество вершин
	virtual void GetNextVertices(int vertex, std::vector<int> &vertices){}; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
	virtual void GetPrevVertices(int vertex, std::vector<int> &vertices){}; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
	void ShowGraph(){};
};

class MatrixGraph: public IGraph
{
private:
	std::map<int, std::vector<int>> neighboringVertices;
public:
	virtual void AddEdge(int from, int to);
	virtual int VerticesCount();
	virtual void GetNextVertices(int vertex, std::vector<int> &vertices);
	virtual void GetPrevVertices(int vertex, std::vector<int> &vertices);

	virtual void ShowGraph();

	MatrixGraph();
	MatrixGraph(IGraph *_oth);
};

class ListGraph: public IGraph
{
private:
	std::map<int, std::vector<int>> neighboringVertices;

public:
	virtual void AddEdge(int from, int to)
	{
		if(from < 0 || to < 0)
		{
			std::cout << "Number of vertices cannot be negative" << std::endl;
			return;
		}
		std::vector<int> vertices_to{to};
		auto it = neighboringVertices.insert(std::make_pair(from, vertices_to));
		if(!it.second)
		{
			it.first->second.push_back(to);
		}
		auto firstIt = neighboringVertices.find(to);
		if(firstIt == neighboringVertices.end())
		{
			neighboringVertices[to] = std::vector<int>();
		}
	}

	virtual int VerticesCount()
	{
		return neighboringVertices.size();
	}

	virtual void GetNextVertices(int vertex, std::vector<int> &vertices)
	{
		auto it = neighboringVertices.find(vertex);
		if ( it != neighboringVertices.end()) {
			for ( auto &verticesList : it->second ) {
				vertices.push_back(verticesList);
			}
		} else {
			std::cout << "Wrong vertices" << std::endl;
		}
	}

	virtual void GetPrevVertices(int vertex, std::vector<int> &vertices)
	{
		auto it = neighboringVertices.find(vertex);
		if(it != neighboringVertices.end())
		{
			for(auto it = neighboringVertices.begin(); it != neighboringVertices.end(); it++)
			{
				for(int i = 0; i < it->second.size(); ++i)
				{
					if(it->second[i] == vertex)
					{
						vertices.push_back(it->second[i]);
					}
				}
			}
		}
		else
		{
			std::cout << "Wrong vertices" << std::endl;
		}
	}

	void ShowGraph()
	{
		for(auto &it : neighboringVertices)
		{
			std::cout << it.first;
			for(auto &verex : it.second)
				std::cout << "->" << verex;

			std::cout<<std::endl;
		}
	}

	ListGraph(){};
	ListGraph(IGraph *oth)
	{
		MatrixGraph* matrix = dynamic_cast<MatrixGraph*>(oth);
		if (matrix)
		{
			std::cout << "Convert matrix to list" << std::endl;
			int vertex_count = matrix->VerticesCount();

			for (int i = 0; i < vertex_count + 1; ++i)
			{
				std::vector<int> vec;
				matrix->GetNextVertices(i, vec);
				if (!vec.empty())
				{
					for (auto &n : vec)
						this->AddEdge(i, n);
				}
				else
				{
					std::vector<int> vec;
					matrix->GetPrevVertices(i, vec);
					if (!vec.empty())
					{
						neighboringVertices[i] = std::vector<int>();
					}
				}
			}
		}
		else
		{
			std::cout << "No convert matrix to list" << std::endl;
		}
	}
};

void MatrixGraph::AddEdge(int from, int to) {
if(from < 0 || to < 0)
	{
		std::cout << "Number of vertices cannot be negative" << std::endl;
		return;
	}
	std::vector<int> vertices_to{to};
	auto it = neighboringVertices.insert(std::make_pair(from, vertices_to));
	if(!it.second)
	{
		it.first->second.push_back(to);
	}
	auto firstIt = neighboringVertices.find(to);
	if(firstIt == neighboringVertices.end())
	{
		neighboringVertices[to] = std::vector<int>();
	}
}

int MatrixGraph::VerticesCount()
{
	return neighboringVertices.size();
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices)
{
	auto it = neighboringVertices.find(vertex);
	if(it != neighboringVertices.end())
	{
		for(auto &verticesList : it->second)
		{
			vertices.push_back(verticesList);
		}
	}
	else
	{
		std::cout << "Wrong vertices" << std::endl;
	}
}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices)
{
	auto it = neighboringVertices.find(vertex);
	if(it != neighboringVertices.end())
	{
		for(auto it = neighboringVertices.begin(); it != neighboringVertices.end(); it++)
		{
			for(int i = 0; i < it->second.size(); ++i)
			{
				if(it->second[i] == vertex)
				{
					vertices.push_back(it->second[i]);
				}
			}
		}
	}
	else
	{
		std::cout << "Wrong vertices" << std::endl;
	}
}

MatrixGraph::MatrixGraph(){};

MatrixGraph::MatrixGraph(IGraph* oth)
{
	ListGraph* list = dynamic_cast<ListGraph*>(oth);
	if(list)
	{
		int vertexCount = list->VerticesCount();
		for(int i = 0; i < vertexCount; i++)
		{
			std::vector<int> vec;
			list->GetNextVertices(i, vec);
			if (vec.size() != 0)
			{
				for (auto &n : vec)
					this->AddEdge(i, n);
			}
			else
			{
				std::vector<int> vec;
				list->GetPrevVertices(i, vec);
				if (vec.size() != 0)
				{
					neighboringVertices[i] = std::vector<int>();
				}
			}
		}
	}
}

void MatrixGraph::ShowGraph()
{   std::cout<<"  ";
	for(int head = 0; head < VerticesCount(); ++head)
		std::cout<<head;
	std::cout << std::endl;

	for(int i = 0; i < VerticesCount(); ++i)
	{
		std::cout << i <<":";
		for(int j = 0; j < VerticesCount(); ++j)
		{
			std::cout<<neighboringVertices[i][j];

		}
		std::cout<<"\n";
	}
	std::cout<<std::endl;
}

int main() {

}
