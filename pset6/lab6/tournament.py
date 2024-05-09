# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            name = row['team']
            score = int(row['rating'])
            dict_1 = {"team": name, "rating": score}
            teams.append(dict_1)
    print()
    counts = {}

    # TODO: Simulate N tournaments and keep track of win counts
    for i in range(N):
        Winner = simulate_tournament(teams)
        if Winner in counts:
            counts[Winner] = counts[Winner] + 1
        else:
            counts[Winner] = 1
    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])
    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    i = len(teams)
    z = 0
    while(i != 1):
        i = i/2
        z = z + 1
    for u in range(z):
        winner = simulate_round(teams)
        teams = winner
    Name = (winner[0])['team']
    return Name


if __name__ == "__main__":
    main()
