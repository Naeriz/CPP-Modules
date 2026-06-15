#include "Cat.hpp"
#include "Dog.hpp"


int main()
{
	const Animal *a = new Animal(); //shouldnt work
	const Animal *c = new Cat(); //should work
	delete a;
	delete c;
}

// int main()
// {
// 	const Dog* i = new Dog();
// 	i->getBrain()->setIdea("walkies!!", 1);
// 	const Dog* m = new Dog(*i);
// 	std::cout << "\n" << "i idea is: " << i->getBrain()->getIdea(1) << "\n";
// 	std::cout << "m idea is: " << m->getBrain()->getIdea(1) << "\n\n";

// 	delete i;
// 	delete m;
// }

// int main() //deep copy prove
// {
// 	Cat* i = new Cat();
// 	Cat* k = new Cat();

// 	i->getBrain()->setIdea("eat", 1);
// 	k->getBrain()->setIdea("sleep", 1);
// 	std::cout << "\n" << &i << "\n";
// 	std::cout << "i idea is: " << i->getBrain()->getIdea(1) << "\n";
// 	std::cout << &k << "\n";
// 	std::cout << "k idea is: " << k->getBrain()->getIdea(1) << "\n\n";
// 	*k = *i;
// 	std::cout << "\n" << &i << "\n";
// 	std::cout << "i idea is: " << i->getBrain()->getIdea(1) << "\n";
// 	std::cout << &k << "\n";
// 	std::cout << "k idea is: " << k->getBrain()->getIdea(1) << "\n\n";
	
// 	delete k;
// 	delete i;
// }


// int main()
// {
// 	const Dog* j = new Dog();
// 	const Cat* i = new Cat();
// 	const Animal *Zoo[100];
// 	j->getBrain()->setIdea("walk", 1);
// 	i->getBrain()->setIdea("eat", 1);
// 	std::cout << "\n" << "cat idea is: " << i->getBrain()->getIdea(1) << "\n";
// 	std::cout << "dog idea is: " << j->getBrain()->getIdea(1) << "\n";
	
// 	for (int i = 0; i < 50; i++)
// 		Zoo[i] = new Dog();
// 	for (int i = 50; i < 100; i++)
// 		Zoo[i] = new Cat();
// 	for (int i = 100; i >= 0; i--)
// 		delete Zoo[i];
// 	delete j;
// 	delete i;
// }
