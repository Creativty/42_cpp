/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:17:36 by aindjare          #+#    #+#             */
/*   Updated: 2025/11/28 11:55:01 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <vector>
#include <climits>
#include <cstdlib>
#include <ostream>
#include <iostream>
#include <iterator>
#include <algorithm>

std::ostream&		operator<<(std::ostream& stream, const std::deque<int>& deq) {
	typedef std::deque<int>::const_iterator	iterator;
	for (iterator it = deq.begin(); it != deq.end(); ++it) {
		if (it != deq.begin()) {
			stream << " ";
		}
		stream << (*it);
	}
	return (stream);
}
std::ostream&		operator<<(std::ostream& stream, const std::vector<int>& vec) {
	typedef std::vector<int>::const_iterator	iterator;
	for (iterator it = vec.begin(); it != vec.end(); ++it) {
		if (it != vec.begin()) {
			stream << ", ";
		}
		stream << (*it);
	}
	return (stream);
}

bool				CLI_parse_numbers(const char **strs, int strs_size,
	std::vector<int>& vec, std::deque<int>& deq)
{
	typedef std::vector<int>::iterator	iterator;
	bool								ok = true;

	for (int i = 0; i < strs_size; ++i) {
		char*		end = NULL;
		long		val = std::strtol(strs[i], &end, 10);
		if (end == NULL || *end != '\0') {
			std::cerr << "error: argument position " << i << ": '" << strs[i] << "' could not parse number\n";
			
			ok = false;
			continue ;
		}
		if (val < INT_MIN || val > INT_MAX) {
			std::cerr << "error: argument position " << i << ": '" << strs[i] << "' number is out of range for an int\n";

			ok = false;
			continue ;
		}

		int			num = static_cast<int>(val);

		iterator	it = std::find(vec.begin(), vec.end(), num);
		if (it != vec.end()) {
			std::cerr << "error: argument position " << i << ": '" << strs[i] << "' is a duplicate of the argument at position " << std::distance(vec.begin(), it) << "\n";

			ok = false;
			continue ;
		}

		vec.push_back(num);
		deq.push_back(num);
	}
	return (ok);
}

struct				FJ_Pair {
	int				pair_size;
	union {
		int			numbers[2];
		FJ_Pair*	pairs[2];
	};

	int				small(void) {
		if (pair_size == 2) {
			return (this->numbers[0]);
		}
		return (this->pairs[0]->small());
	}
	int				large(void) {
		if (pair_size == 2) {
			return (this->numbers[1]);
		}
		return (this->pairs[1]->large());
	}
	static FJ_Pair*	make(int small, int large) {
		FJ_Pair*	pair = new FJ_Pair;

		pair->pair_size = 2;
		pair->numbers[0] = small;
		pair->numbers[1] = large;
		return (pair);
	}
	static FJ_Pair*	make(FJ_Pair* small, FJ_Pair* large) {
		FJ_Pair*	pair = new FJ_Pair;

		pair->pair_size = small->pair_size * 2;
		pair->pairs[0] = small;
		pair->pairs[1] = large;
		return (pair);
	}
};

std::ostream&		operator<<(std::ostream& stream, const std::vector<FJ_Pair*>& vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		if (i > 0) {
			stream << ", ";
		}

		const FJ_Pair&	pair = *vec[i];
		if (pair.pair_size == 2) {
			stream << pair.numbers[0] << ", " << pair.numbers[1];
		} else {
			stream << pair.pairs[0] << ", " << pair.pairs[1];
		}
	}
	return (stream);
}

/* DESC: Ford Jhonson
*	10: Begin
*		20: Container of sorted pairs `Pairs` in the form [small, large], with a `Rest` element in case of odd sized `Input Container`
*		30: Check if we can form pair then recurse to 10, otherwise continue
*		40: Sequence in the form `Pairs[0].Small + Pairs.map([small, large] => large)` known as the "main chain" (this will be sorted automatically due to the pairings from before)
*		50: Sequence in the form `Pairs.map([small, large] => small) + Rest` known as the "pend chain"
*		60: Binary insert the elements from "pend chain" into "main chain", in the order based on Jacobsthal numbers (if not possible use reverse order)
*/

/* DESC: Binary insertion using Jacobsthal Numbers order (with reverse order fallback)
 * 10: For each item in the to be inserted
 *		20: 
 *
 *
 */

/* Implementation */


size_t					JACOBSTHAL_number(size_t n) {
	if (n <= 1) {
		return (n);
	}
	return (JACOBSTHAL_number(n - 1) + 2 * JACOBSTHAL_number(n - 2));
}

