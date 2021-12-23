import random

user_wins = 0
computer_wins = 0
draws = 0

options = ["rock", "paper", "scissors"]

def win_condition():
    print("\nYou win! :D")
    global user_wins
    user_wins += 1

while True:
    user_input = input("\nEnter Rock/Paper/Scissors or Q to quit: ").lower()
    if user_input == "q":
        break

    if user_input not in options:
        print("Sorry, that's not valid")
        continue
    
    random_number = random.randint(0, 2)
    # rock: 0, paper: 1, scissors: 2
    computer_choice = options[random_number]
    print("Computer picked", computer_choice + ".")

    #winning conditions
    if user_input == "rock" and computer_choice == "scissors":
        win_condition()
    
    elif user_input == "paper" and computer_choice == "rock":
        win_condition()

    elif user_input == "scissors" and computer_choice == "paper":
        win_condition()

    elif user_input == computer_choice:
        print("Draw!")
        draws += 1
        
    else:
        print("\nYou lost! :(")
        computer_wins += 1

    print("\nYou won", user_wins, "times.")
    print("The computer won", computer_wins, "times.")
    print("You and the computer drew", draws, "times.")

print("\nProgram done, Goodbye!\n")