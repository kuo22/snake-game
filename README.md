# Snake
Snake game made in C++ and SDL2

The program includes some basic functionalities including main menu and ability to pause the game.  The game itself wasn't difficult to make, but managing various states (menu/pause) was a bit challenging and required online research.

## Implementing State Management

The game uses a `StageManager` class that handles state transitions based on certain events (key presses).  Each state is represented by its own class, such as `PlayState` and `PauseState`, which inherits from a base class called `GameState`.  By doing so, the state manager simply needs to call the essential methods of `handleEvents`, `update`, and `render` from the base class rather than from all the individual states.

The states are then stored as a stack in the state manager.  State transitions are then handled through the `changeState`, `pushState` and `popState`.  

`changeState` is used when the current state is no longer needed and can be safely destroyed.  This would apply to states that are usually only visited once such as the introduction sequence or main menu.

`pushState` is used to pause the current state and transition to another state temporarily.  This would apply to states such as a pause where the player is still plannnig on resuming the game later on.

`popState` is used in conjunction with `pushState`, which destroys the current state to return to the previous state.  An example would be unpausing the game.

## Implementing Snake

A queue is used for storing the body of the snake, where each element is the coordinate of that segment of the body.  At each step, a coordinate is popped and removed (the tail), and another one pushed back in.

The food is spawned using a random generator, and uses a while loop to make sure that the spawn coordinate is not part of the snake body.  This could probably be optimized to be more efficient while maintaining the random aspect.