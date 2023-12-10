# Voting-System

This C program simulates an election/voting system where users can cast votes for candidates or choose to reset all votes (admin only).

## Features

- **Cast the Vote:**
  - Users can cast votes for their preferred candidate or choose "None of These."

- **Find Vote Count:**
  - Display the total votes received by each candidate and the number of spoiled votes.

- **Find Leading Candidate:**
  - Identify the leading candidate(s) based on the vote count.

- **Display Candidate Promises:**
  - View the promises made by each candidate.

- **Reset All Votes (Admin Only):**
  - Admins can reset all votes to zero using a four-digit password.

- **Exit:**
  - Exit the program.

## How to Compile and Run

1. Open a terminal window.
2. Navigate to the project directory.

```bash
gcc -o ElectionSystem main.c
./ElectionSystem
```

## Voting Process

1. Users can cast votes after verifying their age (minimum age requirement is 18).
2. Users select their preferred candidate or choose "None of These."
3. Users confirm their vote choice.
4. Votes are recorded, and users receive a confirmation message.

## Admin Access

- Admin Password: 4512

## Election Statistics

- Spoiled Votes: Indicates the number of votes marked as "None of These."
- Leading Candidates: Displays the candidate(s) with the highest vote count.

## Additional Information

We appreciate your participation in this election. Every vote counts!

## Author

Viktorya Margaryan
