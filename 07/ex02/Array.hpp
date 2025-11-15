/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 10:25:47 by aindjare          #+#    #+#             */
/*   Updated: 2025/11/15 13:14:34 by xenobas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <stdexcept>
template <typename T>
class Array {
private:
	T*		elements;
	size_t	len;

public:
	Array(void): elements(0), len(0) { };
	Array(const Array& arr) {
		this->elements = 0;
		this->len = 0;
		if (arr.len > 0) {
			this->elements = new T[arr.len]();
			this->len = arr.len;

			for (size_t i = 0; i < this->len; ++i)
				this->elements[i] = arr.elements[i];
		}
	}
	Array& operator=(const Array& arr) {
		delete[] this->elements;

		this->elements = 0;
		this->len = 0;
		if (arr.len > 0) {
			this->elements = new T[arr.len]();
			this->len = arr.len;

			for (size_t i = 0; i < this->len; ++i)
				this->elements[i] = arr.elements[i];
		}
	}
	~Array(void) {
		delete[] this->elements;

		this->elements = 0;
		this->len = 0;
	};

	Array(unsigned int n): elements(new T[n]()), len((size_t)n) { };

	size_t	size(void) const {
		return (this->len);
	};

	T&	operator[](size_t index) {
		if (index >= this->len)
			throw std::out_of_range("Out of bounds access");
		return (this->elements[index]);
	}
	const T&	operator[](size_t index) const {
		return ((*this)[index]);
	}
};
#endif
