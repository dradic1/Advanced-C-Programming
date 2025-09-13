
#include <stdio.h>
#include <stdlib.h>
#include "povezaniPopis.h"


void PrintMenu() {
    printf("\nFootball team statistics\n");
    printf("\n1. Add player\n");
    printf("2. Print all players\n");
    printf("3. Overview of players by position\n");
    printf("4. Sort players by number of assists\n");
    printf("5. Sort players by number of goals\n");
    printf("6. Delete all players\n");
    printf("7. Exit\n");
    printf("\nNote: Enter at least two players to use the functions.\n");
    printf("\nSelect an option: ");
}

int main() {
    PlayerList* playersList = PlayerListInitialize();
    int choice;

    do {
        PrintMenu();
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: {
                struct player newPlayer;
                printf("Enter name: ");
                scanf("%s", newPlayer.name);
                printf("Enter surname: ");
                scanf("%s", newPlayer.surname);
                printf("Enter the position: ");
                scanf("%s", newPlayer.position);
                printf("Enter number of goals: ");
                scanf("%d", &newPlayer.goals);
                printf("Enter number of assists: ");
                scanf("%d", &newPlayer.assists);
                PlayerListInsert(playersList, &newPlayer);
                printf("Player added!\n");
                break;
            }
            case 2:
                printf("All players:\n");
                PlayerListPrint(playersList);
                break;
            case 3: {
                char position[POSITION_SIZE];
                printf("Enter position for review: ");
                scanf("%s", position);
                SearchByPosition(playersList, position);
                break;
            }
            case 4:
                SortByAssists(playersList);
                printf("Players sorted by number of assists:\n");
                PlayerListPrint(playersList);
                break;
            case 5:
                SortByGoals(playersList);
                printf("Players sorted by number of goals:\n");
                PlayerListPrint(playersList);
                break;
            case 6:
                PlayerListDelete(playersList);
                printf("All players deleted!\n");
                break;
            case 7:
                printf("Exit the program.\n");
                break;
            default:
                printf("Invalid entry! Please select an option between 1 and 7.\n");
        }
    } while (choice != 7);

    PlayerListDestroy(playersList);
    return 0;
}
