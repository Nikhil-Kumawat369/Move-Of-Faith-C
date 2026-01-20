# 🎮 MOVE OF FATE — The Deadly Arena (C Game)

MOVE OF FATE is a two-player, turn-based terminal game written in C, where every step forward is a gamble. Players enter a deadly 4×4 arena filled with hidden TNT, earning increasing rewards for each safe move — but one wrong step can end everything.

>🩸 Greed brings glory. One mistake brings ruin.

## 🧠 Game Concept

Two players take turns stepping into a 16-tile arena.
Some tiles are safe. Others hide deadly TNT.

- Each safe move increases your score

- Each next move is worth more points

- You can cash out anytime

- Step on TNT, and:

  - The game ends immediately

  - 35% of your total score is deducted

  - The arena reveals probability echoes (not exact bomb locations)

After both players finish, scores are compared and a winner is declared.

## ✨ Features

- 🎯 Two-Player Competitive Gameplay

- 💣 Hidden TNT System (randomized every turn)

- 📈 Increasing Risk–Reward Scoring

- 🧠 Strategic Cash-Out Mechanic

- 🎲 Multiple Difficulty Levels (1–15 TNT)

- 🖥️ ASCII-Rendered 4×4 Arena

- 🎭 Immersive Narrative & Thematic Messages

- 🔀 Fisher–Yates Shuffle for Fair Randomization

## 🕹️ How the Game Works

### Arena

- A 4×4 grid (16 tiles)

- Tiles are numbered 1–16

- Once stepped on, a tile becomes unavailable

### Levels

Before the game starts, players choose a level (1–15):

- Level number = number of TNT tiles

- Higher levels = higher risk

### Scoring System

>Each safe move gives increasing points:

| Move Number | Points Earned |
| :---------: | :-----------: |
| 1 | 100 |
| 2 | 200 |
| 3 | 300 |
| ... | ... |
| 15 | 1500 |

### Risk Choice (After Every Safe Move)

- C → Continue playing (higher reward, higher risk)

- X → Cash out and secure your score

### TNT Penalty

If a player steps on TNT:

- Game ends instantly

- 35% of total score is deducted

- Final score is locked

## 🏆 Winning Conditions

- Both players complete their turns

- Scores are compared

- Player with the higher score wins

- Equal scores result in a draw

## 🛠️ Tech Stack

- Language: C

- Compiler: GCC / Clang

- Libraries Used:
```C
<stdio.h>
```

```C
<stdlib.h>
```

```C
<math.h>
```

```C
<time.h>
```

## 📂 Project Structure

```C
MOVE_OF_FATE/
│
├── main.c          # Complete game logic
└── README.md       # Project documentation
```

## 🚀 How to Compile & Run

### Compile

```C
gcc main.c -o move_of_fate -lm
```

### Run

```C
./move_of_fate
```

>⚠️ Make sure you compile with -lm because the game uses math.h.

## 📌 Gameplay Notes

- TNT locations are never revealed exactly

- Displayed -1 tiles represent probability echoes, not certainty

- Each player gets a freshly randomized arena

- Invalid inputs terminate the game for integrity

## 🧪 Randomization & Fairness

- TNT positions are randomized using the Fisher–Yates shuffle

- srand(time(0)) ensures a new arena every run

- Each player faces a separate random arena

## 📜 License

>This project is open for learning and experimentation.
>You may modify, distribute, or expand it freely.

## 👤 Author

Developed by: Nikhil Kumawat
<br>
Language: C
<br>
Project: Move Of Faith

>“The Deadly Arena never tells the truth.”