void					BINARY_insert(std::vector<FJ_Pair*>& Output_Container, size_t End, FJ_Pair* Pair, int& Comparisons) {
	if (End > Output_Container.size()) {
		End = Output_Container.size();
	}

	size_t		left = 0;
	size_t		right = End;
	int			Number = Pair->large();
	while (left < right) {
		size_t	middle = (right + left) / 2;

		++Comparisons;
		if (Number > Output_Container[middle]->large()) {
			left = middle + 1;
		} else {
			right = middle;
		}
	}

	size_t							Index = left;
	std::vector<FJ_Pair*>::iterator	Position = Output_Container.begin();

	std::advance(Position, Index);
	Output_Container.insert(Position, Pair);
}
void					BINARY_insert(std::vector<int>& Output_Container, size_t End, int Number, int& Comparisons) {
	if (End > Output_Container.size()) {
		End = Output_Container.size();
	}

	size_t		left = 0;
	size_t		right = End;
	while (left < right) {
		size_t	middle = (right + left) / 2;
		++Comparisons;
		if (Number > Output_Container[middle]) {
			left = middle + 1;
		} else {
			right = middle;
		}
	}

	size_t						Index = left;
	std::vector<int>::iterator	Position = Output_Container.begin();

	std::advance(Position, Index);
	Output_Container.insert(Position, Number);
}

void					FJ_free(FJ_Pair* Pair) {
	if (Pair->pair_size > 2) {
		FJ_free(Pair->pairs[0]);
		FJ_free(Pair->pairs[1]);
	}
	delete	Pair;
}
void					FJ_free(std::vector<FJ_Pair*>& Pairs) {
	for (size_t i = 0; i < Pairs.size(); ++i) {
		FJ_Pair*	Pair = Pairs[i];

		FJ_free(Pair);
	}
}
void					FJ_flat(std::vector<int>& Output_Container, FJ_Pair* Pair) {
	if (Pair->pair_size > 2) {
		FJ_flat(Output_Container, Pair->pairs[0]);
		FJ_flat(Output_Container, Pair->pairs[1]);
	} else {
		Output_Container.push_back(Pair->numbers[0]);
		Output_Container.push_back(Pair->numbers[1]);
	}
}
void					FJ_flat(std::vector<int>& Output_Container, const std::vector<FJ_Pair*>& Input_Container) {
	for (size_t i = 0; i < Input_Container.size(); ++i) {
		FJ_Pair*	Pair = Input_Container[i];
		FJ_flat(Output_Container, Pair);
	}
}
std::vector<FJ_Pair*>	FJ_sort(const std::vector<FJ_Pair*> Input_Container, int& Comparisons) {
	bool					Rest = (Input_Container.size() % 2 == 1);
	std::vector<FJ_Pair*>	Pairs;
	for (size_t i = 0; i + 1 < Input_Container.size(); i += 2) {
		size_t	small_idx = i + 0;
		size_t	large_idx = i + 1;

		++Comparisons;
		if (Input_Container[small_idx]->large() > Input_Container[large_idx]->large()) {
			small_idx = i + 1;
			large_idx = i + 0;
		}

		FJ_Pair*			pair = FJ_Pair::make(Input_Container[small_idx], Input_Container[large_idx]);
		Pairs.push_back(pair);
	}

	if (Pairs.size() > 1) {
		Pairs = FJ_sort(Pairs, Comparisons);
	}

	std::vector<FJ_Pair*>	Seq_Main;
	Seq_Main.push_back(Pairs[0]->pairs[0]);
	for (size_t i = 0; i < Pairs.size(); ++i) {
		Seq_Main.push_back(Pairs[i]->pairs[1]);
	}

	std::vector<FJ_Pair*>	Seq_Pend;
	for (size_t i = 0; i < Pairs.size(); ++i) { /* NOTE(xenobas): Intentionally push the 1st element that already exists in the Seq_Main, so that we can skip it during jacobsthal binary insertion */
		Seq_Pend.push_back(Pairs[i]->pairs[0]);
	}
	if (Rest) {
		Seq_Pend.push_back(Input_Container.back());
	}

	size_t	Inserts = 1;
	size_t	jacobsthal_idx = 3;
	size_t	jacobsthal_prev = 1;
	size_t	jacobsthal_curr = 3;
	/* Upper bound = base main upper bound + jacobsthal overall iteration */
	while (jacobsthal_curr <= Seq_Pend.size()) {
		for (size_t jacobsthal_i = jacobsthal_curr; jacobsthal_i > jacobsthal_prev; --jacobsthal_i) {
			size_t					Index = jacobsthal_i - 1;
			FJ_Pair*				Pair = Seq_Pend[Index];

			size_t					End = jacobsthal_i + Inserts - 1;
			BINARY_insert(Seq_Main, End, Pair, Comparisons);

			Inserts++;
		}

		++jacobsthal_idx;
		jacobsthal_prev = jacobsthal_curr;
		jacobsthal_curr = JACOBSTHAL_number(jacobsthal_idx);
	}

	/* NOTE(xenobas): Handle Jacobsthal overflow */
	while (Seq_Pend.size() > Inserts) {
		FJ_Pair*	Pair = Seq_Pend.back();
		Seq_Pend.pop_back();

		size_t		End = Seq_Main.size();
		BINARY_insert(Seq_Main, End, Pair, Comparisons);

		++Inserts;
	}
	// if (Rest) {
	// 	FJ_Pair*	Pair = Input_Container.back();

	// 	size_t		End = Seq_Main.size();
	// 	BINARY_insert(Seq_Main, End, Pair, Comparisons);

	// 	++Inserts;
	// }
	return (Seq_Main);
}
std::vector<int>		FJ_sort(const std::vector<int>& Input_Container, int& Comparisons) {
	bool					Rest = (Input_Container.size() % 2 == 1);
	std::vector<FJ_Pair*>	Pairs;
	std::vector<int>		Numbers;

	for (size_t i = 0; i + 1 < Input_Container.size(); i += 2) {
		size_t	small_idx = i + 0;
		size_t	large_idx = i + 1;

		++Comparisons;
		if (Input_Container[small_idx] > Input_Container[large_idx]) {
			small_idx = i + 1;
			large_idx = i + 0;
		}

		FJ_Pair*			pair = FJ_Pair::make(Input_Container[small_idx], Input_Container[large_idx]);
		Pairs.push_back(pair);
	}

	if (Pairs.size() > 1) {
		Pairs = FJ_sort(Pairs, Comparisons);
	}

	std::vector<int>	Seq_Main;
	Seq_Main.push_back(Pairs[0]->numbers[0]);
	for (size_t i = 0; i < Pairs.size(); ++i) {
		Seq_Main.push_back(Pairs[i]->numbers[1]);
	}

	std::vector<int>	Seq_Pend;
	for (size_t i = 0; i < Pairs.size(); ++i) { /* NOTE(xenobas): Intentionally push the 1st element that already exists in the Seq_Main, so that we can skip it during jacobsthal binary insertion */
		Seq_Pend.push_back(Pairs[i]->numbers[0]);
	}
	if (Rest) {
		Seq_Pend.push_back(Input_Container.back());
	}

	size_t	Inserts = 1;
	size_t	jacobsthal_idx = 3;
	size_t	jacobsthal_prev = 1;
	size_t	jacobsthal_curr = 3;
	/* Upper bound = base main upper bound + jacobsthal overall iteration */
	while (jacobsthal_curr <= Seq_Pend.size()) {
		for (size_t jacobsthal_i = jacobsthal_curr; jacobsthal_i > jacobsthal_prev; --jacobsthal_i) {
			size_t		Index = jacobsthal_i - 1;
			int			Number = Seq_Pend[Index];

			size_t		End = jacobsthal_i + Inserts - 1;
			BINARY_insert(Seq_Main, End, Number, Comparisons);

			Inserts++;
		}

		++jacobsthal_idx;
		jacobsthal_prev = jacobsthal_curr;
		jacobsthal_curr = JACOBSTHAL_number(jacobsthal_idx);
	}

	/* NOTE(xenobas): Handle Jacobsthal overflow */
	while (Seq_Pend.size() > Inserts) {
		int				Number = Seq_Pend.back();
		Seq_Pend.pop_back();

		size_t		End = Seq_Main.size();
		BINARY_insert(Seq_Main, End, Number, Comparisons);

		++Inserts;
	}
	return (Seq_Main);
}

