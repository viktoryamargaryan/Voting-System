#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define CANDIDATE_COUNT 4

typedef struct {
    const char *name;
    int votesCount;
} Candidate;

Candidate candidates[CANDIDATE_COUNT] = {
    {"John Doe", 0},
    {"Jane Brown", 0},
    {"Mary Johnson", 0},
    {"Bob Smith", 0}
};

int spoiledVotes = 0;

/**
 * @brief Checks if the given choice is valid.
 *
 * @param choice The user's selected choice.
 * @return Returns true if the choice is valid, otherwise false.
 */
bool isValidChoice(int choice) {
    return choice >= 1 && choice <= CANDIDATE_COUNT + 1;
}

/**
 * @brief Displays the list of candidates for voting.
 */
void displayCandidates() {
    printf("\n### Please choose your Candidate ###\n");
    for (int i = 0; i < CANDIDATE_COUNT; ++i) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    printf("%d. %s\n", CANDIDATE_COUNT + 1, "None of These");
}

/**
 * @brief Allows a user to cast a vote after verifying their age.
 */
void castVote() {
     int age;
    printf("\nEnter your age: ");
    scanf("%d", &age);

    if (age >= 18) {
        int choice, confirmVote;
        do {
            displayCandidates();

            printf("\nInput your choice (1 - %d) : ", CANDIDATE_COUNT + 1);
            scanf("%d", &choice);

            if (!isValidChoice(choice)) {
                printf("Invalid choice. Please choose between 1 to %d\n", CANDIDATE_COUNT + 1);
            }
        } while (!isValidChoice(choice));

        printf("\nYou've chosen: ");
        if (choice == CANDIDATE_COUNT + 1) {
            printf("None of These");
        } else {
            printf("%s", candidates[choice - 1].name);
        }

        do {
            printf("\nAre you sure you want to cast this vote? (1 for Yes / 0 for No): ");
            scanf("%d", &confirmVote);

            if (confirmVote != 0 && confirmVote != 1) {
                printf("Please enter either 1 for Yes or 0 for No.\n");
            }
        } while (confirmVote != 0 && confirmVote != 1);

        if (confirmVote == 1) {
            if (choice == CANDIDATE_COUNT + 1) {
                spoiledVotes++;
            } else {
                candidates[choice - 1].votesCount++;
            }
            printf("\nThanks for voting!!");
        } else {
            printf("\nVote Cancelled.");
        }
    } else {
        printf("\nSorry, you are not eligible to vote. Minimum age requirement is 18.\n");
    }
}

/**
 * @brief Displays the voting statistics.
 */
void displayVoteCount() {
    printf("\n### Voting Statistics ###\n");
    for (int i = 0; i < CANDIDATE_COUNT; ++i) {
        printf("%s - %d\n", candidates[i].name, candidates[i].votesCount);
    }
    printf("Spoiled Votes - %d\n", spoiledVotes);
}

/**
 * @brief Determines the leading candidate(s) based on the vote count.
 */
void getLeadingCandidate() {
   printf("\n### Leading Candidates ###\n");
    int maxVotes = candidates[0].votesCount;

    for (int i = 1; i < CANDIDATE_COUNT; ++i) {
        if (candidates[i].votesCount > maxVotes) {
            maxVotes = candidates[i].votesCount;
        }
    }

    printf("Leading candidate(s): ");
    for (int i = 0; i < CANDIDATE_COUNT; ++i) {
        if (candidates[i].votesCount == maxVotes) {
            printf("[%s] ", candidates[i].name);
        }
    }

    if (maxVotes == 0 || (candidates[0].votesCount == candidates[1].votesCount &&
                           candidates[1].votesCount == candidates[2].votesCount &&
                           candidates[2].votesCount == candidates[3].votesCount)) {
        printf("\nWarning: No clear winner.\n");
    }
}

/**
 * @brief Displays the promises made by each candidate.
 */
void displayCandidatePromises() {
     printf("\n### Candidate Promises ###\n");
    printf("1. %s: Promises to focus on healthcare and education reform.\n", candidates[0].name);
    printf("2. %s: Vows to strengthen the economy and create job opportunities.\n", candidates[1].name);
    printf("3. %s: Commits to environmental protection and sustainable policies.\n", candidates[2].name);
    printf("4. %s: Pledges to address national security and immigration reforms.\n", candidates[3].name);
}

/**
 * @brief Resets all votes to zero (Admin Only).
 *
 * @param adminPassword The admin password required to reset votes.
 */
void resetVotes(int adminPassword) {
    int passwordAttempts = 0;
    int password;
    
    printf("\nEnter Admin Password (four digits): ");
    
    while (passwordAttempts < 3) {
        scanf("%d", &password);
        
        if (password == adminPassword) {
            for (int i = 0; i < CANDIDATE_COUNT; ++i) {
                candidates[i].votesCount = 0;
            }
            spoiledVotes = 0;
            printf("\n### All votes have been reset. ###\n");
            break;
        } else {
            printf("Incorrect Password. Please try again. Attempts left: %d\n", 2 - passwordAttempts);
            passwordAttempts++;
            if (passwordAttempts == 3) {
                printf("Too many incorrect attempts. Try again later.\n");
                break;
            }
            printf("\nEnter Admin Password (four digits): ");
        }
    }
}


/**
 * @brief Displays additional information about the election.
 */
void displayAdditionalInfo() {
    printf("\n### Additional Information ###\n");
    printf("We value your participation in this election. Every vote counts!\n");
}

/**
 * @brief The main function to manage the voting system.
 */
int main() {
    int adminPassword = 4512;
    int choice;

    printf("\n### Welcome to Election/Voting 2023 ###\n");

    do {
        printf("\n1. Cast the vote");
        printf("\n2. Find Vote Count");
        printf("\n3. Find leading Candidate");
        printf("\n4. Display Candidate Promises");
        printf("\n5. Reset All Votes (Admin Only)");
        printf("\n0. Exit");
        printf("\nPlease enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                castVote();
                break;
            case 2:
                displayVoteCount();
                break;
            case 3:
                getLeadingCandidate();
                break;
            case 4:
                displayCandidatePromises();
                break;
            case 5:
                resetVotes(adminPassword);
                break;
            case 0:
                printf("\nThanks for voting. See you next time!!");
                break;
            default:
                printf("\nError: Invalid Choice\n");
        }
    } while (choice != 0);

    return 0;
}
