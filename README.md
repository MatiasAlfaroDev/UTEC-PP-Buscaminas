<p>
<img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" width="52"/>
<img src="https://img.shields.io/badge/GIT-E44C30?style=for-the-badge&logo=git&logoColor=white"width="50"/>
<img src="https://img.shields.io/badge/license-MIT-green"/>
</p>


<p align="center">
<img src="https://github.com/MatiasAlfaroDev/UTEC-PP-Buscamin/assets/101219427/22fec946-9d65-49d2-bc8d-65395063ad9e"/>

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
<h2></h2>

### How the game works
<p>
Each cell on the board will be identified by its row and column number (ranging from 0 to 7). <em>Initially, the board will show all unexplored squares. Once you start playing, the board will start to change. After the first move if there are adjacent mines, it will show the number of mines it has surrounding it.</em>

 ### Difficulty
<p>
<img src="https://github.com/MatiasAlfaroDev/UTEC-PP-Buscamin/assets/101219427/d5f4cfbf-5f0c-43a8-bd33-d384b8e68325"/>
  
  * The maximum amount of flags placed at once is relative to the number of mines.
  * Game will start with the board size that you select from the difficulty.
  * Every mine will be scattered throughout the board.
</p>


<h2></h2>

### Basic aspects of Playing 
<img src="https://github.com/MatiasAlfaroDev/UTEC-PP-Buscamin/assets/101219427/5ef80fd2-012b-4cbf-8436-4ba21d8040de"/>

<p>
  

The player has 2 possible moves each turn:

  * <b>E</b> - Cascade reveal of what was in a previously unexplored set of cells. If the cell did not have any adjacent mines<br> <em>it will expand the       exploration to its neighboring cells until there are cells with adjacent mines.</em>

  * <b>F</b> - Flags a previously unexplored cell as suspicious, if the cell had been already flagged it will remove the flag.<em>In order
to win you'll have to Flag every mine</em>

To indicate their move, the player must enter the correspondant letter (M or E), followed by a space and then the coordinates of the row and column, respectively.<em>We're working on enhance this by listening to the clicks of the mouse, so you can right click where you wanna explore and left click where you want to Flag.</em>

</p>

<h2> </h2>

### The Rules 
<p>
<img src="https://github.com/MatiasAlfaroDev/UTEC-PP-Buscamin/assets/101219427/c1db6dbe-acd4-4e54-8972-320e9d385091"/>
  
  * User will be prompted as shown in the previous image, they should agree in order to start playing.
  * <em>With new feautes, new Ruels will come.</em>
</p>
