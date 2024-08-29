# Snake Game with Different Levels (Console-based)

This is a console-based Snake Game built in C++ using Visual Studio Community Edition. The game features multiple levels, different versions of the classic Snake game, player modes, and a scoring system, making it both easy and challenging.

## Table of Contents

- [Features](#features)
- [Game Versions](#game-versions)
- [How to Play](#how-to-play)
- [Scoring System](#scoring-system)
- [Requirements](#requirements)
- [Installation](#installation)

## Features

- **Multiple Levels:** The game offers three distinct levels with varying difficulties.
- **Single and Multiplayer Modes:** Players can select either single-player or multiplayer mode(upto 4 Players).
- **Classic and Modern Versions:** The game includes the classic Snake game with no boundaries and two additional levels with boundaries for more challenging gameplay.
- **Scoring System:** The game tracks the player's score based on the amount of food eaten by snake (one score will be added in particular snake total score).

## Game Versions

1. **Classic Nokia Snake:** 
   - This version replicates the original Snake game from old Nokia phones.
   - No boundaries: The snake can move through the edges of the screen and reappear on the opposite side.

2. **Level with Boundaries:**
   - Introduces boundaries around the game area.
   - The snake dies if it collides with the boundary walls.

3. **Advanced Level with Boundaries:**
   - A more challenging version of the boundary-based level with additional obstacles.
   - Requires precise control and strategy to avoid collision with the walls.

## How to Play

1. **Select Mode:**
   - Choose either single-player or multiplayer mode(upto 4).
   
2. **Select Level:**
   - Choose from the three available game versions:
     - Classic Nokia Snake (No boundaries).
     - Snake game with boundaries.
     - Advanced snake game with more challenging boundaries.

3. **Gameplay Controls:**
   - **Arrow keys:** Control the movement of the snake (up, down, left, right).
   - **Goal:** Eat the food to grow longer while avoiding collisions with boundaries, if playing a level with them.
   
4. **Multiplayer Mode:**
   - Two players control separate snakes using different sets of keys.
   - The game continues until all of the players loses (by colliding with the boundaries).

## Scoring System

- Points are awarded for each piece of food the snake eats.
- The score increases as the snake grows longer.
- In multiplayer mode, all players have individual scores.
- The scores are showing side by side while playing game.

## Requirements

- Visual Studio Community Edition (or any C++ IDE).
- C++ compiler.
- Basic understanding of C++.
- Please Make some settings with your console window to enjoy it properly.
- In your console window **right click on top left corner**.
- In settings change your font to **Raster font** and change dimension to **80-by-80** to see and enjoy the game properly.

## Installation

1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/MuhammdRehman/Snake-game-Having-Diffrent-Levels-Console-base.git
