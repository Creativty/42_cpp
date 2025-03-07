/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:46:14 by aindjare          #+#    #+#             */
/*   Updated: 2025/03/07 15:51:06 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void) {
	std::time_t	t  = std::time(0);
	std::tm*	tm = std::localtime(&t);

	std::cout << "[";
	std::cout << 1900 + tm->tm_year; // "1992"; 
	std::cout << std::setfill('0') << std::setw(2) << 0000 + tm->tm_mon; // "01";
	std::cout << std::setfill('0') << std::setw(2) << 0000 + tm->tm_mday; // "04";   
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2) << 0000 + tm->tm_hour; // "09";   
	std::cout << std::setfill('0') << std::setw(2) << 0000 + tm->tm_min; // "15";   
	std::cout << std::setfill('0') << std::setw(2) << 0000 + tm->tm_sec; // "32";   
	std::cout << "]";
}

Account::Account(void) {
	_amount = 0;
	_nbDeposits = 0;
	_accountIndex = _nbAccounts++;
	_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
	// [19920104_091532] index:0;amount:42;created
}

Account::Account(int initial_deposit) {
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_accountIndex = _nbAccounts++;
	_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void) {
	// [19920104_091532] index:7;amount:8942;closed
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

int	Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void) {
	// TODO(XENOBAS): Implement this static function
	// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	int	p_amount = _amount;
	_nbDeposits++;
	_totalNbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	/* Examples
	 * [19920104_091532] index:5;p_amount:23;withdrawal:refused
	 * [19920104_091532] index:6;p_amount:763;withdrawal:657;amount:106;nb_withdrawals:1
	*/
	int		p_amount = _amount;
	bool	is_refused = ((_amount - withdrawal) < 0);
	if (!is_refused) {
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
	}

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	if (is_refused) {
		std::cout << "withdrawal:refused";
	} else {
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "nb_withdrawals:" << _nbWithdrawals;
	}
	std::cout << std::endl;
	return (false);
}

int		Account::checkAmount( void ) const {
	return (_amount);
}

void	Account::displayStatus( void ) const {
	// [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}
