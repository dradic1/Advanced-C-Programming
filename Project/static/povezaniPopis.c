#include "povezaniPopis.h"
#include  <string.h>

PlayerList* PlayerListInitialize()
{
	   PlayerList* newList = (PlayerList*)malloc(sizeof(PlayerList));
	    if (newList == NULL) {
	        printf("Memory allocation failed.\n");
	        exit(EXIT_FAILURE);
	    }

	    newList->head = NULL;
	    newList->tail = NULL;

	    return newList;
}

void PlayerListInsert(PlayerList* list, player* element)
{
		player* newPlayer = (player*)malloc(sizeof(player));
	    if (newPlayer == NULL) {
	        printf("Memory allocation failed.\n");
	        exit(EXIT_FAILURE);
	    }

	    strcpy(newPlayer->name, element->name);
	    strcpy(newPlayer->surname, element->surname);
	    strcpy(newPlayer->position, element->position);
	    newPlayer->assists = element->assists;
	    newPlayer->goals = element->goals;
	    newPlayer->next = list->head;
	    newPlayer->prev = list->tail;

	    if (list->head == NULL) {

	        list->head = newPlayer;
	        list->tail = newPlayer;


	    } else {

	        list->tail->next = newPlayer;
	        list->head->prev = newPlayer;
	        list->tail = newPlayer;
	    }
}

void PlayerListDestroy(PlayerList* list) {

		player* current = list->head;
		player* next;

		do {
	        	next = current->next;
	        	free(current);
	        	current = next;
		} while (current != list->head);

		free(list);
}

void PlayerListDelete(PlayerList* list) {

    	player* current = list->head;
    	player* next;

    	do {
    		next = current->next;
    		free(current);
    		current = next;
    	} while (current != list->head);

    	list->head = NULL;
    	list->tail = NULL;
}

void PlayerListPrint(PlayerList* list)
{
    if (IsEmpty(list)) {
	        printf("List is empty.\n");
	        return;
	    }

	player* current = list->head;
	    do {
	    	printf("Name: %s, Surname: %s, Position: %s, Goals: %d, Assists: %d\n", current->name,current->surname,current->position,current->goals,current->assists);
	        current = current->next;
	    } while (current != list->head);
}

int  IsEmpty(PlayerList* list)
{
		return list->head == NULL;
}

void SearchByPosition(PlayerList* list, char *position)
{
    if (IsEmpty(list)) {
	        printf("List is empty.\n");
	        return;
	    }

	player* current = list->head;
	int found=0;
	do
	{
		if(strcmp(current->position,position)==0)
		{
			printf("Name: %s, Surname: %s, Position: %s, Goals: %d, Assists: %d\n", current->name,current->surname,current->position,current->goals,current->assists);
			found++;
		}
		current=current->next;

	}while(current != list->head);
	if(found==0)
	{
		printf("There is no player in that position!\n");
	}
}

void SortByGoals(PlayerList* list) {
    if (IsEmpty(list)) {
        printf("List is empty.\n");
        return;
    }

    player* current = list->head;
    player* end = list->tail;

    while (current != end) {
        player* max = current;
        player* temp = current->next;

        while (temp != list->head) {
            if (temp->goals > max->goals) {
                max = temp;
            }
            temp = temp->next;
        }

        if (max != current) {

            if (current->prev)
                current->prev->next = max;
            if (max->prev)
                max->prev->next = current;
            if (current->next)
                current->next->prev = max;
            if (max->next)
                max->next->prev = current;

            player* tempNext = current->next;
            player* tempPrev = current->prev;
            current->next = max->next;
            current->prev = max->prev;
            max->next = tempNext;
            max->prev = tempPrev;

            if (list->head == current)
                list->head = max;
            else if (list->head == max)
                list->head = current;
            if (list->tail == current)
                list->tail = max;
            else if (list->tail == max)
                list->tail = current;
        }

        current = current->next;
    }
}

void SortByAssists(PlayerList* list) {
    if (IsEmpty(list)) {
        printf("List is empty.\n");
        return;
    }

    player* current = list->head;
    player* end = list->tail;

    while (current != end) {
        player* max = current;
        player* temp = current->next;

        while (temp != list->head) {
            if (temp->assists > max->assists) {
                max = temp;
            }
            temp = temp->next;
        }

        if (max != current) {

            if (current->prev)
                current->prev->next = max;
            if (max->prev)
                max->prev->next = current;
            if (current->next)
                current->next->prev = max;
            if (max->next)
                max->next->prev = current;

            player* tempNext = current->next;
            player* tempPrev = current->prev;
            current->next = max->next;
            current->prev = max->prev;
            max->next = tempNext;
            max->prev = tempPrev;

            if (list->head == current)
                list->head = max;
            else if (list->head == max)
                list->head = current;
            if (list->tail == current)
                list->tail = max;
            else if (list->tail == max)
                list->tail = current;
        }

        current = current->next;
    }
}
