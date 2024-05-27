

</p>

<p align="center">
 <img src="https://github.com/MatiasAlfaroDev/UTEC-PP-Buscamin/assets/101219427/9e77c53a-caab-4588-8439-05c6c083f17d" />
</p>



<h1> <img src="https://red.utec.edu.uy/wp-content/uploads/2018/11/09-Isotipo-1.png" width="25"/> UTEC - PP - <b>Minesweeper</b></h1>

<p>The game consists of exploring a board where hidden mines are present. The player must fully explore this board by
<b>marking all the hidden mines</b> in order to win. The player will lose the game if they detonate a mine at any time.
<em>The player's score will be determined based on the time it takes to mark all the hidden mines.</em></p>

<h2> </h2>

### Compile & Play
Use Latest G++ version, choose an easy directory for <em>git clone</em>.
```
cd <directory>
git clone https://github.com/MatiasAlfaroDev/UTEC-PP-Buscaminas.git
g++ -o minesweeper.exe main.cpp
./minesweeper.exe
```
<hr>

### How the game works
<p>
Each cell on the board will be identified by its row and column number (ranging from 0 to 7). <em>Initially, the board will show all unexplored squares. Once you start playing, the board will start to change. After the first move if there are adjacent mines, it will show the number of mines it has surrounding it.</em>
 
 ### Difficulty
 * #### Beginner <em>(this is the way thats intendend in the lab)</em>
      * The game starts with an <b>8 x 8 board</b>.
      * There will be <b>16 mines</b> scattered throughout the board.
      * The maximum amount of flags placed at once is <b>16</b>
<h2></h2>

 * #### Intermediate
      * The game starts with an <b>16 x 16 board</b>.
      * There will be <b>40 mines</b> scattered throughout the board.
      * The maximum amount of flags placed at once is <b>40</b>
<h2></h2>

 * #### Advanced
      * The game starts with an <b>16 x 30 board</b>.
      * There will be <b>99 mines</b> scattered throughout the board.
      * The maximum amount of flags placed at once is <b>99</b>
</p>
<hr>


### Basic aspects of Playing 
<p>
  
The player has 2 possible moves each turn:

  * <b>OPTION [E]</b> Cascade reveal of what was in a previously unexplored set of cells. If the cell did not have any adjacent mines, <em>it will expand the       exploration to its neighboring cells until there are cells with adjacent mines.</em>

  * <b>OPTION [F]</b> Flags a previously unexplored cell as suspicious, if the cell had been already flagged it will remove the flag mark from that square. <em>In order
to win you'll have to Flag every mine</em>

To indicate their move, the player must enter the correspondant letter (M or E), followed by a space and then the coordinates of the row and column, respectively.<em>We're working on enhance this by listening to the clicks of the mouse, so you can right click where you wanna explore and left click where you want to Flag.</em>

</p>

<h2> </h2>

### The Rules 

* Only up to <b>16 cells</b> can be marked.
* The player wins when they have revealed <b>48 cells.</b>
<em>Besides revealing all the board, it's a must that every mine needs to be <b>Flagged</b></em>

### Invalid moves:
* Exploring a cell that is <b>Flagged</b>.
* <b>Flagging</b> or <b>Exploring</b> a cell that has already been explored.
* <b>Marking</b> or <b>Exploring</b> in nonexistent squares.<em>Outside the board</em>
* Using an incorrect move format.
<img alt="C++" src="https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white" width="60">
<img alt="Git" src="https://img.shields.io/badge/git-%23F05033.svg?style=for-the-badge&logo=git&logoColor=white" width="60">
