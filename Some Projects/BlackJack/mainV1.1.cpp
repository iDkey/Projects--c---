//Version 1.1

#include <iostream>
#include <string>
#include <utility>
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

int convertCartsToValue(int indexCart, int& cartsValue)
{
	if(indexCart >= 0 and indexCart <= 8)
		return std::atoi(carts[indexCart].c_str());

	if(indexCart > 8 and indexCart <= 11)
		return 10;

	if(indexCart == 12)
		return cartsValue > 10 ? 1 : 11;
	return 0;
}

class Carts
{
private:
	int indexCart1 = 0;
	int indexCart2 = 0;
	std::vector<int> additionalCarts;

public:
	void setIndexCarts(int inIndex1, int inIndex2)
	{
		indexCart1 = inIndex1;
		indexCart2 = inIndex2;
	}
	void setAdditionalCart(int inIndexAdditional)
	{
		additionalCarts.push_back(inIndexAdditional);
	}

	int getIndex1() const	{ return indexCart1;}
	int getIndex2() const	{ return indexCart2;}
	int getAdditionalIndex(int& i)
	{
		return additionalCarts[i];
	}
	int getAdditionalSize() { return additionalCarts.size();}
};

class Player
{
private:
	std::vector<Carts*> availableCarts;
	bool keepPlaying = true;
	std::string playerName;
	//Carts availableCarts;
	int cartsValue = 0;

public:
	Player()= default;;
	Player(std::string inName) : playerName(std::move(inName)){};

