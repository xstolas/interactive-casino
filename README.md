# **Interactive Casino**  
The **Interactive Casino** is a C programming project that simulates the thrill of a virtual casino environment. It features four classic casino games—Roulette, Blackjack, Slots, and Coin Flip, allowing users to place bets, test their luck, and manage their virtual balance. This project showcases modular programming, dynamic memory management, and random number generation in C.  

## **Project Features**  
- **Roulette**: Bet on a number between 0 and 18. Win 18x the bet for correct guesses.  
- **Blackjack**: Compete against the dealer to achieve a higher card value without exceeding 21.  
- **Slots**: Spin three reels and win based on matching patterns, including a jackpot for all three matching.  
- **Coin Flip**: Bet on heads or tails, and double your bet on a correct guess.  

## **Contribution**  
### **Roulette Game**  
As a contributor to the Interactive Casino project, I was responsible for implementing the **Roulette** game function. My tasks included:  
- Developing the game mechanics to allow players to guess a number between 0 and 18.  
- Using `rand()` seeded with `srand(time(NULL))` to generate a random winning number, ensuring fairness and unpredictability.  
- Validating user inputs for bets and guesses to prevent invalid entries.  
- Implementing winning and losing scenarios with corresponding updates to the player’s balance, managed using pointer arithmetic.  
- Adding clear game rules and feedback messages to enhance the user experience.  

This module demonstrates key programming concepts such as randomization, input validation, and dynamic memory management in C.

### **Code Snippet**
```
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
```

## **How to Run the Program**  
1. Clone the repository:  
   ```bash  
   git clone https://github.com/xstolas/interactive-casino.git  
   ```  
2. Navigate to the project directory:  
   ```bash  
   cd interactive-casino
   ```  
3. Compile the program using GCC or another C compiler:  
   ```bash  
   gcc casino.c -o casino  
   ```  
4. Run the program:  
   ```bash  
   ./casino  
   ```  

## **Technologies Used**  
- **Programming Language**: C  
- **Libraries**:  
  - `<stdio.h>`: Input and output functions  
  - `<stdlib.h>`: Random number generation and memory management  
  - `<time.h>`: Seeding the random number generator with system time  

## **Acknowledgments**  
Special thanks to my team members for their collaboration and to our advisor Mr. Sahabzada Betab Badar for his guidance throughout the project.  

## **License**  
This project is licensed under the MIT License.  
