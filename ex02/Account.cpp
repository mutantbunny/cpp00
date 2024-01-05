/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 05:52:44 by coelho            #+#    #+#             */
/*   Updated: 2024/01/05 05:53:32 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts(0);
int Account::_totalAmount(0);
int Account::_totalNbDeposits(0);
int Account::_totalNbWithdrawals(0);

int Account::getNbAccounts(void) { return Account::_nbAccounts; }
int Account::getTotalAmount(void) { return Account::_totalAmount; }
int Account::getNbDeposits(void) { return Account::_totalNbDeposits; }
int Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals()
				<< std::endl;
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" <<_amount
				<< ";created" << std::endl;
}

Account::Account(void): Account(0) { }

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" <<_amount
				<< ";closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";p_amount:" <<_amount
				<< ";deposit:" << deposit;

	_amount +=deposit;
	++_nbDeposits;
	_totalAmount += deposit;
	++_totalNbDeposits;

	std::cout << ";amount:" <<_amount
				<< ";nb_deposits:" << _nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";p_amount:" <<_amount;

	if (withdrawal > _amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}

	_amount -=withdrawal;
	++_nbWithdrawals;
	_totalAmount -= withdrawal;
	++_totalNbWithdrawals;

	std::cout << ";withdrawal:" << withdrawal
				<< ";amount:" <<_amount
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
	return true;
}

int		Account::checkAmount(void) const { return _amount; }

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" <<_amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< std::endl;
}

void Account::_displayTimestamp( void )
{
	time_t raw_time;
	struct tm *loc_time;
	char str_time[19];

	time(&raw_time);
	loc_time = localtime(&raw_time);
	strftime(str_time, 19, "[%Y%m%d_%H%M%S] ", loc_time);
	std::cout << str_time;
}
