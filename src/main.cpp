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

  

	return 0;
}