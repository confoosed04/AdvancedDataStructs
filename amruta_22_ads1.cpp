#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coef;
    int exp;
    struct node* next;
};

struct node* createTerm(int coef, int exp) 
{
    struct node* newTerm = (struct node*)malloc(sizeof(struct node));
    newTerm->coef = coef;
    newTerm->exp = exp;
    newTerm->next = NULL;
    return newTerm;
}

void addTerm(struct node** poly, int coef, int exp) 
{
    struct node* newTerm = createTerm(coef, exp);

    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        struct node* temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTerm;
    }
}

void inputPoly(struct node** poly) 
{
    int coef, exp;
    char choice;

    do {
        printf("Enter coefficient: ");
        scanf("%d", &coef);

        printf("Enter exponent: ");
        scanf("%d", &exp);

        addTerm(poly, coef, exp);

        printf("Do you want to add another term? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
}

void displayPoly(struct node* poly) 
{
    if (poly == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

    struct node* temp = poly;
    while (temp != NULL) {
        printf("%dx^%d", temp->coef, temp->exp);
        temp = temp->next;

        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

struct node* addPoly(struct node* poly1, struct node* poly2) 
{
    struct node* result = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        int coef1 = (poly1 != NULL) ? poly1->coef : 0;
        int exp1 = (poly1 != NULL) ? poly1->exp : 0;
        int coef2 = (poly2 != NULL) ? poly2->coef : 0;
        int exp2 = (poly2 != NULL) ? poly2->exp : 0;

        int sumCoef = coef1 + coef2;
        addTerm(&result, sumCoef, exp1);

        if (poly1 != NULL) {
            poly1 = poly1->next;
        }
        if (poly2 != NULL) {
            poly2 = poly2->next;
        }
    }

    return result;
}


int main() 
{
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;

    printf("Enter terms for the first polynomial:\n");
    inputPoly(&poly1);

    printf("Enter terms for the second polynomial:\n");
    inputPoly(&poly2);

    printf("First Polynomial: ");
    displayPoly(poly1);

    printf("Second Polynomial: ");
    displayPoly(poly2);

    struct node* result = addPoly(poly1, poly2);

    printf("Resultant Polynomial: ");
    displayPoly(result);

   
    return 0;
}
