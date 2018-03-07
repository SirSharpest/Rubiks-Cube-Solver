# Rubiks-Cube-Solver

![Rubiks Cube](https://www.rubiks.com/images/carousel/solve-it-rubiks-cube.png)

## Project currently in need of a representation refactor!
In order to make this behave more like an actual cube the faces and cubids structure will
require an overhaul. That is to say rather than having a [6][3][3] stucture of individual blocks, the program will
require a broken down structure such as:
- 6 unchanging center pieces
- 12 edge pieces each with 2 colors (4 per face with each being shared with one other face 2x6)
- 8 corner pieces each with 3 colors ( 4 per face with each being shared with 3 others 4x6 - 4x4)

## What is this?
- A C++ program to solve a rubiks cube
- Written to teach myself OpenCV (the solver takes a Rubiks cube face image to start off) 

## Can anyone use it?
- Yes, but it's not finished yet

### When will it be finished? 
- When I have a lot of time i.e. over mid-term break

## Can anyone steal this? 
- Yes, there will be a license on this once I find my MIT generator.

## How am I solving the cube?
- The current plan is to implement the 7 stage beginner method with a few heuristics to guide this process
    - I'll be adding a few algorithms to transplant sections of the cube without distubing others e.g. the "-r -d r d u" method

## Can I actually do a rubiks cube? 
- Yes, I can now. Glad I could update this part

