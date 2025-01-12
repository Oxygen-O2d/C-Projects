#include <stdio.h>
#include <time.h>
#include <math.h>
#include <process.h>
#include <stdlib.h>

// Function prototypes
int randomnumber();   // Generates a random card number
int card(int number); // Converts a card number to its point value

// Global variables
int bet = 0;         // Player's current bet
float credits = 500; // Player's initial credits
int ptotal = 0;      // Player's total points
int dtotal = 0;      // Dealer's total points

// Function to handle drawing a card for the player
void player_card_no()
{
    int player_no = randomnumber();           // Get a random card number
    int player_card_number = card(player_no); // Get card value

    // Update player's total points based on card drawn
    if (player_no == 1)
    {
        ptotal += player_card_number; // Ace handling
        printf("\nYou got the Ace card, Total points is %d", ptotal);
    }
    else if (player_no >= 2 && player_no <= 10)
    {
        ptotal += player_card_number;
        printf("\nYou got a face %d card, Total points is %d", player_no, ptotal);
    }
    else if (player_no >= 11)
    {
        // Face cards (Jack, Queen, King)
        if (player_no == 11)
        {
            ptotal += player_card_number;
            printf("\nYou got the Jack card, Total points is %d", ptotal);
        }
        if (player_no == 12)
        {
            ptotal += player_card_number;
            printf("\nYou got the Queen card, Total points is %d", ptotal);
        }
        if (player_no == 13)
        {
            ptotal += player_card_number;
            printf("\nYou got the King card, Total points is %d", ptotal);
        }
    }
}

// Function to handle drawing a card for the dealer
void dealer_card_no()
{
    int dealer_no = randomnumber();           // Get a random card number
    int dealer_card_number = card(dealer_no); // Get card value

    // Update dealer's total points based on card drawn
    if (dealer_no == 1)
    {
        dtotal += dealer_card_number; // Ace handling
        printf("\nDealer got the Ace card, Total points is %d", dtotal);
    }
    else if (dealer_no >= 2 && dealer_no <= 10)
    {
        dtotal += dealer_card_number;
        printf("\nDealer got the %d card, Total points is %d", dealer_no, dtotal);
    }
    else if (dealer_no >= 11)
    {
        // Face cards (Jack, Queen, King)
        if (dealer_no == 11)
        {
            dtotal += dealer_card_number;
            printf("\nDealer got the Jack card, Total points is %d", dtotal);
        }
        if (dealer_no == 12)
        {
            dtotal += dealer_card_number;
            printf("\nDealer got the Queen card, Total points is %d", dtotal);
        }
        if (dealer_no == 13)
        {
            dtotal += dealer_card_number;
            printf("\nDealer got the King card, Total points is %d", dtotal);
        }
    }
}

// Function to determine the winner of the game
void Winner()
{
    if (ptotal == 21 && dtotal != 21)
    {
        printf("Player Wins!");
        credits += (bet * 1.5); // Blackjack payout
    }
    else if (dtotal == 21 && ptotal != 21)
    {
        printf("Dealer Wins");
        credits -= bet; // Player loses bet
    }
    else if (dtotal == 21 && ptotal == 21)
    {
        printf("Draw");
    }
    else if (ptotal > dtotal && ptotal < 21)
    {
        printf("Player wins!");
        credits += (bet * 1.5); // Player wins
    }
    else if (dtotal > ptotal && dtotal < 21)
    {
        printf("Dealer Wins!");
        credits -= bet; // Player loses
    }
    else if (ptotal > 21)
    {
        printf("Dealer Wins!"); // Player busts
        credits -= bet;         // Player loses bet
    }
    else if (dtotal > 21)
    {
        printf("Player Wins");  // Dealer busts
        credits += (bet * 1.5); // Player wins
    }
}

// Function to return the point value of a card based on its number
int card(int number)
{
    if (number == 1)
    {
        return 11; // Ace is worth 11 points
    }
    if (number >= 2 && number <= 10)
    {
        return number; // Numbered cards are worth their face value
    }
    return 10; // Face cards (Jack, Queen, King) are worth 10 points
}

// Function to generate a random card number (1-13)
int randomnumber()
{
    static int seeded = 0; // Static variable to ensure random seed is set only once
    if (!seeded)
    {
        srand((unsigned)time(NULL)); // Seed the random number generator
        seeded = 1;
    }
    return rand() % 13 + 1; // Generate random number between 1 and 13
}