/* Entry Point */
int					main(int argc, const char **argv) {
	// TODO(xenobas): Handle only one number
	// TODO(xenobas): Implement deque as well
	std::deque<int>		container_deq;
	std::vector<int>	container_vec;

	if (argc == 1) {
		std::cerr << "usage: " << argv[0] << " <integer>...\n";
		return (1);
	}
	if (!CLI_parse_numbers(&argv[1], argc - 1, container_vec, container_deq)) {
		return (2);
	}

	std::cout << "Deque:  " << container_deq << '\n';

	std::cout << "Vector: " << container_vec << '\n';
	int					sorted_ops = 0;
	std::vector<int>	sorted_vec = FJ_sort(container_vec, sorted_ops);
	// std::vector<int>	sorted_vec = FJ_sort(container_vec);
	std::cout << "Vector: " << sorted_vec << '\n';
	std::cout << sorted_ops << " comparisons\n";
	bool				sorted_ok = true;
	for (size_t i = 0; i + 1 < sorted_vec.size(); ++i) {
		if (sorted_vec[i + 0] >= sorted_vec[i + 1]) {
			std::cerr << "error: vector was not sorted properly" << std::endl;
			sorted_ok = false;
			break ;
		}
	}
	return (sorted_ok ? 0 : 8);
}
