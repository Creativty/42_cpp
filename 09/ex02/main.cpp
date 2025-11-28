/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:17:36 by aindjare          #+#    #+#             */
/*   Updated: 2025/11/28 15:15:12 by aindjare         ###   ########.fr       */
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

#include <time.h>

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

void					FJ_free(FJ_Pair* Pair) {
	if (Pair->pair_size > 2) {
		FJ_free(Pair->pairs[0]);
		FJ_free(Pair->pairs[1]);
	}
	delete	Pair;
}

size_t					JACOBSTHAL_number(size_t n) {
	if (n <= 1) {
		return (n);
	}
	return (JACOBSTHAL_number(n - 1) + 2 * JACOBSTHAL_number(n - 2));
}

void					BINARY_insert(std::deque<FJ_Pair*>& Output_Container, size_t End, FJ_Pair* Pair, int& Comparisons) {
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
	std::deque<FJ_Pair*>::iterator	Position = Output_Container.begin();

	std::advance(Position, Index);
	Output_Container.insert(Position, Pair);
}
void					BINARY_insert(std::deque<int>& Output_Container, size_t End, int Number, int& Comparisons) {
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
	std::deque<int>::iterator	Position = Output_Container.begin();

	std::advance(Position, Index);
	Output_Container.insert(Position, Number);
}