// Function to display the rules of Blackjack
void Rules()
{
    printf("Blackjack Rule\n");
    printf("Objective: Beat the dealer's hand by getting a total value closest to 21 without exceeding it.\n\n");
    printf("Card Values:\n");
    printf("Numbered cards (2-10) are worth their face value.\n");
    printf("Jacks, Queens, and Kings are worth 10 points each.\n");
    printf("Aces can be worth either 1 or 11 points, depending on which is more beneficial to the player.\n\n");
    printf("Gameplay:\n");
    printf("Initial Deal: Each player receives two cards face up, and the dealer receives one card face up (the \"upcard\") and one card face down (the \"hole card\").\n");
    printf("Player's Turn: Based on the value of their hand, players can choose to:\n");
    printf("Hit: Take an additional card to try to get closer to 21 or beat the dealer's hand.\n");
    printf("Stand: Keep their current hand and end their turn.\n");
    printf("Double Down: Double their initial bet and receive one more card, but cannot hit again after that.\n");
    printf("Split: If the initial two cards have the same value, split them into two separate hands, each with a separate bet. Players can hit or stand on each hand separately.\n\n");
    printf("Dealer's Turn: After all players have finished their turns, the dealer reveals their hole card and follows a set of predetermined rules:\n");
    printf("If the dealer's upcard is an Ace, they may offer \"insurance\" to players, allowing them to bet half their initial bet that the dealer has a Blackjack (Ace and a 10-value card). If the dealer does have a Blackjack, insurance wins 2:1.\n");
    printf("If the dealer's hand value is 16 or less, they must draw another card.\n");
    printf("If the dealer's hand value is 17 or more, they must stand.\n\n");
    printf("Winning and Losing: If a player's hand value is higher than the dealer's hand without exceeding 21, they win even money (1:1) on their bet. If the player's hand value exceeds 21, they \"bust\" and lose their bet. If the dealer's hand value exceeds 21, all remaining players win even money on their bets.\n\n");
    printf("Additional Rules:\n");
    printf("Blackjack: If a player's initial two cards have a total value of 21 (e.g., an Ace and a 10-value card), they have a Blackjack and win 3:2 (or 6:5 in some casinos) on their bet, unless the dealer also has a Blackjack.\n");
    printf("Surrender: Some casinos offer surrender, allowing players to give up their hand and lose half their bet. Early surrender, where players can surrender before the dealer checks for a Blackjack, is less common.\n");
    printf("Side Bets: Some casinos offer additional side bets, such as Perfect Pairs, TriLux, or 21+3, which can have varying payouts and rules. These bets are separate from the main Blackjack game and are not recommended as they have a significant house edge.\n");
}

// Function to display help commands
void help()
{
    printf("Commands: \n");
    printf("H: To Hit, take card\n");
    printf("S: To Stay, reveal cards\n");
}

// Main function
int main()
{
    int opt; // Variable for menu option selection

    do
    {
        // Display menu options
        printf("\n\n[1] Begin the game!\n");
        printf("[2] See the Rules!\n");
        printf("[3] See the Commands\n");
        printf("Select: ");
        scanf("%d", &opt); // Get user selection

        switch (opt)
        {
        case 1:
        {
            char start, choice2; // Variables for user input
            printf("You sure you want to continue, If continue press Y/N: ");
            scanf(" %c", &start); // Add space to handle newline

            if (start == 'Y')
            {
                do
                {
                    ptotal = 0; // Reset player total points
                    dtotal = 0; // Reset dealer total points
                    if (credits > 0)
                    {
                        printf("You have %.2f credits\n", credits);
                        printf("Enter Your Bet Amount: ");
                        scanf("%d", &bet); // Get player's bet

                        player_card_no(); // Draw player's card
                        dealer_card_no(); // Draw dealer's card

                        printf("\n\nDealer has %d points and You have %d points", dtotal, ptotal);
                        char choice; // Variable for hit/stay choice

                        do
                        {
                            printf("\nHit Or Stay: ");
                            scanf(" %c", &choice); // Get player's choice

                            if (choice == 'H')
                            {
                                player_card_no(); // Draw another card for player

                                // Check for bust conditions
                                if (ptotal > 21 && dtotal < 21)
                                {
                                    printf("\nDealer Wins!");
                                    credits -= bet; // Player loses bet
                                    printf("\nYour new credits is $%.2f \n", credits);
                                    break;
                                }
                                else if(ptotal == 21 && dtotal < 21){
                                    printf("\nPlayer Wins!");
                                    credits += (bet*1.5);
                                    break;
                                }
                                dealer_card_no(); // Dealer draws card after player hits

                                // Check for dealer bust
                                if (dtotal > 21 && ptotal < 21)
                                {
                                    printf("\nPlayer Wins");
                                    credits += (bet * 1.5); // Player wins
                                    printf("\nYour new credits is $%.2f \n", credits);
                                    break;
                                }
                                else if(dtotal == 21 && ptotal < 21){
                                    printf("\nDealer Wins!");
                                    credits -= bet;
                                    break;
                                }
                            }
                            else if (choice == 'S')
                            {
                                Winner(); // Check the winner when player stands
                                break;
                            }
                            else
                            {
                                printf("Invalid input!"); // Handle invalid input
                                break;
                            }
                        } while (choice == 'H'); // Continue hitting if player chooses 'H'

                        printf("Wanna Play More (Y/N): ");
                        scanf(" %c", &choice2); // Check if player wants to continue
                    }
                    else
                    {
                        printf("You have Zero Credits!"); // Notify player of no credits
                        break;
                    }
                } while (choice2 == 'Y'); // Repeat game if player chooses to continue
            }
            break;
        }
        case 2:
            Rules(); // Show the rules of the game
            break;
        case 3:
            help(); // Show the commands for gameplay
            break;
        default:
            printf("Invalid Option\n"); // Handle invalid menu option
            break;
        }
    } while (opt == 1 && opt == 2 && opt == 3); // Loop until a valid option is selected

    return 0; // Exit the program
}
