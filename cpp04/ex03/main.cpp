#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

void	subject_main(void)
{
	std::cout << "SUBJECT TEST" << std::endl;
	IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << std::endl;
	
	ICharacter	*me = new	Character("me");
	
	AMateria	*tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << std::endl;
	
	ICharacter	*bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;
	delete (bob);
	delete (me);
	delete (src);
}

int	main(void)
{
	subject_main();
	std::cout << "--------------------------------" << std::endl;
	std::cout << "\nCUSTOM TEST" << std::endl;
	IMateriaSource	*src = new MateriaSource();
	ICharacter		*me = new Character("me");
	ICharacter		*target = new Character("target");
	std::cout << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << std::endl;

	AMateria	*m0;
	AMateria	*m1;

	m0 = src->createMateria("ice");
	me->equip(m0);
	std::cout << std::endl;
	me->use(0, *target);
	me->use(1, *target);
	me->use(-1, *target);
	me->use(100, *target);
	me->unequip(0);
	me->unequip(1);
	me->use(0, *target);
	delete (m0);
	m0 = src->createMateria("cure");
	me->equip(m0);
	me->use(0, *target);
	std::cout << std::endl;
	std::cout << "m0 current type is " << m0->getType() << "\n\n";
	m1 = src->createMateria("cure");
	m0 = src->createMateria("fire");
	std::cout << "Deep copy exemple" << std::endl;
	Character	*bob = new Character("bob");
	bob->equip(m1);
	Character	*other_bob = new Character(*bob);
	bob->unequip(0);
	bob->use(0, *target);
	other_bob->use(0, *target);
	std::cout << std::endl;
	delete(src);
	delete(m1);
	delete(me);
	delete(target);
	delete(bob);
	delete(other_bob);
}