#include "Account.hpp"
#include <iostream>

//cant put into constructor cuz static (global all accounts have access)
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit):_accountIndex(_nbAccounts), 
				_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	if (initial_deposit < 0)
	{
		std::cout << "invalid deposit amount please retry" << std::endl;
		return ;
	}
	_nbAccounts++;
	_totalAmount = _totalAmount + _amount;
	_amount = initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			  << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			  << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::cout << "[20251101_033332] ";
}

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int 	Account::getTotalAmount()
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}


int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
	<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount;
	p_amount = _amount;
	_totalAmount = _totalAmount + deposit;
	_amount = _amount + deposit;
	_totalNbDeposits++;
	_nbDeposits++;
 	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				  << ";p_amount:" << p_amount << ";deposit:" << deposit
				  <<  ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount;
	p_amount = _amount;
	if (_amount >= withdrawal)
	{
		_totalAmount = _totalAmount - withdrawal;
		_amount = _amount - withdrawal;
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
				  << ";p_amount:" << p_amount << ";withdrawal:" << withdrawal 
				  <<  ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
				  << ";p_amount:" << p_amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
}

int		Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << std::endl;
}


//hpp line 48 change func name for print_date to _displayTimestamp
//how to add to total amount if its static hpp l44
//displaystatus, checkamount and display account info confused what is what