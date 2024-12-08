#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void show_bal(int balance);
void roulette(int *balance);
void blackjack(int *balance);
void slots(int *balance);
void cf(int *balance);

int main()
{
    int balance, choice;

    srand(time(NULL));

    printf("Welcome to Casino!\n\n");
    printf("Enter your initial balance: ");
    scanf("%d", &balance);

    while (1)
    {
        printf("Current balance: %d\n", balance);
        printf("Choose a game!\n");
        printf("1. Roulette.\n");
        printf("2. Blackjack.\n");
        printf("3. Slots.\n");
        printf("4. Coin Flip\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            roulette(&balance);
            break;

        case 2:
            blackjack(&balance);
            break;

        case 3:
            slots(&balance);
            break;

        case 4:
            cf(&balance);
            break;

        case 5:
            printf("Thank you for playing, Your balance is: %d\n", balance);
            return 0;    

        default:
            printf("Invalid choice, Please try again. \n\n");
        }
    }    

}

void show_bal(int balance)
{
    printf("Your current balance is: %d\n\n\n", balance);
}

//ROULETTE GAME!!

void roulette(int *balance)
{
    int guess, winnumber, bet;

    printf("<---Roulette--->\n\n");
    printf("Rules for Roulette:\n");
    printf("1. Guessing the Right Number: The player chooses a number between 0 and 18. If the randomly generated number matches the player's guess, they win a payout of bet * 18.\n");
    printf("2. Betting and Losing: If the player's guess does not match the randomly generated number, they lose the amount they bet.\n");
    printf("3. Range of Possible Outcomes: The random number generated is between 0 and 18, inclusive, representing 19 possible outcomes for each round of the game.\n\n");
    
    printf("Enter your bet: ");
    scanf("%d", &bet);

    if(bet > *balance || bet <= 0 )
    {
        printf("Invalid bet amount. Please try again.\n\n");
        return;
    }

    printf("Choose a number from the range 0-18 : ");
    scanf("%d", &guess);

    if (guess < 0 || guess > 18)
    {
        printf("Invalid number, please try again.\n\n");
        return;
    }

    winnumber = rand() % 19;
    printf("Winning number is: %d\n", winnumber);

    if (guess == winnumber)
    {
        printf("Congratulations!! You win! \n");
        *balance = *balance + bet*18;
    }

    else
    {
        printf("You lose! Better luck next time!\n");
        *balance = *balance - bet;
    }

    show_bal(*balance);   
}

//BLACKJACK GAME!!

void blackjack(int *balance)
{
    int player_card, dealer_card, bet;

    printf("<---BlackJack--->\n\n");
    printf("Rules for BlackJack:\n");
    printf("1. Betting Rule: The player must place a bet before each round, and the bet cannot exceed their current balance or be less than or equal to zero.\n");
    printf("2. Card Values: Both the player and the dealer are randomly assigned a card value between 1 and 21. The player and dealer compare their cards, and the one with the higher card wins.\n");
    printf("3. Winning Rule: If the player's card value is greater than the dealer's, they win the round and gain the amount they bet.\n");
    printf("4. Losing Rule: If the dealer's card value is greater than the player's, the player loses their bet, and the balance is reduced accordingly.\n");
    printf("5. Draw Rule: If the player and dealer have the same card value, the round is a draw, and there is no change in the player's balance.\n\n");
    
    printf("Enter your bet: ");
    scanf("%d", &bet);

    if (bet > *balance || bet <= 0) 
    {
        printf("Invalid bet amount. Please try again.\n\n");
        return;
    }

    player_card = rand() % 21+1;
    dealer_card = rand() % 21+1;

    printf("Your card: %d\n", player_card);
    printf("Dealer's card: %d\n", dealer_card);

    if (player_card > dealer_card)
    {
        printf("Congratulations! You win!\n");
        *balance = *balance + bet;
    }
    else if (player_card < dealer_card)
    {
        printf("You Lose. Better luck next time!\n");
        *balance = *balance - bet;
    }
    else
    {
        printf("It's a draw! no gain or loss\n");
    }
    
    show_bal(*balance);
}

//SLOTS GAME!!

void slots(int *balance)
{
    int bet, s1, s2, s3;

    printf("<---SLOTS--->\n\n");
    printf("Rules for Slots.\n");
    printf("1. Betting Rule: The player must place a bet before spinning the slots. The bet cannot exceed their current balance or be less than or equal to zero.\n");
    printf("2. Slot Spin: Three random values are generated for the three slots (ranging from 0 to 10), and the results are displayed to the player.\n");
    printf("3. Jackpot Rule: If all three slots match (e.g., 3 | 3 | 3), the player wins the jackpot and receives 10 times the amount they bet.\n");
    printf("4. Partial Match Rule: If any two slots match (e.g., 3 | 3 | 1), the player wins half their bet.\n");
    printf("5. No Match Rule: If none of the slots match (e.g., 3 | 1 | 2), the player loses their bet, and their balance is reduced accordingly.\n\n");

    printf("Enter your bet: ");
    scanf("%d", &bet);

    if (bet > *balance || bet <= 0) 
    {
        printf("Invalid bet amount. Please try again.\n\n");
        return;
    }

    s1 = rand() % 11;
    s2 = rand() % 11;
    s3 = rand() % 11;

    printf("Slot Results: %d | %d | %d\n", s1,s2,s3);

    if (s1 == s2 && s2 == s3)
    {
        printf("Congratulations! You won a JACKPOT!!!\n");
        *balance = *balance + bet * 10;
    }
    else if (s1 == s2 || s2 == s3 || s1 == s3)
    {
        printf("Congrats! You win half your bet!\n");
        *balance = *balance + bet / 2;
    }
    else
    {
        printf("You lose. Better luck next time!\n");
        *balance = *balance - bet;
    }

    show_bal(*balance);
}

//COIN FLIP 


void cf(int *balance)
{
    int bet, choice, result;

    printf("<---Coin Flip--->\n\n");
    printf("Rules for Coin Flip:\n");
    printf("1. The player bets on either 'Heads' or 'Tails'. \n");
    printf("2. A coin is flipped, and the outcome is randomly determined. \n");
    printf("3. If the player's guess matches the outcome, they win ddouble their bet.\n");
    printf("4. If the player's guess does not match, they lose the bet.\n\n");

    printf("Enter your bet: ");
    scanf("%d", &bet);

    if (bet > *balance || bet <= 0)
    {
        printf("Invalid bet amount. Please try again. \n\n");
        return;
    }

    printf("Choose your bet:\n");
    printf("1. Heads\n");
    printf("2. Tails\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);


    if(choice != 1 && choice != 2)
    {
        printf("Invalid choice! Please slect 1 for Heads or 2 for Tails. \n\n");
        return;
    }

    result = rand() % 2+1;

    if(result == 1)
    {
        printf("Coin Flip result: Heads\n");
    }
    else
    {
        printf("Coin Flip result: Tails\n");
    }

    if(choice == result)
    {
        printf("Congratulations! You win!\n");
        *balance = *balance + bet;
    }
    else
    {
        printf("You lose! Better luck next time.\n");
        *balance = *balance - bet;
    }

    show_bal(*balance);

}