# Snake Game and AI

This is a small project with the goal of improving my c++ skills and learn about creating AI.  
First I'm implementing an fully functional snake game then I will work on an AI which finishes
the game with a few turns as possible. 



* Main Tasks:
    - Implement a fully functional snake game.
    - Construct an AI
    - Analyze the results of the AI (ie optimal or not?)



* ToDo:
  - Look over functions
        - DONE
  - Rewrite newApple() -> randomCoord()
        - DONE
  - Make a small flowchart
        - DONE


* Flow chart:
    - Call constructor
    -  Main loop
       1. Get user input
       2. Check nextStep
            * If apple is taken:
              - Add one to snake
              - Generate new apple
       3. updateSnake
       4. updateMap
       5. paint
       6. sleep 0.2 sec


   
* Functions:
  - paint() 
    - Paints the map to stdout
  - moveSnake()
    - Updates snake position after a turn is completed.
  - nextStep()
    - Logic for next step (Collision, apple, add length to snake)
  - updateBoard()
    - Update board with new snake Position and apple.
  - getRandomCoord()
    - returns a pair which is randomly selected within the board.
  - setNewApple()
    - Sets apple to a position which is not equal to the snake.
