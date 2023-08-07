#include <iostream>
#include "Containers/Vector/Vector.h"
#include "Containers/List/List.h"

template<typename T>
void bubble_sort(Vector<T>& vec){
	for (int i = 0; i < vec.size() - 1; i++){
		for (int j = 0; j < vec.size() - i - 1; j++){
			if (vec[j] > vec[j+1]){
				vec[j] = vec[j] + vec[j+1];
				vec[j+1] = vec[j] - vec[j+1];
				vec[j] = vec[j] - vec[j+1];
			}
		}
	}
}

template<typename T>
void bubble_sort(List<T>& list){
	Node<T> *first = list.front(), *last = nullptr;
	while ( first && first->next != last )
    {
        Node<T> *sorted = first->next;
        for ( Node<T> *current = first; current->next != last; current = current->next )
        {
            if ( current->next->data < current->data ) 
            {
                std::swap( current->next->data, current->data );
                sorted = current->next;
            }                
        }
        last = sorted;
    }
	Node<T> *head = list.front();
	head = first;
}


int main(int argc, char const *argv[])
{
	Vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(2);
	vec.push_back(6);
	vec.push_back(4);
	vec.push_back(3);

	std::cout << std::endl;
	vec.print();
	std::cout << std::endl;
	
	bubble_sort(vec);
	
	std::cout << std::endl;
	vec.print();
	std::cout << std::endl;

	std::cout << "List: " << std::endl;

	List<int> list;
	
	list.push_back(1);
	list.push_back(2);
	list.push_back(4);
	list.push_back(2);
	list.push_back(6);
	list.push_back(4);
	list.push_back(3);

	std::cout << std::endl;
	list.print();
	std::cout << std::endl;

	bubble_sort(list);

	std::cout << std::endl;
	list.print();
	std::cout << std::endl;

	return 0;
}
