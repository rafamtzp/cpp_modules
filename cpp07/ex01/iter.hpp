#pragma once

template <typename T, typename F>
void	iter(T *addr, const int len, F f)
{
	for (int i = 0; i < len; i++)
		f(addr[i]);
	return ;
}
