#ifndef DPOVEZANIPOPIS_H_
#define DPOVEZANIPOPIS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 20
#define SURNAME_NAME_SIZE 20
#define POSITION_SIZE 20

typedef struct player{
	char 	name[NAME_SIZE];
	char 	surname[SURNAME_NAME_SIZE];
	char 	position[POSITION_SIZE];
	int		goals;
	int 	assists;
	struct 	player *prev;
	struct 	player *next;
} player;

typedef struct PlayerList {
	player* head;
	player* tail;
} PlayerList;

PlayerList* PlayerListInitialize();
void PlayerListDestroy(PlayerList* list);
void PlayerListInsert(PlayerList* list, player* element);
void PlayerListDelete(PlayerList* list);
void PlayerListPrint  (PlayerList* list);
int  IsEmpty(PlayerList* list);
void SearchByPosition(PlayerList* playerlist, char *position);
void SortByGoals(PlayerList* list);
void SortByAssists(PlayerList* list);
#endif
