#include "checker.h"

t_instruction	ft_str_to_instruction(const char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		return (Ins_Swap_A);
	if (ft_strcmp(str, "sb") == 0)
		return (Ins_Swap_B);
	if (ft_strcmp(str, "ss") == 0)
		return (Ins_Swap_Both);
	if (ft_strcmp(str, "pa") == 0)
		return (Ins_Push_A);
	if (ft_strcmp(str, "pb") == 0)
		return (Ins_Push_B);
	if (ft_strcmp(str, "ra") == 0)
		return (Ins_Rotate_A);
	if (ft_strcmp(str, "rb") == 0)
		return (Ins_Rotate_B);
	if (ft_strcmp(str, "rr") == 0)
		return (Ins_Rotate_Both);
	if (ft_strcmp(str, "rra") == 0)
		return (Ins_Reverse_Rotate_A);
	if (ft_strcmp(str, "rrb") == 0)
		return (Ins_Reverse_Rotate_B);
	if (ft_strcmp(str, "rrr") == 0)
		return (Ins_Reverse_Rotate_Both);
	return (Ins_Invalid);
}
