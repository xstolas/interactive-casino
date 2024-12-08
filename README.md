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
