#include "monty.h"

/**
 * m_get_int - get char pointer 
 * @num: number convert to string
 * Return: char pointer null if fails and malloc.
 */
char *m_get_int(int num)
{
	long num_v = 0;
	unsigned int tmp;
	int len = 0;
	char *ret;

	tmp = m_abs_m(num);
	len = m_len_buff_uint(tmp, 10);

	if (num < 0 || num_v < 0)
		len++;
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);

	m_full_buff(tmp, 10, ret, len);
	if (num < 0 || num_v < 0)
		ret[0] = '-';

	return (ret);
}
/**
 * m_abs_m - abs  of int
 * @i: integer 
 * Return: unsigned  i
 */
unsigned int m_abs_m(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}
/**
 * m_len_buff_uint - length of buff 
 * @num: number 
 * @base: base of number representation use
 * Return: int 
 */
int m_len_buff_uint(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}
/**
 * m_full_buff - complete buff 
 * @num: num to convert to string
 * @base: b num
 * @buff: buffer  completed
 * @buff_size:  buffer size
 * Return: void.
 */
void m_full_buff(unsigned int num, unsigned int base, char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9)
			buff[i] = rem + 87;
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}

/**
 * m_isdigit - Entry point
 *
 * Return:   1 else 0
 */
int m_isdigit(void)
{
	int i = 0;

	if (globalvar.token2[0] == '-' || globalvar.token2[0] == '+')
		i++;
	while (globalvar.token2[i])
	{

		if (isdigit(globalvar.token2[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
