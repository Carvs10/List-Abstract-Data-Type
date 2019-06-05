#include <iostream>				// std::begin(), std::end()
#include <iterator>  			// std::function
#include <functional>           // std::function
#include <algorithm> 
#include <vector>
#include "../include/list.h"

int main(){

	sc::list<int> vazio;//1
	//std::cout << "pega!\n";
	sc::list<int> vazio2(2); //2
	std::vector<int> vec{1, 2, 3, 4, 5};
	sc::list<int> lista1( std::begin(vec), std::end(vec) ); //3
	sc::list<int> lista2(lista1);//4
	std::array<int, 5> list{1, 2, 3, 4, 5};
	//sc::list<int> lista3(list);


	//OPARATORS
	std::cout << "\n===============OPARATORS TEST==================\n\n";

	std::cout << "Size: " <<lista1.size() << std::endl;//size()

	std::cout << "Back: " <<lista1.back() << std::endl;//back()
	std::cout << "Front: " <<lista1.front() << std::endl;//front()

	lista1.push_back(6);
	std::cout << "Push_back: " <<lista1.back() << std::endl;//push_back()

	lista1.push_front(7);
	std::cout << "Push_front: " <<lista1.front() << std::endl;//push_front()

	lista1.pop_back();
	std::cout << "Pop_back: " <<lista1.back() << std::endl;//pop_back()

	lista1.pop_front();
	std::cout << "Pop_front: " <<lista1.front() << std::endl;//pop_front()



  

	return 0;
}