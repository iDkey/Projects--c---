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
	virtual void ShowGraph(IGraph* iGraph){};
};

class MatrixGraph: public IGraph
{
private:
	std::map<int, std::vector<int>> neighboringVertices;
	int countV = 0;

public:
	virtual void AddEdge(int from, int to);
	virtual int VerticesCount();
	virtual void GetNextVertices(int vertex, std::vector<int> &vertices);
	virtual void GetPrevVertices(int vertex, std::vector<int> &vertices);

	virtual void ShowGraph(IGraph* iGraph);

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

	virtual void ShowGraph(IGraph* listGraph)
	{
		for(auto it : neighboringVertices)
		{
			std::cout << it.first << ": ";
			for(auto vert : it.second)
			{
				std::cout << vert << " ";
			}
			std::cout << std::endl;
		}
	}

	ListGraph(){};
	ListGraph(IGraph *oth)
	{
		MatrixGraph* matrix = dynamic_cast<MatrixGraph*>(oth);
		if (matrix)
		{
			std::cout << "Convert matrix to list";
			int vertex_count = matrix->VerticesCount();
			for (int i = 0; i < vertex_count; ++i)
			{
				std::vector<int> vec;
				matrix->GetNextVertices(i, vec);
				if(!vec.empty())
				{
					for(int k = 0; k < vec.size(); k++)
					{
						if(vec[k] == 1)
							this->AddEdge(i, k);
					}
				}
				else
				{
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

void MatrixGraph::AddEdge(int from, int to)
{
	if(from < 0 || to < 0)
	{
		std::cout << "Number of vertices cannot be negative" << std::endl;
		return;
	}

	if(from < to)
	{
		if(to + 1 > countV)
		{
			//create vector for cop
			std::vector<int> vert;
			vert.reserve(to);
			//for every vertex's resize vector to 'to''s size
			for(int i = 0; i < to + 1; ++i)
			{
				//fill zero
				vert.clear();
				for(int k = 0; k < to + 1; ++k)
					vert.push_back(0);

				if(i + 1 > countV)
				{
					neighboringVertices.insert(std::make_pair(i, vert));
				}
				else
				{
					//fill old data
					auto it = neighboringVertices.find(i);
					for(int a : it->second)
						vert[a] = it->second[a];
					it->second = vert;
				}


			}
			//add new way
			neighboringVertices[from][to] = 1;
			//update count of vertices
			countV = VerticesCount();
		}
		else
		{
			neighboringVertices[from][to] = 1;
		}
	}
	else
	{
		if(from + 1 > countV)
		{
			std::vector<int> vert;
			vert.reserve(from);
			//for every vertex's resize vector to 'to''s size
			for(int i = 0; i < from + 1; ++i)
			{
				//fill zero
				vert.clear();
				for(int k = 0; k < from + 1; ++k)
					vert.push_back(0);

				if(i + 1 > countV)
				{
					neighboringVertices.insert(std::make_pair(i, vert));
				}
				else
				{
					//fill old data
					auto it = neighboringVertices.find(i);
					for(int a : it->second)
						vert[a] = it->second[a];
					it->second = vert;
				}


			}
			//add new way
			neighboringVertices[from][to] = 1;
			//update count of vertices
			countV = VerticesCount();
		}
		else
		{
			neighboringVertices[from][to] = 1;
		}
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
	std::cout << "Converting list graph to matrix graph";
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

void MatrixGraph::ShowGraph(IGraph* matrixGraph)
{
	std::cout << "  ";
	for(int i = 0; i < VerticesCount(); i++)
		std::cout << i << " ";
	std::cout << std::endl;
	for(int i = 0; i < matrixGraph->VerticesCount(); ++i)
	{
		std::cout << i << " ";
		auto it = neighboringVertices[i];
		for(int i : it)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	IGraph* listGraph = new ListGraph();

	listGraph->AddEdge(1, 0);
	listGraph->AddEdge(0, 2);
	listGraph->AddEdge(0, 1);
	listGraph->AddEdge(2, 1);
	listGraph->AddEdge(1, 2);
	listGraph->AddEdge(2, 0);
	listGraph->AddEdge(2, 2);
	listGraph->ShowGraph(listGraph);
	IGraph* matrixGraph = new MatrixGraph(listGraph);
	std::cout << std::endl;
	matrixGraph->ShowGraph(matrixGraph);
}
