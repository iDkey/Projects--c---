/*#include <iostream>
#include <string>
#include <memory>

class Toy
{
public:
	Toy() : name("SameToy") {};
	Toy(std::string inName) : name(inName) {};

private:
	std::string name;
};

class smart_ptr_toy
{
private:
	Toy* obj;

public:
	smart_ptr_toy()
	{
		obj = new Toy("SomeName");
	}
	smart_ptr_toy(std::string inName)
	{
		obj = new Toy(inName);
	}

	smart_ptr_toy(const smart_ptr_toy& oth)
	{
		obj = new Toy(*oth.obj);
	}
	smart_ptr_toy& operator = (const smart_ptr_toy& oth)
	{
		if(this == &oth)
			return *this;
		if(obj != nullptr)
			delete obj;
		obj = new Toy(*oth.obj);
		return *this;
	}

	~smart_ptr_toy()
	{
		delete obj;
	}

};

class Dog
{
private:
	std::string name = "";
	int age = 0;
	std::string lovelyToy;
public:

	Dog(std::string inNameDog, std::string inNameToy, int inAge) : name(inNameDog), lovelyToy(inNameToy)
	{
		if(inAge > 0 and inAge < 30)
			age = inAge;
	}
	Dog() : Dog("SomeName", "SomeToy", 0) {};
	Dog(std::string inName) : Dog(inName, "SomeToy", 0) {};
	Dog(int inAge) : Dog("SomeName", "SomeToy", inAge) {};

	void copyToy(const Dog& oth)
	{
		lovelyToy = oth.lovelyToy;
	}

};


int main() {
	std::unique_ptr<Dog> d = std::make_unique<Dog>("sharik", "bone", 5);
}*/
#include <iostream>
#include <string>
#include <memory>

class Toy
{
public:
	Toy() : name("SameToy") {};
	Toy(std::string inName) : name(inName) {};

private:
	std::string name;
};

class shared_ptr_toy
{
private:
	Toy* obj;
	int *count = new int(0);

public:
	shared_ptr_toy()
	{
		std::cout << "create obj" << std::endl;
		obj = new Toy("SomeName");
	}
	shared_ptr_toy(std::string inName)
	{
		std::cout << "create obj" << std::endl;
		obj = new Toy(inName);
	}

	shared_ptr_toy(const shared_ptr_toy& oth)
	{
		std::cout << "copy obj" << std::endl;
		this->count+=1;
		obj = new Toy(*oth.obj);
	}
	shared_ptr_toy& operator = (const shared_ptr_toy& oth)
	{
		std::cout << "copy = obj" << std::endl;
		*count += 1;
		if(this == &oth)
			return *this;
		if(obj != nullptr)
			delete obj;
		obj = new Toy(*oth.obj);
		return *this;
	}

	~shared_ptr_toy()
	{
		if(count == nullptr)
		{
			delete count;
			std::cout << "Del count" << std::endl;
		}
		*count -= 1;
		delete obj;
		std::cout << "del obj" << std::endl;

	}
};

class Dog
{
private:
	std::string name = "";
	int age = 0;
	shared_ptr_toy lovelyToy;
public:
	Dog(std::string inNameDog, shared_ptr_toy inNameToy, int inAge) : name(inNameDog), lovelyToy(inNameToy)
	{
		if(inAge > 0 and inAge < 30)
			age = inAge;
	}
	Dog() : Dog("SomeName", shared_ptr_toy("some toy"), 0) {};
	Dog(std::string inName) : Dog(inName, shared_ptr_toy("some toy"), 0) {};
	Dog(int inAge) : Dog("SomeName", shared_ptr_toy("some toy"), inAge) {};

	void copyToy(const Dog& oth)
	{
		lovelyToy = oth.lovelyToy;
	}

};


int main() {
	shared_ptr_toy ball("ball");
	std::unique_ptr<Dog> d = std::make_unique<Dog>("sharik", ball, 5);
}