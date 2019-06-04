#include <iostream>				// std::begin(), std::end()
#include <iterator>  			// std::function
#include <functional>           // std::function
#include <algorithm> 
#include <vector>
#include "../include/list.h"

int main(){

	ls::list<int> vazio;//1
	std::cout << "pega!\n";
	ls::list<int> vazio2(2); //2
	std::vector<int> vec{1, 2, 3, 4, 5};
	ls::list<int> lista1( std::begin(vec), std::end(vec) ); //3

  

	return 0;
}