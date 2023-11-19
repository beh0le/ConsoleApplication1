#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> // содержит time()
#include <conio.h>

class Unit { // Это ебейший класс который создаст тебе любого перса
public:
	int max_hp;
	int hp;
	int damage;
	int mana;
	std::string name;

	Unit(int max_hp, int damage, std::string name, int mana = 0) { //Это ебаный констурктор который создаст тебе перса и передаст через this в переменые твои аргументы
		this->max_hp = max_hp;
		this->hp = max_hp;
		this->damage = damage;
		this->name = name;
		this->mana = mana;
	}

	void print() { // Это сука метод который выведет инфу о персе который был созда через Unit
		std::cout << "Имя: " << name << "\nЗдоровье: " << hp << "/" << max_hp << "\nУрон: " << damage << "\nМана: " << mana << std::endl;
	}
};


int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "Игра-хуйня" << std::endl;
	std::cout << "\n\nВыбрать персонажа: 1 (Орк) или 2 (Рыцарь)" << "\nВыйти: 3"<<std::endl;
	int choice;
	std::cin >> choice;
	Unit* punit = nullptr;
	if (choice == 1) {
		Unit ork(20, 7, "Орк", 5); //Это блять реальное ООП
		punit = &ork;
		std::cout << "Вы выбрали орка" << std::endl;
		ork.print();
	}
	else if (choice == 2) {
		Unit knight(25, 5, "Рыцарь", 8);
		punit = &knight;
		std::cout << "Вы выбрали рыцаря" << std::endl;
		knight.print();
	}
	else if (choice == 3) {
		exit(0);
	}
	else {
		std::cout << "Ввод некорректный" << std::endl;
	}
	Unit slave(5,2, "Slave", 5);
	Unit* penemy = &slave;
	std::cout << "Вы начали свой спуск в подземелье, но на вас напал Slave." << std::endl;
	slave.print();
	std::cout << " \nВаши действия?" << std::endl;
	std::cout << "Драться: 1" << "\tУбежать: 2, верятность 50%" << std::endl;
	std::cin >> choice;
	if (choice == 1) {
		std::cout << "Вы начали бой" << std::endl;
			while (slave.hp > 0 && punit->hp >0) {
				std::cout << "Атака:1; Урон от атаки=  " << punit->damage << "\n Защита: 2; Снижение урона на 50% и исциление на 10% от максимального здоров'я " << std::endl;
				int choice_2;
				std::cin >> choice_2;
				if (choice_2 == 1) {
					slave.hp = slave.hp - punit->damage;
					punit->hp = punit->hp - slave.damage;
					if (slave.hp < 0) {
						slave.hp = 0;
					}
					if (punit->hp <= 0) {
						std::cout << "Вы проиграли";
						exit(0);
					};
					std::cout << "Вы нанесли " << punit->damage << " урона. У Slave осталось " << slave.hp << " Здоровья" << std::endl;
					std::cout << "Вы получили " << slave.damage << " урона. У вас осталось " << punit->hp << " Здоровья" << std::endl;
				}
				if (choice_2 == 2) {
					int dm, hh;
					dm = (slave.damage / 2);
					punit->hp -= dm;
					hh = (punit->max_hp / 10);
					punit->hp += hh;
				std::cout << "Ваше здороье: " << punit->hp<<std::endl;
				std::cout << "Вы получили " << dm << " Урона" << "\n Вы исцелились на " << hh << " Здоровья" << std::endl;
				}
			}
			if (slave.hp == 0) {
				std::cout << "Вы победили" << std::endl;
			}
	}
	else if (choice == 2) {
		int random;
		srand(time(NULL));
		random = rand()%101;
		if (random <= 50) {
			std::cout << "Вам повезло, вы смогли скрытся";
		}
		else if (random > 50) {
			punit->hp = 0;
			std::cout <<"Вы програли";
		}
	}
	else {
		std::cout << "Ввод некорректный" << std::endl;
	}
	return 0;
	_getch();
}