	void setCarts()
	{
		auto cartsPlug = new Carts;
		cartsPlug->setIndexCarts(getRandomNum(0,12), getRandomNum(0,12));
		availableCarts.push_back(cartsPlug);
	}
	void setCartsValue()
	{
		auto cartsPlug = availableCarts[0];

		cartsValue += convertCartsToValue(cartsPlug->getIndex1(), cartsValue);
		cartsValue += convertCartsToValue(cartsPlug->getIndex2(), cartsValue);
		for(int i = 0; i < cartsPlug->getAdditionalSize(); ++i)
		{
			cartsValue += convertCartsToValue(cartsPlug->getAdditionalIndex(i), cartsValue);
		}
		if(cartsValue > 21)
		{
			if(cartsPlug->getIndex1() == 12 or cartsPlug->getIndex2() == 12)
				cartsValue -= 10;
		}
	}
	int getCartsValue() const
	{
		return cartsValue;
	}
	Carts* getCarts()
	{
		return availableCarts[0];
	}
	std::string getAvailableCart()
	{
		std::string availableCartsStr;
		auto cartsPlug = availableCarts[0];
		availableCartsStr = carts[cartsPlug->getIndex1()];
		availableCartsStr += ", " + carts[cartsPlug->getIndex2()];
		for(int i = 0; i < cartsPlug->getAdditionalSize(); ++i)
		{
			availableCartsStr += ", " + carts[cartsPlug->getAdditionalIndex(i)];
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

	bool getKeepPlaying() const
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
	std::vector<Player*> players;
	int countOfSplit = 0;

public:
	void setCarts()
	{
		availableCarts.setIndexCarts(getRandomNum(0,12), getRandomNum(0,12));
	}
	void setCartsValue()
	{
		cartsValue += convertCartsToValue(availableCarts.getIndex1(), cartsValue);
		cartsValue += convertCartsToValue(availableCarts.getIndex2(), cartsValue);
		for(int i = 0; i < availableCarts.getAdditionalSize(); ++i)
		{
			cartsValue += convertCartsToValue(availableCarts.getAdditionalIndex(i), cartsValue);
		}
		if(cartsValue > 21)
		{
			if(availableCarts.getIndex1() == 12 or availableCarts.getIndex2() == 12)
				cartsValue -= 10;
		}
	}
	int getCartsValue() const
	{
		return cartsValue;
	}
	std::string getAvailableCart()
	{
		return carts[availableCarts.getIndex1()];
	}

	void setDealerName()
	{
		dealerName = dealerNames[getRandomNum(0, 4)];
	}
	std::string getDealerName()
	{
		return dealerName;
	}

	void dealerMore()
	{
		int newIndex = getRandomNum(0,12);
		std::string newCartName = carts[newIndex];
		availableCarts.setAdditionalCart(newIndex);
		cartsValue = 0;
		setCartsValue();
	}

	static void playerMore(Player* player)
	{
		int newIndex = getRandomNum(0,12);
		std::string newCartName = carts[newIndex];
		player->getCarts()->setAdditionalCart(newIndex);
		player->clearCartsValue();
		player->setCartsValue();
	}

	static void playerDouble(Player* player)
	{
		playerMore(player);
		player->setKeepPlaying();
	}

	void playerSplit(Player* player)
	{
		if(player->getCarts()->getIndex1() == player->getCarts()->getIndex2() and
				player->getCarts()->getAdditionalSize() == 0)
		{
			countOfSplit++;
			auto* carts2 = new Carts();
			int plug = player->getCarts()->getIndex2();
			player->getCarts()->setIndexCarts(player->getCarts()->getIndex1(), getRandomNum(0, 12));
			carts2->setIndexCarts(plug, getRandomNum(0, 12));
		}
		else
			std::cout << "Cannot split" << std::endl;
	}

	static void playerEnough(Player* player)
	{
		player->setKeepPlaying();
	}

	void pushPlayerPointer(Player*& player)
	{
		players.push_back(player);
	}
	Player* getPlayerPointer(int playerIndex)
	{
		return players[playerIndex];
	}
	int getPlayerCount()
	{
		return players.size();
	}
};

//function of logic game
std::string botsLogic(Dealer*& dealer, const std::string& whoPlay, const int& playerIndex)
{
	if(whoPlay == "player")
	{
		if(dealer->getPlayerPointer(playerIndex)->getCarts()->getIndex1() ==
		   dealer->getPlayerPointer(playerIndex)->getCarts()->getIndex2() and
		   dealer->getPlayerPointer(playerIndex)->getCartsValue() < 18)
		{
			return "split";
		}
		else
		if(dealer->getPlayerPointer(playerIndex)->getCartsValue() > 17)
		{
			return "enough";
		}
		else
		if(getRandomNum(1, 2) == 1 and dealer->getPlayerPointer(playerIndex)->getCartsValue() < 17)
		{
			return "double";
		}
		else
			return "more";
	}
	else
	{
		if(dealer->getCartsValue() <= 17)
			return "more";
		else
			return "enough";
	}
}

//bots play game
void botsPlaying(Dealer*& dealer, Player*& player)
{
	for(int i = 1; i < dealer->getPlayerCount(); ++i)
	{
		while(player->getKeepPlaying())
		if(botsLogic(dealer, "player", i) == "more")
		{
			Dealer::playerMore(player);
		}
		else
			if(botsLogic(dealer, "player", i) == "split")
			{
				dealer->playerSplit(player);
			}
			else
				if(botsLogic(dealer, "player", i) == "double")
					Dealer::playerDouble(player);
				else
					if(botsLogic(dealer, "player", i) == "enough")
						Dealer::playerEnough(player);
	}

	while(botsLogic(dealer, "dealer", -1) != "enough")
	{
		if(botsLogic(dealer, "dealer", -1) == "more")
			dealer->dealerMore();
	}
}

void startGame(int& countOfPlayers, std::string& inName)
{
	//settings for dealer
	auto* dealer = new Dealer();
	dealer->setDealerName();
	dealer->setCarts();
	dealer->setCartsValue();
	dealer->getCartsValue();
	std::cout << "Dealer " << dealer->getDealerName() << std::endl;
	std::cout << "Dealer's cart: " << dealer->getAvailableCart() << std::endl;
	std::cout << "Dealer's carts value:" << dealer->getCartsValue() << std::endl;
	std::cout << std::endl;

	//settings for player
	auto* player = new Player(inName);
	player->setCarts();
	player->setCartsValue();
	dealer->pushPlayerPointer(player);

	//settings for bots
	for(int i = 0; i < countOfPlayers - 1; ++i)
	{
		auto* playerBot = new Player();
		playerBot->setPlayerName();
		playerBot->setCarts();
		playerBot->setCartsValue();
		dealer->pushPlayerPointer(playerBot);
	}

	//output for all players
	for(int i = 0; i < countOfPlayers; ++i)
	{
		std::cout << "Player#" << i + 1 << std::endl;
		std::cout << "Player name: " << dealer->getPlayerPointer(i)->getPlayerName() << std::endl;
		std::cout << dealer->getPlayerPointer(i)->getPlayerName() << " have " << dealer->getPlayerPointer(i)->getAvailableCart() << std::endl;
		std::cout << "its " << dealer->getPlayerPointer(i)->getCartsValue() << std::endl;
		std::cout << std::endl;
	}

	//playing game for all players
	for ( int i = 0; i < countOfPlayers; i++ ) {
		std::cout << "Player#" << i + 1 << " move" << std::endl;
		player = dealer->getPlayerPointer(i);
		while(player->getKeepPlaying())
		{
			if(i == 0)
			{
				std::string move = "";
				std::cout << "Make a move:" << std::endl;
				std::cin >> move;
				if(move == "more")
				{
					dealer->playerMore(player);
					if(player->getCartsValue() > 21)
					{
						std::cout << "Player " << inName << " lose" << std::endl;
						player->setKeepPlaying();
					}
				}
				else
				if(move == "double")
				{
					dealer->playerDouble(player);
				}
				else
				if(move == "enough")
				{
					dealer->playerEnough(player);
				}
				else
				if(move == "split")
				{
					dealer->playerSplit(player);
				};
				std::cout << dealer->getPlayerPointer(i)->getPlayerName() << " have ";
				std::cout << dealer->getPlayerPointer(i)->getAvailableCart() << std::endl;
				std::cout << "Its " << dealer->getPlayerPointer(i)->getCartsValue();
				std::cout << std::endl;
			}
			else
			{
				botsPlaying(dealer, player);
				std::cout << dealer->getPlayerPointer(i)->getPlayerName() << " have ";
				std::cout << dealer->getPlayerPointer(i)->getAvailableCart() << std::endl;
				std::cout << "Its " << dealer->getPlayerPointer(i)->getCartsValue();
				std::cout << std::endl;
			}
		}
	}
}

int main() {
	//setting count of players on the table
	int countOfPlayers = 0;
	std::cout << "Input count of players:" << std::endl;
	std::cin >> countOfPlayers;

	//setting player's name
	std::string name = "";
	std::cout << "Input u name:" << std::endl;
	std::cin >> name;

	//start 1st settings
	startGame(countOfPlayers, name);
}
