
# Planet Buster

**Planet Buster** is a 2D game where the player navigates a spaceship to interact with planets, earning points, avoiding damage, and surviving as long as possible. The game is built using **SFML** (Simple and Fast Multimedia Library) and features a start menu, dynamic gameplay, and a game-over screen.

---

## Features
- **Start Menu**:
  - **Start Game**: Launches the gameplay.
  - **Quit**: Exits the application.
- **Gameplay**:
  - Collect planets for points and health boosts.
  - Avoid damaging planets to maintain health.
  - Spawning and interaction mechanics.
- **Game Over Screen**:
  - Displays when the player runs out of health, marking the end of the game.
- **Real-time UI**:
  - Displays health and points dynamically during gameplay.

---

## Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/<your-username>/Planet-Buster.git
   cd Planet-Buster
   ```
2. Ensure you have the following:
   - **SFML 2.6.1** or later.
   - A C++ compiler (e.g., GCC, MSVC).
   - A development environment supporting C++ (e.g., Visual Studio or VS Code).

3. Set up SFML:
   - Include the SFML headers and libraries in your project.
   - Configure your IDE/compiler to link against SFML.

4. Build the project:
   - Compile the source files, ensuring SFML dependencies are linked.

---

## Usage
1. Run the compiled executable.
2. Select **Start Game** to begin.
3. Navigate the spaceship using the WASD keys.
4. Collect healing planets, avoid damaging ones, and try to score as many points as possible.
5. When health reaches zero, the **Game Over** screen will display.

---

## File Structure
```
Planet-Buster/
├── src/
│   ├── Game.cpp       # Main game logic
│   ├── Player.cpp     # Player-related logic
│   ├── Planets.cpp    # Planet mechanics
│   └── main.cpp       # Entry point
├── include/
│   ├── Game.h         # Game class header
│   ├── Player.h       # Player class header
│   ├── Planets.h      # Planets class header
├── assets/
│   ├── fonts/         # Font files for UI
│   ├── images/        # Icon and other image assets
└── README.md          # Project documentation
```