void					FJ_free(std::deque<FJ_Pair*>& Pairs) {
	for (size_t i = 0; i < Pairs.size(); ++i) {
		FJ_Pair*	Pair = Pairs[i];

		FJ_free(Pair);
	}
}
void					FJ_flat(std::deque<int>& Output_Container, FJ_Pair* Pair) {
	if (Pair->pair_size > 2) {
		FJ_flat(Output_Container, Pair->pairs[0]);
		FJ_flat(Output_Container, Pair->pairs[1]);
	} else {
		Output_Container.push_back(Pair->numbers[0]);
		Output_Container.push_back(Pair->numbers[1]);
	}
}
void					FJ_flat(std::deque<int>& Output_Container, const std::deque<FJ_Pair*>& Input_Container) {
	for (size_t i = 0; i < Input_Container.size(); ++i) {
		FJ_Pair*	Pair = Input_Container[i];
		FJ_flat(Output_Container, Pair);
	}
}
std::deque<FJ_Pair*>	FJ_sort_pairs(const std::deque<FJ_Pair*> Input_Container, int& Comparisons) {
	std::deque<FJ_Pair*>	Pairs;

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
		Pairs = FJ_sort_pairs(Pairs, Comparisons);
	}

	std::deque<FJ_Pair*>	Seq_Main;
	Seq_Main.push_back(Pairs[0]->pairs[0]);
	for (size_t i = 0; i < Pairs.size(); ++i) {
		Seq_Main.push_back(Pairs[i]->pairs[1]);
	}

	std::deque<FJ_Pair*>	Seq_Pend;
	for (size_t i = 0; i < Pairs.size(); ++i) { /* NOTE(xenobas): Intentionally push the 1st element that already exists in the Seq_Main, so that we can skip it during jacobsthal binary insertion */
		Seq_Pend.push_back(Pairs[i]->pairs[0]);
	}

	bool					Rest = (Input_Container.size() % 2 == 1);
	if (Rest) {
		Seq_Pend.push_back(Input_Container.back());
	}

	size_t	Inserts = 1;
	size_t	jacobsthal_idx = 3;
	size_t	jacobsthal_prev = 1;
	size_t	jacobsthal_curr = 3;
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
	typedef std::deque<FJ_Pair*>::reverse_iterator	reverse_iterator;

	reverse_iterator	Iter_Pend = Seq_Pend.rbegin();
	while (Seq_Pend.size() > Inserts) {
		FJ_Pair*		Pair = *(Iter_Pend++);

		size_t		End = Seq_Main.size();
		BINARY_insert(Seq_Main, End, Pair, Comparisons);

		++Inserts;
	}
	return (Seq_Main);
}
std::deque<int>			FJ_sort(const std::deque<int>& Input_Container, int& Comparisons) {
	std::deque<FJ_Pair*>	Pairs;
	std::deque<int>		Numbers;

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

	if (Input_Container.size() == 1) {
		return (Input_Container);
	}
	if (Pairs.size() > 1) {
		Pairs = FJ_sort_pairs(Pairs, Comparisons);
	}

	std::deque<int>	Seq_Main;
	Seq_Main.push_back(Pairs[0]->numbers[0]);
	for (size_t i = 0; i < Pairs.size(); ++i) {
		Seq_Main.push_back(Pairs[i]->numbers[1]);
	}

	std::deque<int>	Seq_Pend;
	for (size_t i = 0; i < Pairs.size(); ++i) { /* NOTE(xenobas): Intentionally push the 1st element that already exists in the Seq_Main, so that we can skip it during jacobsthal binary insertion */
		Seq_Pend.push_back(Pairs[i]->numbers[0]);
	}

	bool			Rest = (Input_Container.size() % 2 == 1);
	if (Rest) {
		Seq_Pend.push_back(Input_Container.back());
	}

	size_t	Inserts = 1;
	size_t	jacobsthal_idx = 3;
	size_t	jacobsthal_prev = 1;
	size_t	jacobsthal_curr = 3;
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
	typedef std::deque<int>::reverse_iterator	reverse_iterator;

	reverse_iterator	Iter_Pend = Seq_Pend.rbegin();
	while (Seq_Pend.size() > Inserts) {
		int				Number = *(Iter_Pend++);

		size_t			End = Seq_Main.size();
		BINARY_insert(Seq_Main, End, Number, Comparisons);

		++Inserts;
	}
	return (Seq_Main);
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
std::vector<FJ_Pair*>	FJ_sort_pairs(const std::vector<FJ_Pair*> Input_Container, int& Comparisons) {
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
		Pairs = FJ_sort_pairs(Pairs, Comparisons);
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
	bool					Rest = (Input_Container.size() % 2 == 1);
	if (Rest) {
		Seq_Pend.push_back(Input_Container.back());
	}

	size_t	Inserts = 1;
	size_t	jacobsthal_idx = 3;
	size_t	jacobsthal_prev = 1;
	size_t	jacobsthal_curr = 3;
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
	typedef std::vector<FJ_Pair*>::reverse_iterator	reverse_iterator;

	reverse_iterator	Iter_Pend = Seq_Pend.rbegin();
	while (Seq_Pend.size() > Inserts) {
		FJ_Pair*		Pair = *(Iter_Pend++);

		size_t			End = Seq_Main.size();
		BINARY_insert(Seq_Main, End, Pair, Comparisons);

		++Inserts;
	}
	return (Seq_Main);
}
std::vector<int>		FJ_sort(const std::vector<int>& Input_Container, int& Comparisons) {
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

	if (Input_Container.size() == 1) {
		return (Input_Container);
	}
	if (Pairs.size() > 1) {
		Pairs = FJ_sort_pairs(Pairs, Comparisons);
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
	bool				Rest = (Input_Container.size() % 2 == 1);
	if (Rest) {
		Seq_Pend.push_back(Input_Container.back());
	}

	size_t	Inserts = 1;
	size_t	jacobsthal_idx = 3;
	size_t	jacobsthal_prev = 1;
	size_t	jacobsthal_curr = 3;
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
	typedef std::vector<int>::reverse_iterator	reverse_iterator;

	reverse_iterator	Iter_Pend = Seq_Pend.rbegin();
	while (Seq_Pend.size() > Inserts) {
		int				Number = *(Iter_Pend++);

		size_t		End = Seq_Main.size();
		BINARY_insert(Seq_Main, End, Number, Comparisons);

		++Inserts;
	}
	return (Seq_Main);
}

/* Time printer */
typedef struct { int64_t micros; }	Microsecond;
typedef struct { int64_t millis; }	Millisecond;
typedef struct { int64_t seconds; }	Second;
static Microsecond		timespec_diff(struct timespec& t0, struct timespec& t1) {
	int64_t	sec  = (int64_t)t1.tv_sec  - (int64_t)t0.tv_sec;
	int64_t	nsec = (int64_t)t1.tv_nsec - (int64_t)t0.tv_nsec;
	return ((Microsecond){ sec * 1000 * 1000 + nsec / 1000 });
}
std::ostream&			operator<<(std::ostream& stream, const Second& dur) {
	return (stream << dur.seconds << "s");
}
std::ostream&			operator<<(std::ostream& stream, const Millisecond& dur) {
	Second	dur_next = { dur.millis / 1000 };
	if (dur_next.seconds > 0) {
		return (stream << dur_next);
	}
	return (stream << dur.millis << "ms");
}
std::ostream&			operator<<(std::ostream& stream, const Microsecond& dur) {
	Millisecond	dur_next = { dur.micros / 1000 };
	if (dur_next.millis > 0) {
		return (stream << dur_next);
	}
	return (stream << dur.micros << "µs");
}

/* Entry Point */
int						abs(int x) {
	return ((x > 0) ? x : -x);
}
int						main(int argc, const char **argv) {
	// TODO(xenobas): Handle only one number
	// TODO(xenobas): Implement deque as well
	std::deque<int>		container_deq;
	std::vector<int>	container_vec;
	struct timespec		time_t0;
	struct timespec		time_t1;

	if (argc == 1) {
		std::cerr << "usage: " << argv[0] << " <integer>...\n";
		return (1);
	}
	if (!CLI_parse_numbers(&argv[1], argc - 1, container_vec, container_deq)) {
		return (2);
	}

	int					sorted_deq_ops = 0;
	clock_gettime(CLOCK_REALTIME, &time_t0);
	std::deque<int>		sorted_deq = FJ_sort(container_deq, sorted_deq_ops);
	clock_gettime(CLOCK_REALTIME, &time_t1);
	Microsecond			sorted_deq_msec = timespec_diff(time_t0, time_t1);

	int					sorted_vec_ops = 0;
	clock_gettime(CLOCK_REALTIME, &time_t0);
	std::vector<int>	sorted_vec = FJ_sort(container_vec, sorted_vec_ops);
	clock_gettime(CLOCK_REALTIME, &time_t1);
	Microsecond			sorted_vec_msec = timespec_diff(time_t0, time_t1);

	bool				sorted_ok = true;
	for (size_t i = 0; i + 1 < sorted_vec.size(); ++i) {
		if (sorted_vec[i + 0] >= sorted_vec[i + 1]) {
			std::cerr << "error: vector was not sorted properly" << '\n';
			sorted_ok = false;
			break ;
		}
	}
	if (sorted_vec.size() != container_vec.size()) {
		std::cerr << "error: vector lost or gained " << abs((int)sorted_vec.size() - (int)container_vec.size()) << " elements during sort\n";
		std::cerr << "\toriginal: " << container_vec << '\n';
		std::cerr << "\tsorted:   " << sorted_vec << '\n';
		sorted_ok = false;
	}
	for (size_t i = 0; i + 1 < sorted_deq.size(); ++i) {
		if (sorted_deq[i + 0] >= sorted_deq[i + 1]) {
			std::cerr << "error: deque was not sorted properly" << '\n';
			sorted_ok = false;
			break ;
		}
	}
	if (sorted_deq.size() != container_deq.size()) {
		std::cerr << "error: deque lost or gained " << abs((int)sorted_deq.size() - (int)container_deq.size()) << " elements during sort\n";
		std::cerr << "\toriginal: " << container_deq << '\n';
		std::cerr << "\tsorted:   " << sorted_deq << '\n';
		sorted_ok = false;
	}
	if (!sorted_ok) {
		return (8);
	}

	std::cout << "Before:\t" << container_vec << '\n';
	std::cout << "After:\t" << sorted_vec << '\n';

	std::cout << "Processing a range of " << container_vec.size() << " element" << (container_vec.size() == 1 ? " " : "s ") << " with std::vector took " << sorted_vec_msec << ", in " << sorted_vec_ops << " comparisons\n";
	std::cout << "Processing a range of " << container_deq.size() << " element" << (container_deq.size() == 1 ? " " : "s ") << " with std::deque  took " << sorted_deq_msec << ", in " << sorted_deq_ops << " comparisons\n";

	return (0);
}
