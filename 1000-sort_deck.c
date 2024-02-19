#include "deck.h"

int convert_to_int(const char *card_name)
{
	int i;

	value_num values[14] = {
		{"Ace", 1}, {"2", 2}, {"3", 3}, {"4", 4},
		{"5", 5}, {"6", 6}, {"7", 7}, {"8", 8},
		{"9", 9}, {"10", 10}, {"Jack", 11}, {"Queen", 12},
		{"King", 13}, {NULL, -1}
	};
	for (i = 0; values[i].valuename != NULL; i++)
	{
		if (strcmp(card_name, values[i].valuename) == 0)
			return (values[i].valuenum);
	}
	return (-1);
}

void sort_by_type(deck_node_t **deck)
{
	deck_node_t *comp1, *comp2, *setbegin;
	int i, j, k;

        setbegin = *deck;
	for (i = 0, setbegin = (*deck); i < 4; i++)
	{
		printf("%d\n", i);
		for (j = 12; j > 0; j--)
		{
			comp1 = setbegin;
			comp2 = setbegin->next;
			for (k = 0; k < j; k++)
			{
				if (comp2->card->kind > setbegin->card->kind)
					break;
				if (convert_to_int(comp1->card->value) >
				    convert_to_int(comp2->card->value))
				{
					if (comp1->prev == NULL)
					{
						*deck = comp2;
						setbegin = comp2;
					}
					comp1->next = comp2->next;
					comp2->prev = comp1->prev;
					comp1->prev = comp2;
					comp2->next = comp1;
					if (comp2->prev)
						comp2->prev->next = comp2;
					if (comp1->next)
						comp1->next->prev = comp1;
					comp2 = comp1->next;
				}
				else
				{
					comp1 = comp1->next;
					comp2 = comp2->next;
				}
			}
			print_deck(*deck);
		}
		while (strcmp(comp1->card->value, "King") != 0)
			comp1 = comp1->next;
		setbegin = comp1->next;
		printf("%s = %d\n", setbegin->card->value, setbegin->card->kind);
	}

}

void sort_by_kind(deck_node_t **deck)
{
	deck_node_t *comp1, *comp2;
	int i, j;

	for (i = 51; i > 0; i--)
	{
		comp1 = *deck;
		comp2 = (*deck)->next;

		for (j = 0; j < i; j++)
		{
			if (comp1->card->kind > comp2->card->kind)
			{
				if (comp1->prev == NULL)
					*deck = comp2;
				comp1->next = comp2->next;
				comp2->prev = comp1->prev;
				comp1->prev = comp2;
				comp2->next = comp1;
				if (comp2->prev)
					comp2->prev->next = comp2;
				if (comp1->next)
					comp1->next->prev = comp1;
				comp2 = comp1->next;
			}
			else
			{
				comp1 = comp1->next;
				comp2 = comp2->next;
			}
		}
	}
}

void sort_deck(deck_node_t **deck)
{
	sort_by_kind(deck);
	sort_by_type(deck);
}
