# Rubik's Cube via visualization using `OpenGL` and `GLUT`
### Language: `C++`
### OS: `macOS`

- Requires frameworks `OpenGL` and `GLUT` (recommend to use XCode or AppCode with included frameworks)
- Average amount of rotates for cube solving is 150-200

 <p align="center"> 
    <img src="https://user-images.githubusercontent.com/82240296/116869576-a823a400-ac19-11eb-8dc7-48700852ba16.gif"> </p>
    
### Some info about code:
     
   1) To  **edit rotation speed** you need to change ROTATE_SPEED_STEP in `visualSettings.h` from 15 by a number, which is correct for (ROTATE_SPEED_STEP*`x` + ROTATE_START_VALUE) % 90 == 0, where `x` - is a natural number 
   2) You need to write the unfolding of the cube in input.txt **in the strict order of planes: Up -> Left -> Front -> Right -> Back -> Bottom**
   3) If you want to **put words "orange", "white" etc. instead of "O", "W" etc. in input**, you need to change `maxWordSize` in `additional.h` from 1 to 6 and uncomment respectively code string in `PrintRubikCube()` (it's marked)

<p align="center"> 
    <img width="445" alt="unfolding" src="https://user-images.githubusercontent.com/82240296/116950646-5406d700-ac8e-11eb-8cca-2e2bffcfc243.png"> </p>
<p align="center"> 
   <img width="690" alt="Large unfolding" src="https://user-images.githubusercontent.com/82240296/116952274-edd08300-ac92-11eb-9739-22679e064221.png"> </p>
    
   4) Function `CheckIfCubeCorrect()` evaluating the correctly of centers and if they are wrong, it throws an exception once you'll click `Find Solution`
   5) You can **rotate planes in a window using keys** 1, 2, 3, 4, 5, 6 for Up, Left, Front, Right, Back, Bottom plane respectively
   6) Using keys up_arrow, left_arrow, down_arrow, right_arrow **rotates cube by X and Y coordinates**
   7) "Solve cube using only right (left) and up rotates" works **only with a solved cube**
   8) `cout <<" \ b ";` in code cleans up 1 symbol from the console - if you'll try to refactor smth, you need to know it
   9) If you want **code to show you solving time**, you need to uncomment `// Timer SolvingTime;`, but be careful: **it could crash all code if nothing used before "Cube-solver-MachineGun"**

#### An example of output for solving 10 millions cubes
 <p align="center"> 
    <img src="https://user-images.githubusercontent.com/82240296/116948826-2ec39a00-ac89-11eb-8d65-6a911b2cb301.gif"> </p>

  10) You can read one cube's unfolding from input **once**, at the second time it'll read the next symbols from the file (nothing)
  11) If the **cube's unfolding is incorrect** and you'll try to find a solution, the cube will start to rotate it planes, but after a huge amount of useless tryings of solving it'll write that cube is incorrect (no other way to prove that cube can't be solved)
