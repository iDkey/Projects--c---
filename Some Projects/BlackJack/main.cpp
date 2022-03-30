//version 1.0
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>

std::vector<std::string> carts = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
std::vector<std::string> dealerNames = {"Jack", "Bob", "Alex", "David", "John"};
std::vector<std::string> playerNames = {"Brian", "Kevin", "Paul", "Steven", "Mark", "Daniel", "Thomas", "Robert", "Ronald", "Jacob"};

int getRandomNum(int leftBorder, int rightBorder)
{
	std::random_device rd{};
	std::mt19937 gen{rd()};
	std::uniform_int_distribution<> randomNum(leftBorder, rightBorder);
	return randomNum(gen);
}

int convertCartsToValue(int& indexCart, int& cartsValue)
{
	if(indexCart >= 0 and indexCart <= 8)
		return std::atoi(carts[indexCart].c_str());

	if(indexCart > 8 and indexCart <= 11)
		return 10;

	if(indexCart == 12)
		return cartsValue > 10 ? 1 : 11;
};

struct Carts
{
	int indexCart1 = 0;
	int indexCart2 = 0;
	std::vector<int> additionalCarts;
};

class Player
{
private:
	bool keepPlaying = true;
	std::string playerName;
	Carts availableCarts;
	int cartsValue = 0;

public:
	void setCarts()
	{
		availableCarts.indexCart1 = getRandomNum(0,12);
		availableCarts.indexCart2 = getRandomNum(0,12);
	}
	void setCartsValue()
	{
		cartsValue += convertCartsToValue(availableCarts.indexCart1, cartsValue);
		cartsValue += convertCartsToValue(availableCarts.indexCart2, cartsValue);
		for(auto i : availableCarts.additionalCarts)
		{
			cartsValue += convertCartsToValue(i, cartsValue);
		}
		if(cartsValue > 21)
		{
			if(availableCarts.indexCart1 == 12 or availableCarts.indexCart2 == 12)
				cartsValue -= 10;
		}
	}
	int getCartsValue()
	{
		return cartsValue;
	}
	Carts* getCarts()
	{
		return &availableCarts;
	}
	std::string getAvailableCart()
	{
		std::string availableCartsStr;
		availableCartsStr = carts[availableCarts.indexCart1];
		availableCartsStr += " " + carts[availableCarts.indexCart2];
		for(auto i : availableCarts.additionalCarts)
		{
			availableCartsStr += " " + carts[i];
		}
		return availableCartsStr;
	}

	void setPlayerName()
	{
		playerName = playerNames[getRandomNum(0, 4)];
	}
	std::string getPlayerName()
	{
		return playerName;
	}

	bool getKeepPlaying()
	{
		return keepPlaying;
	}
	void setKeepPlaying()
	{
		keepPlaying = false;
	}

	void clearCartsValue()
	{
		cartsValue = 0;
	}
};

class Dealer
{
private:
	std::string dealerName = "";
	Carts availableCarts;
	int cartsValue = 0;

public:
	void setCarts()
	{
		availableCarts.indexCart1 = getRandomNum(0,12);
		availableCarts.indexCart2 = getRandomNum(0,12);
	}
	void setCartsValue()
	{
		cartsValue += convertCartsToValue(availableCarts.indexCart1, cartsValue);
		cartsValue += convertCartsToValue(availableCarts.indexCart2, cartsValue);
	}
	int getCartsValue()
	{
		return cartsValue;
	}
	std::string getAvailableCart()
	{
		return carts[availableCarts.indexCart1];
	}

	void setDealerName()
	{
		dealerName = dealerNames[getRandomNum(0, 4)];
	}
	std::string getDealerName()
	{
		return dealerName;
	}

	void playerMore(Player* player)
	{
		int newIndex = getRandomNum(0,12);
		std::string newCartName = carts[newIndex];
		player->getCarts()->additionalCarts.push_back(newIndex);
		player->clearCartsValue();
		player->setCartsValue();
	}

	void playerDouble(Player* player)
	{
		playerMore(player);
		player->setKeepPlaying();
	}

	void playerSplit(Player* player)
	{

	}

	void playerEnough(Player* player)
	{
		player->setKeepPlaying();
	}
};

int main() {
	/*auto* dealer = new Dealer();
	dealer->setDealerName();
	dealer->setCarts();
	dealer->setCartsValue();
	dealer->getCartsValue();
	std::cout << "Dealer " << dealer->getDealerName() << std::endl;
	std::cout << "Dealer's cart: " << dealer->getAvailableCart() << std::endl;
	std::cout << "Dealer's cart value:" << dealer->getCartsValue();*/

	auto* player = new Player();
	player->setPlayerName();
	player->setCarts();
	player->setCartsValue();
	player->getCartsValue();
	std::cout << "Player " << player->getPlayerName() << std::endl;
	std::cout << "Player's cart: " << player->getAvailableCart() << std::endl;
	std::cout << "Player's cart value:" << player->getCartsValue() << std::endl;
	auto* dealer = new Dealer();
	dealer->playerMore(player);
	std::cout << "Player's cart: " << player->getAvailableCart() << std::endl;
	std::cout << "Player's cart value:" << player->getCartsValue() << std::endl;


}
