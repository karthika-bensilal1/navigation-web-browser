#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char url[100];
    struct Node* prev;
    struct Node* next;
};
struct Node* create(char* url) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url, url);
    newNode->prev = newNode->next = NULL;
    return newNode;
}
void visit(struct Node** current, char* url) {
    struct Node* newPage = create(url);

    if (*current != NULL) {
        struct Node* temp = (*current)->next;
        while (temp != NULL) {
            struct Node* Delete = temp;
            temp = temp->next;
            free(Delete);
        }
        (*current)->next = newPage;
        newPage->prev = *current;
    }
    *current = newPage;
    printf("Visited: %s\n", (*current)->url);
}
void Forward(struct Node** current) {
    if (*current != NULL && (*current)->next != NULL) {
        *current = (*current)->next;
        printf("Forward to: %s\n", (*current)->url);
    } else {
        printf("No forward page\n");
    }
}
void Back(struct Node** current) {
    if (*current != NULL && (*current)->prev != NULL) {
        *current = (*current)->prev;
        printf("Back to: %s\n", (*current)->url);
    } else {
        printf("No previous page\n");
    }
}
int main() {
    struct Node* current = NULL;
    int choice;
    char url[100];
    while (1) {
        printf("\n1. Visit Page\n2. Back\n3. Forward\n4. Current Page\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%s", url);
                visit(&current, url);
                break;
            case 2:
                Back(&current);
                break;
            case 3:
                Forward(&current);
                break;
            case 4:
                if (current != NULL)
                    printf("Current Page: %s\n", current->url);
                else
                    printf("No page visited yet!\n");
                break;
            case 5:
                printf("Exiting....\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
