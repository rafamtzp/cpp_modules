#include <algorithm>
#include "easyfind.hpp"

template <typename T>
typename T::iterator	easyfind(T cont, int tofind)
{
	typename T::iterator it = std::find(cont.begin(), cont.end(), tofind));
	if (it == cont.end())
		throw NotFoundException();
	return it;
}