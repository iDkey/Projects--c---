#include <iostream>
#include <string>

class Toy
{
private:
	std::string _name;

public:
	Toy() : _name("SameToy") {};
	Toy(std::string inName) : _name(std::move(inName)) {};
	std::string name() const
	{
		return _name;
	}
};

class shared_ptr_toy
{
private:
	Toy* obj = nullptr;
	int* countLinks = nullptr;
	void decrease()
	{
		if(--*countLinks == 0)
		{
			std::cout << "Delete toy with name " << (obj == nullptr ? "Empty" : obj->name()) << std::endl;
			delete obj;
			delete countLinks;
		}
	}

public:
	shared_ptr_toy()
	{
		obj = new Toy("SomeName");
		countLinks = new int(1);
	}
	shared_ptr_toy(std::string inName)
	{
		obj = new Toy(inName);
		countLinks = new int(1);
	}
	shared_ptr_toy(Toy* ptr): obj(ptr)
	{
		countLinks = new int(1);
	}

	shared_ptr_toy(const shared_ptr_toy& oth)
	{
		obj = oth.obj;
		countLinks = oth.countLinks;
		++*countLinks;
	}

	shared_ptr_toy& operator = (const shared_ptr_toy& oth)
	{
		if(countLinks != oth.countLinks)
		{
			decrease();
			obj = oth.obj;
			countLinks = oth.countLinks;
			++*countLinks;
		}
		return *this;
	}
	Toy* operator->() const
	{
		return obj;
	}

	~shared_ptr_toy()
	{
		decrease();
	}
};

template<typename ... Args>
shared_ptr_toy make_shared_toy(Args&& ... args)
{
	return shared_ptr_toy(std::forward<Args>(args)...);
}

int main() {
	shared_ptr_toy null1(nullptr);
	shared_ptr_toy null5(nullptr);
	auto null2 = null1;

	auto p = make_shared_toy("Ball");
	auto p1 = make_shared_toy("Bone");
	null2 = null1 = p;
	null5 = p1;

	std::cout<<null2->name()<<std::endl;
}