#include <stdio.h>
#include <stdlib.h>

#define MAX_DEPTH 10

#define MAIN_MENU 1
#define VEG_MENU 2
#define NON_VEG_MENU 3
#define CART_SCREEN 4

typedef struct {
    int screenIDs[MAX_DEPTH];
    int top;
} NavStack;

void pushScreen(NavStack *s, int screenID) {
    if (s->top < MAX_DEPTH - 1) {
        s->top++;
        s->screenIDs[s->top] = screenID;
    }
}

int popScreen(NavStack *s) {
    if (s->top > 0) { // Keep the root screen
        s->top--;
        return s->screenIDs[s->top];
    }
    return MAIN_MENU; // Fallback
}

void displayCurrentScreen(int screenID) {
    printf("\n-----------------------------------");
    switch(screenID) {
        case MAIN_MENU:
            printf("\n🏠 [MAIN MENU]\n1. Veg Items\n2. Non-Veg Items\n3. View Checkout Cart\n");
            break;
        case VEG_MENU:
            printf("\n🥗 [VEGETARIAN MENU]\n1. Paneer Tikka - Rs.120\n2. Veg Burger - Rs.80\n0. Go Back\n");
            break;
        case NON_VEG_MENU:
            printf("\n🍗 [NON-VEGETARIAN MENU]\n1. Chicken Roll - Rs.150\n2. Fish Fry - Rs.180\n0. Go Back\n");
            break;
        case CART_SCREEN:
            printf("\n🛒 [YOUR CART]\n(Displaying final items...)\n0. Go Back\n");
            break;
    }
    printf("-----------------------------------\n");
}

int main() {
    NavStack nav;
    nav.top = -1;
    
    int currentScreen = MAIN_MENU;
    pushScreen(&nav, currentScreen);
    
    int choice;
    
    while(1) {
        displayCurrentScreen(currentScreen);
        printf("Enter selection: ");
        scanf("%d", &choice);
        
        if (currentScreen == MAIN_MENU) {
            if (choice == 1) {
                currentScreen = VEG_MENU;
                pushScreen(&nav, currentScreen);
            } else if (choice == 2) {
                currentScreen = NON_VEG_MENU;
                pushScreen(&nav, currentScreen);
            } else if (choice == 3) {
                currentScreen = CART_SCREEN;
                pushScreen(&nav, currentScreen);
            } else {
                printf("Exiting application. Goodbye!\n");
                break;
            }
        } 
        // Sub-menus handling "Go Back" via 0
        else {
            if (choice == 0) {
                currentScreen = popScreen(&nav);
                printf("\n↩️ Returning to previous screen...\n");
            } else {
                printf("\n➕ Item processed successfully!\n");
            }
        }
    }
    return 0;
}
